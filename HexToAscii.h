/* 
 * File:   HexToAscii.h
 * Author: Atef
 *
 * Created on May 8, 2022, 8:59 PM
 */

#ifndef HEXTOASCII_H
#define	HEXTOASCII_H

#include "config.h"


int validate(char *hex);
int valueOf(char symbol);
char* hexToAscii(char hex[]);

#endif	/* HEXTOASCII_H */

