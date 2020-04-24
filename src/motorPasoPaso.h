#include <stdio.h>
#include <stdint.h>

#define GPIO_OUTPUT 1

uint16_t gradosPorPaso;

uint8_t GPIO1;
uint8_t GPIO2;
uint8_t GPIO3;
uint8_t GPIO4;

void inicializacionMotor (uint16_t );
void secuenciaMotorCW(uint8_t sentidoGiro);
void paso_1(void);