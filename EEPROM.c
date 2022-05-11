#include "config.h"
#include "EEPROM.h"

#define EEPROM_PAGE_SIZE 16


//******************************************************************
//Function  : To write single byte into EEPROM memory.
//Arguments : 1. SLA_W device address.
//          : 2. 16 bit internal address of the location to be written.
//          : 3. One byte of data to be written into EEPROM.
//Return    :    none
//******************************************************************
static volatile uint16_t boatloader_Size=0;
static volatile uint16_t counter=0;
static volatile uint16_t remainder=0;
static uint8_t index =0;
void EEPROM_Write(uint16_t addr, uint8_t dat)
	{
		while(1)
		{
			I2C_start();
			I2C_write(EEPROM_DEVICE_ADDR);
			
			if ( (TWSR & 0xF8) != TW_MT_SLA_NACK) break;
			
			I2C_stop();
		}

		I2C_write(addr >> 8);
		I2C_write(addr);
		I2C_write(dat);
		I2C_stop();
	}

//******************************************************************
//Function  : To read single byte from the EEPROM memory.
//Arguments : 1. SLA_W device address.
//          : 2. 16 bit internal address of the location to read.
//Return    :    Byte containing the read data.
//******************************************************************
	uint8_t EEPROM_Read( uint16_t addr)
	{
		uint8_t dat;
		while(1)
		{
			I2C_start();
			I2C_write(EEPROM_DEVICE_ADDR);
			
			if ( (TWSR & 0xF8) != TW_MT_SLA_NACK) break;
			
			I2C_stop();
		}
		
		I2C_write(addr >> 8); 
		I2C_write(addr); 

		I2C_start();
		I2C_write(EEPROM_DEVICE_ADDR+1);
		//dat = twiread(0); //0 - NOACK
		dat = I2C_read_NACK();
		I2C_stop();
		
		return dat;
	}


void EEPROM_Write_Len( uint16_t addr, uint8_t len, uint8_t *buf)
	{
		while(1) // wait until device is unconciscious
		{
			I2C_start();
			I2C_write(EEPROM_DEVICE_ADDR);
			
			if ( (TWSR & 0xF8) != TW_MT_SLA_NACK) break;
			
			I2C_stop();
		}
		
		I2C_write(addr >> 8);
		I2C_write(addr);
		
		while(len--) I2C_write(*buf++);
		
		I2C_stop();
	}

void EEPROM_Read_Len( uint16_t addr, uint16_t len, uint8_t *buf) 
	{
		while(1)
		{
			I2C_start();
			I2C_write(EEPROM_DEVICE_ADDR);
			
			if ( (TWSR & 0xF8) != TW_MT_SLA_NACK) break;
			
			I2C_stop();
		}
		
		I2C_write(addr >> 8);
		I2C_write(addr);
		
		I2C_start();
		I2C_write(EEPROM_DEVICE_ADDR+1);

		while( --len )
			*buf++ = I2C_read_ACK();
		
		*buf = I2C_read_NACK();
		
		I2C_stop();
}