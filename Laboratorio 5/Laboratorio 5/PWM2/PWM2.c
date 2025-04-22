#include "PWM2.h"

void PWM2_init(void){
		DDRB |= (1 << PORTB2);
		
		// Reinicia el contador del Timer0
		TCNT0 = 0;

		
		TCCR0A = (1 << COM1B1) | (0 << COM1B0);
		
		TCCR0B &= ~(1<<CS02); // colocamos en un preescalar de 64
		TCCR0B |= (1<<CS01);
		TCCR0B |= (1<<CS00);
	
		TCCR0B &= (1<<WGM02); 
		TCCR0A |= (1<<WGM01);
		TCCR0A |= (1<<WGM00);
		
}

void servo_writeB(float adc_Value){
	
	OCR0B = map2(adc_Value, 0, 255, 8, 39);
}

float map2(float x, float in_min, float in_max, float out_min, float out_max){
	
	return ((x - in_min) * (out_max - out_min) / (in_max - in_min)) + out_min;
}