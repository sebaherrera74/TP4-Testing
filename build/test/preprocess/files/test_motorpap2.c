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

    uint16_t cantpasos=0;



    gpioConfig_CMockExpect(33, GPIO1, 1);

 gpioConfig_CMockExpect(34, GPIO2, 1);

 gpioConfig_CMockExpect(35, GPIO3, 1);

 gpioConfig_CMockExpect(36, GPIO4, 1);

    inicializacionMotor(cantpasos);

}





 void test_ActivoUnaSecuenciaPaso(void){

     int8_t cantPasos=1;

     uint8_t sentidoGiro=1;

     uint8_t velocidad=1;

     int i;



      gpioWrite_CMockExpect(47, GPIO1, 1);

   gpioWrite_CMockExpect(48, GPIO2, 1);

   gpioWrite_CMockExpect(49, GPIO3, 1);

   gpioWrite_CMockExpect(50, GPIO4, 0);

      delay_CMockIgnore();

      secuenciaCW(velocidad,cantPasos);



 }



void test_ActivoUnaSecuenciaPaso_2(void){

     int8_t cantPasos=4;

     uint8_t sentidoGiro=1;

     uint8_t velocidad=1;

     int i;



      gpioWrite_CMockExpect(62, GPIO1, 1);

   gpioWrite_CMockExpect(63, GPIO2, 1);

   gpioWrite_CMockExpect(64, GPIO3, 1);

   gpioWrite_CMockExpect(65, GPIO4, 0);

      delay_CMockIgnore();



      gpioWrite_CMockExpect(68, GPIO1, 1);

   gpioWrite_CMockExpect(69, GPIO2, 1);

   gpioWrite_CMockExpect(70, GPIO3, 0);

   gpioWrite_CMockExpect(71, GPIO4, 1);

      delay_CMockIgnore();



      gpioWrite_CMockExpect(74, GPIO1, 1);

   gpioWrite_CMockExpect(75, GPIO2, 0);

   gpioWrite_CMockExpect(76, GPIO3, 1);

   gpioWrite_CMockExpect(77, GPIO4, 1);

      delay_CMockIgnore();



      gpioWrite_CMockExpect(80, GPIO1, 0);

   gpioWrite_CMockExpect(81, GPIO2, 1);

   gpioWrite_CMockExpect(82, GPIO3, 1);

   gpioWrite_CMockExpect(83, GPIO4, 1);

      delay_CMockIgnore();



      secuenciaCW(velocidad,cantPasos);

 }



 void test_ActivoUnaSecuenciaPaso_3(void){

     int8_t cantPasos=6;

     uint8_t sentidoGiro=1;

     uint8_t velocidad=1;

     int i,aux=0;

     uint8_t sPasos[4][4]={

               {1,1,1,0},

             {1,1,0,1},

             {1,0,1,1},

             {0,1,1,1}

                };



    for(i=0;i<cantPasos;i++){

      aux=(i+4)%4;

      gpioWrite_CMockExpect(103, GPIO1, sPasos[aux][0]);

   gpioWrite_CMockExpect(104, GPIO2, sPasos[aux][1]);

   gpioWrite_CMockExpect(105, GPIO3, sPasos[aux][2]);

   gpioWrite_CMockExpect(106, GPIO4, sPasos[aux][3]);

      delay_CMockIgnore();

       }

       secuenciaCW(velocidad,cantPasos);

 }



void test_ActivoUnaSecuenciaPaso_4(void){

     int8_t cantPasos=6;

     uint8_t sentidoGiro=1;

     uint8_t velocidad=1;

     int i,aux=0;

     uint8_t sPasos[4][4]={

               {1,1,1,0},

             {1,1,0,1},

             {1,0,1,1},

             {0,1,1,1}

                };



    for(i=0;i<cantPasos;i++){

      aux=(i+4)%4;

      gpioWrite_CMockExpect(126, GPIO1, sPasos[aux][3]);

   gpioWrite_CMockExpect(127, GPIO2, sPasos[aux][2]);

   gpioWrite_CMockExpect(128, GPIO3, sPasos[aux][1]);

   gpioWrite_CMockExpect(129, GPIO4, sPasos[aux][0]);

      delay_CMockIgnore();

       }

       secuenciaCCW(velocidad,cantPasos);



}
