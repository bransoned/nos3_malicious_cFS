/*******************************************************************************
** File:
**   echo_msg.h
**
** Purpose:
**  Define ECHO application commands and telemetry messages
**
*******************************************************************************/
#ifndef _ECHO_MSG_H_
#define _ECHO_MSG_H_

#include "cfe.h"
#include "echo_device.h"


/*
** Ground Command Codes
** TODO: Add additional commands required by the specific component
*/
#define ECHO_NOOP_CC                 0
#define ECHO_RESET_COUNTERS_CC       1
#define ECHO_ENABLE_CC               2
#define ECHO_DISABLE_CC              3
#define ECHO_CONFIG_CC               4


/* 
** Telemetry Request Command Codes
** TODO: Add additional commands required by the specific component
*/
#define ECHO_REQ_HK_TLM              0
#define ECHO_REQ_DATA_TLM            1


/*
** Generic "no arguments" command type definition
*/
typedef struct
{
    /* Every command requires a header used to identify it */
    CFE_MSG_CommandHeader_t CmdHeader;

} ECHO_NoArgs_cmd_t;


/*
** ECHO write configuration command
*/
typedef struct
{
    CFE_MSG_CommandHeader_t CmdHeader;
    uint32   DeviceCfg;

} ECHO_Config_cmd_t;


/*
** ECHO device telemetry definition
*/
typedef struct 
{
    CFE_MSG_TelemetryHeader_t TlmHeader;
    ECHO_Device_Data_tlm_t Echo;

} __attribute__((packed)) ECHO_Device_tlm_t;
#define ECHO_DEVICE_TLM_LNGTH sizeof ( ECHO_Device_tlm_t )


/*
** ECHO housekeeping type definition
*/
typedef struct 
{
    CFE_MSG_TelemetryHeader_t TlmHeader;
    uint8   CommandErrorCount;
    uint8   CommandCount;
    uint8   DeviceErrorCount;
    uint8   DeviceCount;
  
    /*
    ** TODO: Edit and add specific telemetry values to this struct
    */
    uint8   DeviceEnabled;
    ECHO_Device_HK_tlm_t DeviceHK;

} __attribute__((packed)) ECHO_Hk_tlm_t;
#define ECHO_HK_TLM_LNGTH sizeof ( ECHO_Hk_tlm_t )

#endif /* _ECHO_MSG_H_ */
