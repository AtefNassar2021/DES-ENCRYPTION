/* 
 * File:   UART.h
 * Author: Atef
 *
 * Created on April 20, 2022, 2:31 PM
 */

#ifndef UART_H
#define	UART_H

#define Rx_enable    1
#define Tx_enable    1
#define Rx_disable   0
#define Tx_disable   0
void init_uart(int BaudRate,int RX_EN,int TX_EN);

void uart_send(char data);
void uart_send_str(char* str);
void uart_send_Num(int num);

char uart_receive();
char uart_receive_str(int n);


#endif	/* UART_H */

