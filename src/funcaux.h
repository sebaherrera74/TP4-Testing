# ifndef FUNCAUX_H
# define FUNCAUX_H

# include <stdint.h>

void gpioConfig( uint8_t, uint8_t );
void gpioWrite (uint8_t gpio,uint8_t estadologicoSalida);
void delay(uint8_t veloc);
void paso_1(void);

void paso_1_Expected(void);
void paso_2_Expected(void);
# endif 