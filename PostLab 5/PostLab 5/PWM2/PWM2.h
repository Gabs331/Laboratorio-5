#ifndef PWM2_H_
#define PWM2_H_

#include <avr/io.h>
#include <stdint.h>

#define Nor 0
#define Inv 1

#define PC_FF_2 0
#define Fast_FF_2 1
#define PC_OCRA_2 2
#define Fast_OCRA_2 3

void setPWM2A(uint8_t INV_NOR, uint8_t ModoOnda, uint16_t Prescaler);
void DutyA2(uint8_t DutyCycle);



#endif /* PWM2_H_ */