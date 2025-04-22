
//***************************************************************************
// Universidad del Valle de Guatemala
// IE2023: Programación de Microcontroladores
// Autor: Paola Gabriela Yoc Moreira 
// Hardware: ATMEGA328P
// Created: 08/04/2025
//***************************************************************************
// Post Lab 5
//***************************************************************************


#define F_CPU 16000000
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include "ADC/ADC.h"
#include "PWM2/PWM2.h"
#include "PWM1/PWM1.h"
#include "PWM0/PWM0.h"



uint8_t Pot = 0;
uint8_t Pot1 = 0;
uint8_t Pot2 = 0;
uint8_t Pot3 = 0;

int main(void)
{
	CLKPR |= (1 << CLKPCE);
	CLKPR |= (1 << CLKPS0); //8MHz
	
	DIDR0 |= (1 << ADC5D);
	
	setPWM0A(Nor, Fast_FF_0, 1024);
	
	setPWM1A(Nor, bits_8, 1024);
	
	setPWM2A(Nor, Fast_FF_2, 1024);
	
	ConfiADCPin(Volt5, JustIz, 7);
	
	ConfiADC(ON, OFF, ON, 128);
	
	sei();
	
	while (1){
		ADCSRA |= (1 << ADSC);
		
		DutyA1(Pot1/6);
		DutyA2(Pot2/6);
		DutyA0(Pot3);
		
		_delay_ms(10);
	}
}

ISR(ADC_vect){
	Pot = (ADMUX & 0x0F);
	
	if (Pot == 7){
		Pot1 = ADCH;
		ConfiADCPin(Volt5, JustIz, 5);
	}
	else if (Pot == 6){
		Pot2 = ADCH;
		ConfiADCPin(Volt5, JustIz, 7);
	}
	else {
		Pot3 = ADCH;
		ConfiADCPin(Volt5, JustIz, 6);
	}
	
	ADCSRA |= (1 << ADIF); //Apagar la bandera de ADC
}