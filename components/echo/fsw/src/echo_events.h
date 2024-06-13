/************************************************************************
** File:
**    echo_events.h
**
** Purpose:
**  Define ECHO application event IDs
**
*************************************************************************/

#ifndef _ECHO_EVENTS_H_
#define _ECHO_EVENTS_H_

/* Standard app event IDs */
#define ECHO_RESERVED_EID              0
#define ECHO_STARTUP_INF_EID           1
#define ECHO_LEN_ERR_EID               2
#define ECHO_PIPE_ERR_EID              3
#define ECHO_SUB_CMD_ERR_EID           4
#define ECHO_SUB_REQ_HK_ERR_EID        5
#define ECHO_PROCESS_CMD_ERR_EID       6

/* Standard command event IDs */
#define ECHO_CMD_ERR_EID               10
#define ECHO_CMD_NOOP_INF_EID          11
#define ECHO_CMD_RESET_INF_EID         12
#define ECHO_CMD_ENABLE_INF_EID        13
#define ECHO_ENABLE_INF_EID            14
#define ECHO_ENABLE_ERR_EID            15
#define ECHO_CMD_DISABLE_INF_EID       16
#define ECHO_DISABLE_INF_EID           17
#define ECHO_DISABLE_ERR_EID           18

/* Device specific command event IDs */
#define ECHO_CMD_CONFIG_INF_EID        20

/* Standard telemetry event IDs */
#define ECHO_DEVICE_TLM_ERR_EID        30
#define ECHO_REQ_HK_ERR_EID            31

/* Device specific telemetry event IDs */
#define ECHO_REQ_DATA_ERR_EID          32

/* Hardware protocol event IDs */
#define ECHO_UART_INIT_ERR_EID         40
#define ECHO_UART_CLOSE_ERR_EID        41

#endif /* _ECHO_EVENTS_H_ */
