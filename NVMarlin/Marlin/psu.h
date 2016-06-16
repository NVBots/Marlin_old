/*
  psu.h - PSU control library for Arduino using 8 bit timers- Version 1
  Copyright (c) 2014 Paul Burke - NVBots  All right reserved.

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
//#ifdef MAD
#ifndef PSU_H
#define PSU_H

#include <inttypes.h>
#include "Configuration.h"

// split into planned and status
typedef struct {
  bool enable; // PSU_ENABLE, PSU_DISABLE
  volatile bool contact; // PSU_MAKE, PSU_BREAK -buffered
  bool fire; // PSU_ON / PSU_OFF - buffered
} psu_t;

extern psu_t psu;

void psu_init();
void psu_extinguish();

// SPI Comms with STM32
void stm32_spi_init();
void stm32_spi_send(char);
void stm32_spi_send_pay(unsigned int, unsigned int, unsigned int, bool);
void stm32_spi_send_buf(byte*, int);


// PSU constants

#define PSU_DISABLE 0
#define PSU_ENABLE 1

#define PSU_BREAK 0
#define PSU_MAKE 1

#define PSU_OFF 0
#define PSU_ON 1

#endif // PSU_H
//#endif // MAD
