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
    
    GPIO1=1;
    GPIO2=2;
    GPIO3=3;
    GPIO4=4;    
}

void tearDown(void){
}

// 1-Test inicializo salidas a motor de acuerdo a los gpio de la EDU-CIAA
//   y los pongo en estado High (motor desernegizado)

void test_salidasBobina(void){
    uint16_t cantpasos=0;
      
    gpioConfig_Expect(GPIO1, GPIO_OUTPUT );
	gpioConfig_Expect(GPIO2, GPIO_OUTPUT );
	gpioConfig_Expect(GPIO3, GPIO_OUTPUT );
	gpioConfig_Expect(GPIO4, GPIO_OUTPUT );
    inicializacionMotor(cantpasos); 
}

//2-test-Activo una secuencia de paso (paso1)
 void test_ActivoUnaSecuenciaPaso(void){
     int8_t cantPasos=1;                  
     uint8_t sentidoGiro=1;
     uint8_t velocidad=1;
     int i;
     
      gpioWrite_Expect(GPIO1,1);
	  gpioWrite_Expect(GPIO2,1);
	  gpioWrite_Expect(GPIO3,1);
	  gpioWrite_Expect(GPIO4,0);
      delay_Ignore();
      secuenciaCW(velocidad,cantPasos);

 }    

void test_ActivoUnaSecuenciaPaso_2(void){
     int8_t cantPasos=4;                  
     uint8_t sentidoGiro=1;
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
      gpioWrite_Expect(GPIO1,sPasos[aux][0]);
	  gpioWrite_Expect(GPIO2,sPasos[aux][1]);
	  gpioWrite_Expect(GPIO3,sPasos[aux][2]);
	  gpioWrite_Expect(GPIO4,sPasos[aux][3]);
      delay_Ignore();
       }
       secuenciaCW(velocidad,cantPasos);
 } 

void test_ActivoUnaSecuenciaPaso_4(void){  //giro la inversa y verifico 
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
      gpioWrite_Expect(GPIO1,sPasos[aux][3]);
	  gpioWrite_Expect(GPIO2,sPasos[aux][2]);
	  gpioWrite_Expect(GPIO3,sPasos[aux][1]);
	  gpioWrite_Expect(GPIO4,sPasos[aux][0]);
      delay_Ignore();
       }
      secuenciaCCW(velocidad,cantPasos);
}



/*
//3-
//cantidad de pasos si es positivo(>0) sentido CW,si es negativo (<0) sentido inverso
void test_SecuenciaCWCantidadPasos(void){
     int8_t cantPasos=1;                  //cantidad de paso si es mayor que cero sentido CW
     uint8_t sentidoGiro=1;
     uint8_t velocidad=3;
     int i;
   
    secuenciaCW(velocidad,cantPasos);
  
    // paso_2_Expected;
        
 }    



//comprobar cantidad de pasos y que coincidan con las salidas de motor esperadas
//y con el sentido de giro 
 

*/