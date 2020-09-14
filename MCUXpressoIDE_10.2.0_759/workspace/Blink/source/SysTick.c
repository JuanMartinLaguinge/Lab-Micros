/*
 * sysTick.c
 *
 *  Created on: Sep 12, 2020
 *      Author: Agus
 */


#include "SysTick.h"
//#include "core_cm4.h"
#include "MK64F12.h"
#include "gpio.h"
#include "board.h"
#include "hardware.h"
#include <stdio.h>


bool SysTick_Init (void)
{
    //Inicializacion de SysTick
	SysTick->CTRL = 0x00;
	SysTick->LOAD = 12500000L - 1; // 500ms @ 100MHz
	SysTick->VAL = 0x00;
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
}


__ISR__ SysTick_Handler(void)
{
	static uint32_t counter = 4; //cuento 4 veces y asi con 125 ms logro un blink cada medio segundo, es practico porque solo tengo 24 bits en el registro systick

	if (counter == 0)
	{
		gpioToggle(PIN_LED_RED);
		counter = 4;
	}

	counter--;
}