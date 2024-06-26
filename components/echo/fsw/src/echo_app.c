/*******************************************************************************
** File: echo_app.c
**
** Purpose:
**   This file contains the source code for the ECHO application.
**
*******************************************************************************/

/*
** Include Files
*/
#include <arpa/inet.h>
#include "echo_app.h"


/*
** Global Data
*/
ECHO_AppData_t ECHO_AppData;

/*
** Application entry point and main process loop
*/
void ECHO_AppMain(void)
{
    int32 status = OS_SUCCESS;

    /*
    ** Create the first Performance Log entry
    */
    CFE_ES_PerfLogEntry(ECHO_PERF_ID);

    /* 
    ** Perform application initialization
    */
    status = ECHO_AppInit();
    if (status != CFE_SUCCESS)
    {
        ECHO_AppData.RunStatus = CFE_ES_RunStatus_APP_ERROR;
    }

    /*
    ** Main loop
    */
    while (CFE_ES_RunLoop(&ECHO_AppData.RunStatus) == true)
    {
        /*
        ** Performance log exit stamp
        */
        CFE_ES_PerfLogExit(ECHO_PERF_ID);

        /* 
        ** Pend on the arrival of the next Software Bus message
        ** Note that this is the standard, but timeouts are available
        */
        status = CFE_SB_ReceiveBuffer((CFE_SB_Buffer_t **)&ECHO_AppData.MsgPtr,  ECHO_AppData.CmdPipe,  CFE_SB_PEND_FOREVER);
        
        /* 
        ** Begin performance metrics on anything after this line. This will help to determine
        ** where we are spending most of the time during this app execution.
        */
        CFE_ES_PerfLogEntry(ECHO_PERF_ID);

        /*
        ** If the CFE_SB_ReceiveBuffer was successful, then continue to process the command packet
        ** If not, then exit the application in error.
        ** Note that a SB read error should not always result in an app quitting.
        */
        if (status == CFE_SUCCESS)
        {
            ECHO_ProcessCommandPacket();
        }
        else
        {
            CFE_EVS_SendEvent(ECHO_PIPE_ERR_EID, CFE_EVS_EventType_ERROR, "ECHO: SB Pipe Read Error = %d", (int) status);
            ECHO_AppData.RunStatus = CFE_ES_RunStatus_APP_ERROR;
        }
    }

    /*
    ** Disable component, which cleans up the interface, upon exit
    */
    ECHO_Disable();

    /*
    ** Performance log exit stamp
    */
    CFE_ES_PerfLogExit(ECHO_PERF_ID);

    /*
    ** Exit the application
    */
    CFE_ES_ExitApp(ECHO_AppData.RunStatus);
} 


