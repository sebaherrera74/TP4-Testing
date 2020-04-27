#include <stdio.h>
#include <stdint.h>

#define GPIO_OUTPUT 1
#define velocidadBaja   10
#define velocidadMedia  20
#define velocidadAlta   30 



uint16_t gradosPorPaso;
typedef uint64_t tick_t;

uint8_t GPIO1;
uint8_t GPIO2;
uint8_t GPIO3;
uint8_t GPIO4;

void inicializacionMotor(void);
void secuenciaCW(uint8_t velocidad,uint16_t cantPasos);
void secuenciaCCW(uint8_t velocidad,uint16_t cantPasos);
int cambioVelocidad(int velocidadSp);


//void delay( tick_t duration_ms );