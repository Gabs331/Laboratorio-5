//***************************************************************************
// Universidad del Valle de Guatemala
// IE2023: Programaci�n de Microcontroladores
// Autor: Paola Gabriela Yoc Moreira
// Hardware: ATMEGA328P
// Created: 08/04/2025
//***************************************************************************
// Post Lab 5
//***************************************************************************

#define F_CPU 16000000
#include <util/delay.h>
#include <avr/io.h>
#include "PWM1/PWM1.h"

float Valor1 = 0;

void ADC_init(void);
uint16_t adcRead(uint8_t canal);

int main(void)
{
	DDRD = 0xFF;         // Configurar el puerto D como salida (opcional si se usa para debug)
	ADC_init();          // Inicializar ADC
	PWM_init();          // Inicializar m�dulo PWM

	while (1) 
	{
		Valor1 = adcRead(0);    // Leer valor del canal ADC0
		servo_writeA(Valor1);   // Enviar valor le�do al servo (PWM)
		_delay_ms(10);          // Peque�a pausa para estabilidad
	}
}

void ADC_init(void){
	ADMUX |= (1 << REFS0);      // Referencia de voltaje: AVCC
	ADMUX &= ~(1 << REFS1);
	ADMUX &= ~(1 << ADLAR);     // Justificaci�n a la derecha (10 bits)

	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Prescaler 128 ? 125kHz
	ADCSRA |= (1 << ADEN);      // Habilitar ADC
}

uint16_t adcRead(uint8_t canal){
	ADMUX = (ADMUX & 0xF0) | (canal & 0x0F); // Selecci�n del canal ADC
	ADCSRA |= (1 << ADSC);                  // Iniciar conversi�n
	while (ADCSRA & (1 << ADSC));           // Esperar que finalice la conversi�n
	return ADC;                             // Retornar resultado
}
