#include "PWM1.h"

void PWM_init(void){
	// Configura el pin PB1 como salida para generar la señal PWM
	DDRB |= (1 << PB1);

	// Reinicia el contador del Timer1
	TCNT1 = 0;

	// Establece el valor máximo del contador (TOP) en 39999 para obtener un periodo de 20 ms
	ICR1 = 39999;

	// Configura el modo de comparación para el canal A (OC1A) sin inversión
	TCCR1A = (1 << COM1A1) | (0 << COM1A0);

	// Selecciona el modo Fast PWM con TOP en ICR1 (modo 14)
	TCCR1A |= (1 << WGM11);
	TCCR1B = (1 << WGM13) | (1 << WGM12);

	// Configura el prescaler en 8 ? frecuencia de 2 MHz para el Timer1
	TCCR1B |= (1 << CS11);
}

void servo_writeA(float adc_Value){
	// Convierte el valor del ADC a un valor de pulso entre 1000 y 4800 (1 ms a 2.4 ms)
	OCR1A = map(adc_Value, 0, 1024, 1000, 4800);
}

float map(float x, float in_min, float in_max, float out_min, float out_max){
	// Función para escalar un valor de un rango de entrada a uno de salida
	return ((x - in_min) * (out_max - out_min) / (in_max - in_min)) + out_min;
}
