/*
1-Incializar motor asignando las salidas a las bobinas a los GPIO1,GPIO2,GPIO3,GPIO4 de la EDU-CIAA
 una vez inicilizada estas salidas verificar que se encuentra desernegizadas o sea con el motor detenido 
2-Activo una secuencia de paso (paso1)
3-verificar Test que al pasar una cantidad de pasos al motor, en el sentido de las agujas del reloj 
y a una determinada velocidad el motor se detenga 
4-Idem al anterior pero en sentido inverso 
5-verificar cambio de velocidad en la secuencia del motor */

#include "unity.h"
#include "motorPasoPaso.h"
#include "mock_funcaux.h"



void setUp(void){
   
   
}

void tearDown(void){
}

// 1-Test inicializo salidas a motor de acuerdo a los gpio de la EDU-CIAA
//   y los pongo en estado High (motor desernegizado)

void test_salidasBobina(void){
    uint16_t cantpasos=1;
      
    gpioConfig_Expect(GPIO1, GPIO_OUTPUT );
	gpioConfig_Expect(GPIO2, GPIO_OUTPUT );
	gpioConfig_Expect(GPIO3, GPIO_OUTPUT );
	gpioConfig_Expect(GPIO4, GPIO_OUTPUT );
    inicializacionMotor(); 
}

//2-test-Activo una secuencia de paso (paso1)
 void test_ActivoUnaSecuenciaPaso(void){
     int8_t cantPasos=1;                  
     uint8_t velocidad=1;
     int i;
    
      gpioWrite_Expect(GPIO1,1);
	 gpioWrite_Expect(GPIO2,1);
	 gpioWrite_Expect(GPIO3,1);
	 gpioWrite_Expect(GPIO4,0);
      delay_Ignore();
      secuenciaCW(velocidad,cantPasos);

 }    
 //Test para aprender

void test_ActivoUnaSecuenciaPaso_2(void){
     int8_t cantPasos=4;                  
     uint8_t velocidad=1;
     int i;
    
      gpioWrite_Expect(GPIO1,1);
	 gpioWrite_Expect(GPIO2,1);
	 gpioWrite_Expect(GPIO3,1);
	 gpioWrite_Expect(GPIO4,0);
      delay_Ignore();

      gpioWrite_Expect(GPIO1,1);
	 gpioWrite_Expect(GPIO2,1);
	 gpioWrite_Expect(GPIO3,0);
	 gpioWrite_Expect(GPIO4,1);
      delay_Ignore();

      gpioWrite_Expect(GPIO1,1);
	 gpioWrite_Expect(GPIO2,0);
	 gpioWrite_Expect(GPIO3,1);
	 gpioWrite_Expect(GPIO4,1);
      delay_Ignore();

      gpioWrite_Expect(GPIO1,0);
	 gpioWrite_Expect(GPIO2,1);
	 gpioWrite_Expect(GPIO3,1);
	 gpioWrite_Expect(GPIO4,1);
      delay_Ignore();
      
      secuenciaCW(velocidad,cantPasos);
 } 

//3-Test de activacion de una secuencia en sentido de las agujas del reloj 

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
       gpioWrite_Expect(GPIO1,sPasos[aux][0]);
	   gpioWrite_Expect(GPIO2,sPasos[aux][1]);
	   gpioWrite_Expect(GPIO3,sPasos[aux][2]);
	   gpioWrite_Expect(GPIO4,sPasos[aux][3]);
       delay_Ignore();
        }

       secuenciaCW(velocidad,cantPasos);
 } 

//4 Test de activacion de una secuencia en sentido contrario a las agujas del reloj 

void test_ActivoUnaSecuenciaPaso_CCW(void){  //giro la inversa y verifico 
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
     gpioWrite_Expect(GPIO1,sPasos[aux][3]);
	 gpioWrite_Expect(GPIO2,sPasos[aux][2]);
	 gpioWrite_Expect(GPIO3,sPasos[aux][1]);
	 gpioWrite_Expect(GPIO4,sPasos[aux][0]);
     delay_Ignore();
       }
      secuenciaCCW(velocidad,cantPasos);
}


//5-Test de cambio de velocidad de acuerdo a una velocidad dada

 void test_cambioVelocidad(void){
     int velocidadSp=4;                                //velocidad de set point 
     int velocidadSeleccionada;                        //resultado esperado de velocidad 
     velocidadSeleccionada=cambioVelocidad(velocidadSp);
     TEST_ASSERT_EQUAL(4,velocidadSeleccionada);
    }






