#include <stdio.h>
#include <stdint.h>

#define GPIO_OUTPUT 1

uint16_t gradosPorPaso;

uint8_t GPIO1;
uint8_t GPIO2;
uint8_t GPIO3;
uint8_t GPIO4;

void inicializacionMotor (uint16_t );
void secuenciaCW(uint8_t velocidad,uint16_t cantPasos);
void secuenciaCCW(uint8_t velocidad,uint16_t cantPasos);
void paso_1(void);