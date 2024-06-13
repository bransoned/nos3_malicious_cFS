/*******************************************************************************
** File: echo_device.h
**
** Purpose:
**   This is the header file for the ECHO device.
**
*******************************************************************************/
#ifndef _ECHO_DEVICE_H_
#define _ECHO_DEVICE_H_

/*
** Required header files.
*/
#include "device_cfg.h"
#include "hwlib.h"
#include "echo_platform_cfg.h"


/*
** Type definitions
** TODO: Make specific to your application
*/
#define ECHO_DEVICE_HDR              0xDEAD
#define ECHO_DEVICE_HDR_0            0xDE
#define ECHO_DEVICE_HDR_1            0xAD

#define ECHO_DEVICE_NOOP_CMD         0x00
#define ECHO_DEVICE_REQ_HK_CMD       0x01
#define ECHO_DEVICE_REQ_DATA_CMD     0x02
#define ECHO_DEVICE_CFG_CMD          0x03

#define ECHO_DEVICE_TRAILER          0xBEEF
#define ECHO_DEVICE_TRAILER_0        0xBE
#define ECHO_DEVICE_TRAILER_1        0xEF

#define ECHO_DEVICE_HDR_TRL_LEN      4
#define ECHO_DEVICE_CMD_SIZE         9

/*
** ECHO device housekeeping telemetry definition
*/
typedef struct
{
    uint32_t  DeviceCounter;
    uint32_t  DeviceConfig;
    uint32_t  DeviceStatus;

} __attribute__((packed)) ECHO_Device_HK_tlm_t;
#define ECHO_DEVICE_HK_LNGTH sizeof ( ECHO_Device_HK_tlm_t )
#define ECHO_DEVICE_HK_SIZE ECHO_DEVICE_HK_LNGTH + ECHO_DEVICE_HDR_TRL_LEN


/*
** ECHO device data telemetry definition
*/
typedef struct
{
    uint32_t  DeviceCounter;
    uint16_t  DeviceDataX;
    uint16_t  DeviceDataY;
    uint16_t  DeviceDataZ;

} __attribute__((packed)) ECHO_Device_Data_tlm_t;
#define ECHO_DEVICE_DATA_LNGTH sizeof ( ECHO_Device_Data_tlm_t )
#define ECHO_DEVICE_DATA_SIZE ECHO_DEVICE_DATA_LNGTH + ECHO_DEVICE_HDR_TRL_LEN


/*
** Prototypes
*/
int32_t ECHO_ReadData(uart_info_t* device, uint8_t* read_data, uint8_t data_length);
int32_t ECHO_CommandDevice(uart_info_t* device, uint8_t cmd, uint32_t payload);
int32_t ECHO_RequestHK(uart_info_t* device, ECHO_Device_HK_tlm_t* data);
int32_t ECHO_RequestData(uart_info_t* device, ECHO_Device_Data_tlm_t* data);


#endif /* _ECHO_DEVICE_H_ */
