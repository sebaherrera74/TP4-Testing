#include "motorPasoPaso.h" 
#include "mock_funcaux.h"


//------------------bobinas Sin energia salidas de los gpio en 1 ya que comun de motor va a VCC 
//             bobina A   bobina B   bobina C  bobina D    
//              (GPIO1)    (GPIO2)    (GPIO3)   (GPIO4)
//                 1          1          1         1


//-----------------Secuencia de las bobinas  
//             bobina A   bobina B   bobina C  bobina D    
//              (GPIO4)    (GPIO3)    (GPIO2)   (GPIO1)
// numero paso
//  paso 1         1         1         1         0 
//  paso 2         1         1         0         1
//  paso 3         1         0         1         1 
//  paso 4         0         1         1         1


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

void secuenciaMotorCW(uint8_t sentidoGiro){

     paso_1();

}
