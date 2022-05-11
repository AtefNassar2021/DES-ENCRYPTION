/* 
 * File:   DES.h
 * Author: Atef
 *
 * Created on April 24, 2022, 11:13 AM
 */

#ifndef DES_H
#define	DES_H
#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char ubyte;

#define KEY_LEN 8
typedef ubyte key_t[KEY_LEN];

void driver(const key_t key, const ubyte *message, int len);


#endif	/* DES_H */

