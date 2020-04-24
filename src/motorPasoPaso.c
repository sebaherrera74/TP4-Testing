#include "motorPasoPaso.h" 

void inicializacionMotor (uint16_t pasos){
uint16_t cantidadPasos = pasos;

        GPIO1=1;
        GPIO2=2;
        GPIO3=3;
        GPIO4=4;

        gpioConfig(GPIO1,GPIO_OUTPUT);
        gpioConfig(GPIO2,GPIO_OUTPUT);
        gpioConfig(GPIO3,GPIO_OUTPUT);
        gpioConfig(GPIO4,GPIO_OUTPUT);

}
