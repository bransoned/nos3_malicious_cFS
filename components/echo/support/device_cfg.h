#ifndef _ECHO_CHECKOUT_DEVICE_CFG_H_
#define _ECHO_CHECKOUT_DEVICE_CFG_H_

/*
** ECHO Checkout Configuration
*/
#define ECHO_CFG
/* Note: NOS3 uart requires matching handle and bus number */
#define ECHO_CFG_STRING           "/dev/usart_16"
#define ECHO_CFG_HANDLE           16
#define ECHO_CFG_BAUDRATE_HZ      115200
#define ECHO_CFG_MS_TIMEOUT       250
#define ECHO_CFG_DEBUG

#endif /* _ECHO_CHECKOUT_DEVICE_CFG_H_ */
