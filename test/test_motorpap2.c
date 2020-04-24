/*
1-Incializar motor asignando las salidas a las bobinas a los GPIO1,GPIO2,GPIO3,GPIO4 de la EDU-CIAA
 una vez inicilizada estas salidas verificar que se encuentra desernegizadas o sea con el motor detenido 
3-verificar Test que al pasar una cantidad de pasos al motor, en el sentido de las agujas del reloj 
y a una determinada velocidad el motor se detenga 
4-Idem al anterior pero en sentido inverso 
5-verificar cambio de velocidad en la secuencia del motor */

#include "unity.h"

#include "motorPasoPaso.h"
#include "mock_funcaux.h"



void setUp(void){
    GPIO1=1;
    GPIO2=2;
    GPIO3=3;
    GPIO4=4;    

}

void tearDown(void){
}

void test_salidasBobina(void){
    uint16_t cantpasos=1024;

    gpioConfig_Expect(GPIO1, GPIO_OUTPUT );
	gpioConfig_Expect(GPIO2, GPIO_OUTPUT );
	gpioConfig_Expect(GPIO3, GPIO_OUTPUT );
	gpioConfig_Expect(GPIO4, GPIO_OUTPUT );

    inicializacionMotor (cantpasos);


}