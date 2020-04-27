#include "build/temp/_test_motorpap2.c"
#include "build/test/mocks/mock_funcaux.h"
#include "src/motorPasoPaso.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"






void setUp(void){





}



void tearDown(void){

}









void test_salidasBobina(void){

    uint16_t cantpasos=1;



    gpioConfig_CMockExpect(30, GPIO1, 1);

 gpioConfig_CMockExpect(31, GPIO2, 1);

 gpioConfig_CMockExpect(32, GPIO3, 1);

 gpioConfig_CMockExpect(33, GPIO4, 1);

    inicializacionMotor();

}





 void test_ActivoUnaSecuenciaPaso(void){

     int8_t cantPasos=1;

     uint8_t velocidad=1;

     int i;



      gpioWrite_CMockExpect(43, GPIO1, 1);

  gpioWrite_CMockExpect(44, GPIO2, 1);

  gpioWrite_CMockExpect(45, GPIO3, 1);

  gpioWrite_CMockExpect(46, GPIO4, 0);

      delay_CMockIgnore();

      secuenciaCW(velocidad,cantPasos);



 }





void test_ActivoUnaSecuenciaPaso_2(void){

     int8_t cantPasos=4;

     uint8_t velocidad=1;

     int i;



      gpioWrite_CMockExpect(58, GPIO1, 1);

  gpioWrite_CMockExpect(59, GPIO2, 1);

  gpioWrite_CMockExpect(60, GPIO3, 1);

  gpioWrite_CMockExpect(61, GPIO4, 0);

      delay_CMockIgnore();



      gpioWrite_CMockExpect(64, GPIO1, 1);

  gpioWrite_CMockExpect(65, GPIO2, 1);

  gpioWrite_CMockExpect(66, GPIO3, 0);

  gpioWrite_CMockExpect(67, GPIO4, 1);

      delay_CMockIgnore();



      gpioWrite_CMockExpect(70, GPIO1, 1);

  gpioWrite_CMockExpect(71, GPIO2, 0);

  gpioWrite_CMockExpect(72, GPIO3, 1);

  gpioWrite_CMockExpect(73, GPIO4, 1);

      delay_CMockIgnore();



      gpioWrite_CMockExpect(76, GPIO1, 0);

  gpioWrite_CMockExpect(77, GPIO2, 1);

  gpioWrite_CMockExpect(78, GPIO3, 1);

  gpioWrite_CMockExpect(79, GPIO4, 1);

      delay_CMockIgnore();



      secuenciaCW(velocidad,cantPasos);

 }







 void test_ActivoUnaSecuenciaPaso_CW(void){

     int8_t cantPasos=6;

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

       gpioWrite_CMockExpect(101, GPIO1, sPasos[aux][0]);

    gpioWrite_CMockExpect(102, GPIO2, sPasos[aux][1]);

    gpioWrite_CMockExpect(103, GPIO3, sPasos[aux][2]);

    gpioWrite_CMockExpect(104, GPIO4, sPasos[aux][3]);

       delay_CMockIgnore();

        }



       secuenciaCW(velocidad,cantPasos);

 }







void test_ActivoUnaSecuenciaPaso_CCW(void){

     int8_t cantPasos=6;

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









 void test_cambioVelocidad(void){

     int velocidadSp=4;

     int velocidadSeleccionada;

     velocidadSeleccionada=cambioVelocidad(velocidadSp);

     UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((velocidadSeleccionada)), (

    ((void *)0)

    ), (UNITY_UINT)(142), UNITY_DISPLAY_STYLE_INT);

    }