/* 
** Initialize application
*/
int32 ECHO_AppInit(void)
{
    int32 status = OS_SUCCESS;
    
    ECHO_AppData.RunStatus = CFE_ES_RunStatus_APP_RUN;

    /*
    ** Register the events
    */ 
    status = CFE_EVS_Register(NULL, 0, CFE_EVS_EventFilter_BINARY);    /* as default, no filters are used */
    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("ECHO: Error registering for event services: 0x%08X\n", (unsigned int) status);
       return status;
    }

    /*
    ** Create the Software Bus command pipe 
    */
    status = CFE_SB_CreatePipe(&ECHO_AppData.CmdPipe, ECHO_PIPE_DEPTH, "ECHO_CMD_PIPE");
    if (status != CFE_SUCCESS)
    {
        CFE_EVS_SendEvent(ECHO_PIPE_ERR_EID, CFE_EVS_EventType_ERROR,
            "Error Creating SB Pipe,RC=0x%08X",(unsigned int) status);
       return status;
    }
    
    /*
    ** Subscribe to ground commands
    */
    status = CFE_SB_Subscribe(CFE_SB_ValueToMsgId(ECHO_CMD_MID), ECHO_AppData.CmdPipe);
    if (status != CFE_SUCCESS)
    {
        CFE_EVS_SendEvent(ECHO_SUB_CMD_ERR_EID, CFE_EVS_EventType_ERROR,
            "Error Subscribing to HK Gnd Cmds, MID=0x%04X, RC=0x%08X",
            ECHO_CMD_MID, (unsigned int) status);
        return status;
    }

    /*
    ** Subscribe to housekeeping (hk) message requests
    */
    status = CFE_SB_Subscribe(CFE_SB_ValueToMsgId(ECHO_REQ_HK_MID), ECHO_AppData.CmdPipe);
    if (status != CFE_SUCCESS)
    {
        CFE_EVS_SendEvent(ECHO_SUB_REQ_HK_ERR_EID, CFE_EVS_EventType_ERROR,
            "Error Subscribing to HK Request, MID=0x%04X, RC=0x%08X",
            ECHO_REQ_HK_MID, (unsigned int) status);
        return status;
    }

    /*
    ** TODO: Subscribe to any other messages here
    */


    /* 
    ** Initialize the published HK message - this HK message will contain the 
    ** telemetry that has been defined in the ECHO_HkTelemetryPkt for this app.
    */
    CFE_MSG_Init(CFE_MSG_PTR(ECHO_AppData.HkTelemetryPkt.TlmHeader),
                   CFE_SB_ValueToMsgId(ECHO_HK_TLM_MID),
                   ECHO_HK_TLM_LNGTH);

    /*
    ** Initialize the device packet message
    ** This packet is specific to your application
    */
    CFE_MSG_Init(CFE_MSG_PTR(ECHO_AppData.DevicePkt.TlmHeader),
                   CFE_SB_ValueToMsgId(ECHO_DEVICE_TLM_MID),
                   ECHO_DEVICE_TLM_LNGTH);

    /*
    ** TODO: Initialize any other messages that this app will publish
    */


    /* 
    ** Always reset all counters during application initialization 
    */
    ECHO_ResetCounters();

    /*
    ** Initialize application data
    ** Note that counters are excluded as they were reset in the previous code block
    */
    ECHO_AppData.HkTelemetryPkt.DeviceEnabled = ECHO_DEVICE_DISABLED;
    ECHO_AppData.HkTelemetryPkt.DeviceHK.DeviceCounter = 0;
    ECHO_AppData.HkTelemetryPkt.DeviceHK.DeviceConfig = 0;
    ECHO_AppData.HkTelemetryPkt.DeviceHK.DeviceStatus = 0;

    /* 
     ** Send an information event that the app has initialized. 
     ** This is useful for debugging the loading of individual applications.
     */
    status = CFE_EVS_SendEvent(ECHO_STARTUP_INF_EID, CFE_EVS_EventType_INFORMATION,
               "ECHO App Initialized. Version %d.%d.%d.%d",
                ECHO_MAJOR_VERSION,
                ECHO_MINOR_VERSION, 
                ECHO_REVISION, 
                ECHO_MISSION_REV);	
    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("ECHO: Error sending initialization event: 0x%08X\n", (unsigned int) status);
    }
    return status;
} 


/* 
** Process packets received on the ECHO command pipe
*/
void ECHO_ProcessCommandPacket(void)
{
    CFE_SB_MsgId_t MsgId = CFE_SB_INVALID_MSG_ID;
    CFE_MSG_GetMsgId(ECHO_AppData.MsgPtr, &MsgId);
    switch (CFE_SB_MsgIdToValue(MsgId))
    {
        /*
        ** Ground Commands with command codes fall under the ECHO_CMD_MID (Message ID)
        */
        case ECHO_CMD_MID:
            ECHO_ProcessGroundCommand();
            break;

        /*
        ** All other messages, other than ground commands, add to this case statement.
        */
        case ECHO_REQ_HK_MID:
            ECHO_ProcessTelemetryRequest();
            break;

        /*
        ** All other invalid messages that this app doesn't recognize, 
        ** increment the command error counter and log as an error event.  
        */
        default:
            ECHO_AppData.HkTelemetryPkt.CommandErrorCount++;
            CFE_EVS_SendEvent(ECHO_PROCESS_CMD_ERR_EID,CFE_EVS_EventType_ERROR, "ECHO: Invalid command packet, MID = 0x%x", CFE_SB_MsgIdToValue(MsgId));
            break;
    }
    return;
} 


