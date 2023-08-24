#ifndef __OLED_H_
#define __OLED_H_

#include "stm32f1xx_hal.h"

#include "u8g2.h"
#include "u8x8.h"

#include "i2c.h"

extern u8g2_t u8g2;

void OLED_Init(u8g2_t *u8g2);

#endif
