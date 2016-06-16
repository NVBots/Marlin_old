
/*
  psu.cpp - PSU control library for Arduino using 8 bit timers- Version 1
  Copyright (c) 2014 Paul Burke & Andrew Feldman - NVBots  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#ifdef MAD
#include "psu.h"
#include "Configuration.h"
#include "ConfigurationStore.h"
#include "pins.h"
#include <avr/interrupt.h>
#include <Arduino.h>
#include "Marlin.h"
#include "temperature.h"
#include "stepper.h"
#include <SPI.h>

psu_t psu;

void stm32_spi_init()
{
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV2);
    pinMode(STM32_NSS, OUTPUT);
    digitalWrite(STM32_NSS,HIGH);
}

void stm32_spi_send(char serial_char)
{
    digitalWrite(STM32_NSS,LOW); // take the SS pin low to select the chip
    SPI.transfer(serial_char); //  send the char via SPI:
    digitalWrite(STM32_NSS,HIGH); // take the SS pin high to de-select the chip:
}

void stm32_spi_send_pay(unsigned int line, unsigned int volt, unsigned int window, bool status)
{
    byte spi_buf[9];
	static unsigned int last_line;

    if(line != 0 && line == last_line) return;

    spi_buf[0] = line >> 8;
    spi_buf[1] = (byte) line;
    spi_buf[2] = volt >> 8;
    spi_buf[3] = (byte) volt;
    spi_buf[4] = window >> 8;
    spi_buf[5] = (byte) window;
    spi_buf[6] = (byte) status;

    uint16_t checksum = (uint16_t)(0xFFFF - (    	spi_buf[0] +
    												spi_buf[1] +
													spi_buf[2] +
													spi_buf[3] +
													spi_buf[4] +
													spi_buf[5] +
													spi_buf[6]));
    spi_buf[7] = checksum >> 8;
    spi_buf[8] = (byte) checksum;

    stm32_spi_send_buf(spi_buf, 9);
    last_line = line;
}

void stm32_spi_send_buf(byte* buffer, int length)
{
     digitalWrite(STM32_NSS,LOW); // take the SS pin low to select the chip
     delayMicroseconds(1000);
   	 SPI.transfer(buffer, length); //  send the buffer via SPI:
     digitalWrite(STM32_NSS,HIGH); // take the SS pin high to de-select the chip:
}


void psu_init()
{
	SET_INPUT(PSU_CONTACT_PIN);
	SET_INPUT(PSU_STALL_PIN);

	pinMode(PSU_ENABLE_PIN, OUTPUT);
	digitalWrite(PSU_ENABLE_PIN, LOW);

	SET_OUTPUT(PSU_FIRING_PIN);
	WRITE(PSU_FIRING_PIN, LOW);
  
	psu.enable = PSU_DISABLE;
	psu.contact = PSU_BREAK;

	psu_extinguish();
}


void psu_extinguish(){

	  WRITE(PSU_FIRING_PIN, LOW);
	  digitalWrite(PSU_ENABLE_PIN, LOW);

}

#endif // MAD