/*
** Process ground commands
** TODO: Add additional commands required by the specific component
*/
void ECHO_ProcessGroundCommand(void)
{
    int32 status = OS_SUCCESS;
    CFE_SB_MsgId_t MsgId = CFE_SB_INVALID_MSG_ID;
    CFE_MSG_FcnCode_t CommandCode = 0;

    /*
    ** MsgId is only needed if the command code is not recognized. See default case
    */
    CFE_MSG_GetMsgId(ECHO_AppData.MsgPtr, &MsgId);

    /*
    ** Ground Commands, by definition, have a command code (_CC) associated with them
    ** Pull this command code from the message and then process
    */
    CFE_MSG_GetFcnCode(ECHO_AppData.MsgPtr, &CommandCode);
    switch (CommandCode)
    {
        /*
        ** NOOP Command
        */
        case ECHO_NOOP_CC:
            /*
            ** First, verify the command length immediately after CC identification 
            ** Note that VerifyCmdLength handles the command and command error counters
            */
            if (ECHO_VerifyCmdLength(ECHO_AppData.MsgPtr, sizeof(ECHO_NoArgs_cmd_t)) == OS_SUCCESS)
            {
                /* Second, send EVS event on successful receipt ground commands*/
                CFE_EVS_SendEvent(ECHO_CMD_NOOP_INF_EID, CFE_EVS_EventType_INFORMATION, "ECHO: NOOP command received");
                /* Third, do the desired command action if applicable, in the case of NOOP it is no operation */
            }
            break;

        /*
        ** Reset Counters Command
        */
        case ECHO_RESET_COUNTERS_CC:
            if (ECHO_VerifyCmdLength(ECHO_AppData.MsgPtr, sizeof(ECHO_NoArgs_cmd_t)) == OS_SUCCESS)
            {
                CFE_EVS_SendEvent(ECHO_CMD_RESET_INF_EID, CFE_EVS_EventType_INFORMATION, "ECHO: RESET counters command received");
                ECHO_ResetCounters();
            }
            break;

        /*
        ** Enable Command
        */
        case ECHO_ENABLE_CC:
            if (ECHO_VerifyCmdLength(ECHO_AppData.MsgPtr, sizeof(ECHO_NoArgs_cmd_t)) == OS_SUCCESS)
            {
                CFE_EVS_SendEvent(ECHO_CMD_ENABLE_INF_EID, CFE_EVS_EventType_INFORMATION, "ECHO: Enable command received");
                ECHO_Enable();
            }
            break;

        /*
        ** Disable Command
        */
        case ECHO_DISABLE_CC:
            if (ECHO_VerifyCmdLength(ECHO_AppData.MsgPtr, sizeof(ECHO_NoArgs_cmd_t)) == OS_SUCCESS)
            {
                CFE_EVS_SendEvent(ECHO_CMD_DISABLE_INF_EID, CFE_EVS_EventType_INFORMATION, "ECHO: Disable command received");
                ECHO_Disable();
            }
            break;

        /*
        ** TODO: Edit and add more command codes as appropriate for the application
        ** Set Configuration Command
        ** Note that this is an example of a command that has additional arguments
        */
        case ECHO_CONFIG_CC:
            if (ECHO_VerifyCmdLength(ECHO_AppData.MsgPtr, sizeof(ECHO_Config_cmd_t)) == OS_SUCCESS)
            {
                uint32_t config = ntohl(((ECHO_Config_cmd_t*) ECHO_AppData.MsgPtr)->DeviceCfg); // command is defined as big-endian... need to convert to host representation
                CFE_EVS_SendEvent(ECHO_CMD_CONFIG_INF_EID, CFE_EVS_EventType_INFORMATION, "ECHO: Configuration command received: %u", config);
                /* Command device to send HK */
                status = ECHO_CommandDevice(&ECHO_AppData.EchoUart, ECHO_DEVICE_CFG_CMD, config);
                if (status == OS_SUCCESS)
                {
                    ECHO_AppData.HkTelemetryPkt.DeviceCount++;
                }
                else
                {
                    ECHO_AppData.HkTelemetryPkt.DeviceErrorCount++;
                }
            }
            break;

        /*
        ** Invalid Command Codes
        */
        default:
            /* Increment the error counter upon receipt of an invalid command */
            ECHO_AppData.HkTelemetryPkt.CommandErrorCount++;
            CFE_EVS_SendEvent(ECHO_CMD_ERR_EID, CFE_EVS_EventType_ERROR, 
                "ECHO: Invalid command code for packet, MID = 0x%x, cmdCode = 0x%x", CFE_SB_MsgIdToValue(MsgId), CommandCode);
            break;
    }
    return;
} 


