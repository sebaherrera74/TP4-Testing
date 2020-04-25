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

uint8_t secuenciaPasos[4][4]={
		{1,1,1,0},
		{1,1,0,1},
		{1,0,1,1},
		{0,1,1,1}
};
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

void secuenciaCW(uint8_t velocidad,uint16_t cantPasos){
    uint8_t aux=0;
    uint16_t i;

    for (i=0;i<cantPasos;i++){

   	aux=(i+4)%4;
		gpioWrite(GPIO1,secuenciaPasos[aux][0]);
		gpioWrite(GPIO2,secuenciaPasos[aux][1]);
		gpioWrite(GPIO3,secuenciaPasos[aux][2]);
		gpioWrite(GPIO4,secuenciaPasos[aux][3]);
	  delay(velocidad);
	}
}

void secuenciaCCW(uint8_t velocidad,uint16_t cantPasos){
    uint8_t aux=0;
    uint16_t i;

    for (i=0;i<cantPasos;i++){
    	aux=(i+4)%4;

	   gpioWrite(GPIO1,secuenciaPasos[aux][3]);
	   gpioWrite(GPIO2,secuenciaPasos[aux][2]);
	   gpioWrite(GPIO3,secuenciaPasos[aux][1]);
	   gpioWrite(GPIO4,secuenciaPasos[aux][0]);
     delay(velocidad);
	 }
}