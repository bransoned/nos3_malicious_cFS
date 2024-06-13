/************************************************************************
** File:
**   $Id: echo_platform_cfg.h  $
**
** Purpose:
**  Define echo Platform Configuration Parameters
**
** Notes:
**
*************************************************************************/
#ifndef _ECHO_PLATFORM_CFG_H_
#define _ECHO_PLATFORM_CFG_H_

/*
** Default ECHO Configuration
*/
#ifndef ECHO_CFG
    /* Notes: 
    **   NOS3 uart requires matching handle and bus number
    */
    #define ECHO_CFG_STRING           "usart_16"
    #define ECHO_CFG_HANDLE           16
    #define ECHO_CFG_BAUDRATE_HZ      115200
    #define ECHO_CFG_MS_TIMEOUT       50            /* Max 255 */
    /* Note: Debug flag disabled (commented out) by default */
    //#define ECHO_CFG_DEBUG
#endif

#endif /* _ECHO_PLATFORM_CFG_H_ */