/*
** Process Telemetry Request - Triggered in response to a telemetery request
** TODO: Add additional telemetry required by the specific component
*/
void ECHO_ProcessTelemetryRequest(void)
{
    CFE_SB_MsgId_t MsgId = CFE_SB_INVALID_MSG_ID;
    CFE_MSG_FcnCode_t CommandCode = 0;

    /* MsgId is only needed if the command code is not recognized. See default case */
    CFE_MSG_GetMsgId(ECHO_AppData.MsgPtr, &MsgId);

    /* Pull this command code from the message and then process */
    CFE_MSG_GetFcnCode(ECHO_AppData.MsgPtr, &CommandCode);
    switch (CommandCode)
    {
        case ECHO_REQ_HK_TLM:
            ECHO_ReportHousekeeping();
            break;

        case ECHO_REQ_DATA_TLM:
            ECHO_ReportDeviceTelemetry();
            break;

        /*
        ** Invalid Command Codes
        */
        default:
            /* Increment the error counter upon receipt of an invalid command */
            ECHO_AppData.HkTelemetryPkt.CommandErrorCount++;
            CFE_EVS_SendEvent(ECHO_DEVICE_TLM_ERR_EID, CFE_EVS_EventType_ERROR, 
                "ECHO: Invalid command code for packet, MID = 0x%x, cmdCode = 0x%x", CFE_SB_MsgIdToValue(MsgId), CommandCode);
            break;
    }
    return;
}


/* 
** Report Application Housekeeping
*/
void ECHO_ReportHousekeeping(void)
{
    int32 status = OS_SUCCESS;

    /* Check that device is enabled */
    if (ECHO_AppData.HkTelemetryPkt.DeviceEnabled == ECHO_DEVICE_ENABLED)
    {
        status = ECHO_RequestHK(&ECHO_AppData.EchoUart, (ECHO_Device_HK_tlm_t*) &ECHO_AppData.HkTelemetryPkt.DeviceHK);
        if (status == OS_SUCCESS)
        {
            ECHO_AppData.HkTelemetryPkt.DeviceCount++;
        }
        else
        {
            ECHO_AppData.HkTelemetryPkt.DeviceErrorCount++;
            CFE_EVS_SendEvent(ECHO_REQ_HK_ERR_EID, CFE_EVS_EventType_ERROR, 
                    "ECHO: Request device HK reported error %d", status);
        }
    }
    /* Intentionally do not report errors if disabled */

    /* Time stamp and publish housekeeping telemetry */
    CFE_SB_TimeStampMsg((CFE_MSG_Message_t *) &ECHO_AppData.HkTelemetryPkt);
    CFE_SB_TransmitMsg((CFE_MSG_Message_t *) &ECHO_AppData.HkTelemetryPkt, true);
    return;
}


/*
** Collect and Report Device Telemetry
*/
void ECHO_ReportDeviceTelemetry(void)
{
    int32 status = OS_SUCCESS;

    /* Check that device is enabled */
    if (ECHO_AppData.HkTelemetryPkt.DeviceEnabled == ECHO_DEVICE_ENABLED)
    {
        status = ECHO_RequestData(&ECHO_AppData.EchoUart, (ECHO_Device_Data_tlm_t*) &ECHO_AppData.DevicePkt.Echo);
        if (status == OS_SUCCESS)
        {
            ECHO_AppData.HkTelemetryPkt.DeviceCount++;
            /* Time stamp and publish data telemetry */
            CFE_SB_TimeStampMsg((CFE_MSG_Message_t *) &ECHO_AppData.DevicePkt);
            CFE_SB_TransmitMsg((CFE_MSG_Message_t *) &ECHO_AppData.DevicePkt, true);
        }
        else
        {
            ECHO_AppData.HkTelemetryPkt.DeviceErrorCount++;
            CFE_EVS_SendEvent(ECHO_REQ_DATA_ERR_EID, CFE_EVS_EventType_ERROR, 
                    "ECHO: Request device data reported error %d", status);
        }
    }
    /* Intentionally do not report errors if disabled */
    return;
}


/*
** Reset all global counter variables
*/
void ECHO_ResetCounters(void)
{
    ECHO_AppData.HkTelemetryPkt.CommandErrorCount = 0;
    ECHO_AppData.HkTelemetryPkt.CommandCount = 0;
    ECHO_AppData.HkTelemetryPkt.DeviceErrorCount = 0;
    ECHO_AppData.HkTelemetryPkt.DeviceCount = 0;
    return;
} 


