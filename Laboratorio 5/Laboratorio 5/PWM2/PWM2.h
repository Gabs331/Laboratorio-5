#ifndef PWM2_H_
#define PWM2_H_

#include <avr/io.h>

// Inicializa el Timer1 en modo PWM rápido para generar señal en PB1 (OC1A)
void PWM2_init(void);

// Ajusta el ciclo de trabajo del PWM en base al valor leído del ADC
void servo_writeB(float valADC);

// Realiza una conversión lineal de un rango de valores a otro (escalamiento)
float map2(float x, float in_min, float in_max, float out_min, float out_max);

#endif /* PWM2_H_ */
