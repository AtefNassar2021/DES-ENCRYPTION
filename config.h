/* 
 * File:   config.h
 * Author: Atef
 *
 * Created on April 20, 2022, 2:25 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#define F_CPU 16000000UL

#define ON     1
#define OFF    0

#define OUT     1
#define IN      0

#define Led0    PC2
#define Led1    PC7
#define Led2    PD3

#define _PA    0
#define _PB    1
#define _PC    2
#define _PD    3

#define Relay   PA2
#define Buzzer  PA3

#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"
#include "I_O.h"
#include <stdlib.h>
#include "LCD.h"
#include<string.h>
#include "DES.h"
#include "HexToAscii.h"
#endif	/* CONFIG_H */