/*
** Enable Component
** TODO: Edit for your specific component implementation
*/
void ECHO_Enable(void)
{
    int32 status = OS_SUCCESS;

    /* Check that device is disabled */
    if (ECHO_AppData.HkTelemetryPkt.DeviceEnabled == ECHO_DEVICE_DISABLED)
    {
        /*
        ** Initialize hardware interface data
        ** TODO: Make specific to your application depending on protocol in use
        ** Note that other components provide examples for the different protocols available
        */ 
        ECHO_AppData.EchoUart.deviceString = ECHO_CFG_STRING;
        ECHO_AppData.EchoUart.handle = ECHO_CFG_HANDLE;
        ECHO_AppData.EchoUart.isOpen = PORT_CLOSED;
        ECHO_AppData.EchoUart.baud = ECHO_CFG_BAUDRATE_HZ;
        ECHO_AppData.EchoUart.access_option = uart_access_flag_RDWR;

        /* Open device specific protocols */
        status = uart_init_port(&ECHO_AppData.EchoUart);
        if (status == OS_SUCCESS)
        {
            ECHO_AppData.HkTelemetryPkt.DeviceCount++;
            ECHO_AppData.HkTelemetryPkt.DeviceEnabled = ECHO_DEVICE_ENABLED;
            CFE_EVS_SendEvent(ECHO_ENABLE_INF_EID, CFE_EVS_EventType_INFORMATION, "ECHO: Device enabled");
        }
        else
        {
            ECHO_AppData.HkTelemetryPkt.DeviceErrorCount++;
            CFE_EVS_SendEvent(ECHO_UART_INIT_ERR_EID, CFE_EVS_EventType_ERROR, "ECHO: UART port initialization error %d", status);
        }
    }
    else
    {
        ECHO_AppData.HkTelemetryPkt.DeviceErrorCount++;
        CFE_EVS_SendEvent(ECHO_ENABLE_ERR_EID, CFE_EVS_EventType_ERROR, "ECHO: Device enable failed, already enabled");
    }
    return;
}


/*
** Disable Component
** TODO: Edit for your specific component implementation
*/
void ECHO_Disable(void)
{
    int32 status = OS_SUCCESS;

    /* Check that device is enabled */
    if (ECHO_AppData.HkTelemetryPkt.DeviceEnabled == ECHO_DEVICE_ENABLED)
    {
        /* Open device specific protocols */
        status = uart_close_port(&ECHO_AppData.EchoUart);
        if (status == OS_SUCCESS)
        {
            ECHO_AppData.HkTelemetryPkt.DeviceCount++;
            ECHO_AppData.HkTelemetryPkt.DeviceEnabled = ECHO_DEVICE_DISABLED;
            CFE_EVS_SendEvent(ECHO_DISABLE_INF_EID, CFE_EVS_EventType_INFORMATION, "ECHO: Device disabled");
        }
        else
        {
            ECHO_AppData.HkTelemetryPkt.DeviceErrorCount++;
            CFE_EVS_SendEvent(ECHO_UART_CLOSE_ERR_EID, CFE_EVS_EventType_ERROR, "ECHO: UART port close error %d", status);
        }
    }
    else
    {
        ECHO_AppData.HkTelemetryPkt.DeviceErrorCount++;
        CFE_EVS_SendEvent(ECHO_DISABLE_ERR_EID, CFE_EVS_EventType_ERROR, "ECHO: Device disable failed, already disabled");
    }
    return;
}


/*
** Verify command packet length matches expected
*/
int32 ECHO_VerifyCmdLength(CFE_MSG_Message_t * msg, uint16 expected_length)
{     
    int32 status = OS_SUCCESS;
    CFE_SB_MsgId_t msg_id = CFE_SB_INVALID_MSG_ID;
    CFE_MSG_FcnCode_t cmd_code = 0;
    size_t actual_length = 0;

    CFE_MSG_GetSize(msg, &actual_length);
    if (expected_length == actual_length)
    {
        /* Increment the command counter upon receipt of an invalid command */
        ECHO_AppData.HkTelemetryPkt.CommandCount++;
    }
    else
    {
        CFE_MSG_GetMsgId(msg, &msg_id);
        CFE_MSG_GetFcnCode(msg, &cmd_code);

        CFE_EVS_SendEvent(ECHO_LEN_ERR_EID, CFE_EVS_EventType_ERROR,
           "Invalid msg length: ID = 0x%X,  CC = %d, Len = %ld, Expected = %d",
              CFE_SB_MsgIdToValue(msg_id), cmd_code, actual_length, expected_length);

        status = OS_ERROR;

        /* Increment the command error counter upon receipt of an invalid command */
        ECHO_AppData.HkTelemetryPkt.CommandErrorCount++;
    }
    return status;
} 
