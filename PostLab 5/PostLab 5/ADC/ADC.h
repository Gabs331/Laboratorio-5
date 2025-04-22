#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <stdint.h>


#define VoltOFF 0
#define Volt5 1
#define Volt1_1 2

#define JustDe 0
#define JustIz 1

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7

#define OFF 0
#define ON 1

void ConfiADCPin(uint8_t VoltRef, uint8_t Just, uint8_t Pin);
void ConfiADC(uint8_t Abil, uint8_t AutoTrig, uint8_t Inter, uint8_t Prescaler);

#endif /* ADC_H_ */