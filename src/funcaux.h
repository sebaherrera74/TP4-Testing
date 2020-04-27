# ifndef FUNCAUX_H
# define FUNCAUX_H

# include <stdint.h>



void gpioConfig( uint8_t gpio, uint8_t output );
void gpioWrite (uint8_t gpio,uint8_t estadologicoSalida);
void delay(uint8_t veloc);

# endif 