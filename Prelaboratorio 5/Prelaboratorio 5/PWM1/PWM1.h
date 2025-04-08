#ifndef PWM1_H_
#define PWM1_H_

#include <avr/io.h>

// Inicializa el Timer1 en modo PWM rápido para generar señal en PB1 (OC1A)
void PWM_init(void);

// Ajusta el ciclo de trabajo del PWM en base al valor leído del ADC
void servo_writeA(float valADC);

// Realiza una conversión lineal de un rango de valores a otro (escalamiento)
float map(float x, float in_min, float in_max, float out_min, float out_max);

#endif /* PWM1_H_ */
