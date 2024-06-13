/*******************************************************************************
** File: echo_app.h
**
** Purpose:
**   This is the main header file for the ECHO application.
**
*******************************************************************************/
#ifndef _ECHO_APP_H_
#define _ECHO_APP_H_

/*
** Include Files
*/
#include "cfe.h"
#include "echo_device.h"
#include "echo_events.h"
#include "echo_platform_cfg.h"
#include "echo_perfids.h"
#include "echo_msg.h"
#include "echo_msgids.h"
#include "echo_version.h"
#include "hwlib.h"


/*
** Specified pipe depth - how many messages will be queued in the pipe
*/
#define ECHO_PIPE_DEPTH            32


/*
** Enabled and Disabled Definitions
*/
#define ECHO_DEVICE_DISABLED       0
#define ECHO_DEVICE_ENABLED        1


/*
** ECHO global data structure
** The cFE convention is to put all global app data in a single struct. 
** This struct is defined in the `echo_app.h` file with one global instance 
** in the `.c` file.
*/
typedef struct
{
    /*
    ** Housekeeping telemetry packet
    ** Each app defines its own packet which contains its OWN telemetry
    */
    ECHO_Hk_tlm_t   HkTelemetryPkt;   /* ECHO Housekeeping Telemetry Packet */
    
    /*
    ** Operational data  - not reported in housekeeping
    */
    CFE_MSG_Message_t * MsgPtr;             /* Pointer to msg received on software bus */
    CFE_SB_PipeId_t CmdPipe;            /* Pipe Id for HK command pipe */
    uint32 RunStatus;                   /* App run status for controlling the application state */

    /*
	** Device data 
    ** TODO: Make specific to your application
	*/
    ECHO_Device_tlm_t DevicePkt;      /* Device specific data packet */

    /* 
    ** Device protocol
    ** TODO: Make specific to your application
    */ 
    uart_info_t EchoUart;             /* Hardware protocol definition */

} ECHO_AppData_t;


/*
** Exported Data
** Extern the global struct in the header for the Unit Test Framework (UTF).
*/
extern ECHO_AppData_t ECHO_AppData; /* ECHO App Data */


/*
**
** Local function prototypes.
**
** Note: Except for the entry point (ECHO_AppMain), these
**       functions are not called from any other source module.
*/
void  ECHO_AppMain(void);
int32 ECHO_AppInit(void);
void  ECHO_ProcessCommandPacket(void);
void  ECHO_ProcessGroundCommand(void);
void  ECHO_ProcessTelemetryRequest(void);
void  ECHO_ReportHousekeeping(void);
void  ECHO_ReportDeviceTelemetry(void);
void  ECHO_ResetCounters(void);
void  ECHO_Enable(void);
void  ECHO_Disable(void);
int32 ECHO_VerifyCmdLength(CFE_MSG_Message_t * msg, uint16 expected_length);

#endif /* _ECHO_APP_H_ */
