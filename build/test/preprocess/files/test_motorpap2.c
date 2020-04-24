#include "build/temp/_test_motorpap2.c"
#include "build/test/mocks/mock_funcaux.h"
#include "src/motorPasoPaso.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"






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



    gpioConfig_CMockExpect(33, GPIO1, 1);

 gpioConfig_CMockExpect(34, GPIO2, 1);

 gpioConfig_CMockExpect(35, GPIO3, 1);

 gpioConfig_CMockExpect(36, GPIO4, 1);

    inicializacionMotor(cantpasos);

}





 void test_ActivoUnaSecuenciaPaso(void){



     paso_1_Expected;





 }
