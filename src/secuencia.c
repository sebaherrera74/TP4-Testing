#include "secuencia.h"

#define girando  2                             //estados del motor
#define detenido 1

uint8_t secuenciaPaso[4]={0x01,0x02,0x04,0x08};



uint16_t posicion                          //posicion actual del motor
uint8_t  forward                           // 1 para giro clock wise, 0 para inverso  
uint8_t  indiceVector                      //indice para vector del motor paso a paso 
uint8_t  MaxTableIndex                        //Indice maxiomo del perfil deseado           
uint8_t  estadoMotor



void giroMotor (uint8_t target) {
    int longitud                         //used para calcular el movimiento

    if (target!=posicion){

         if (target>posicion){
             forward=1;                  //set flag forward
             longitud=target-posicion  
         }
         
         else
         {
          forward=0;                     //clear  flag forward
          longitud=posicion-target                      
         }
         
         if (longitud<1024)
             MaxTableIndex=longitud>>2           //divido longitud en  4 
         else 
         MaxTableIndex=0xFF                      //max lo pongo en 255    

         recuento=longitud-2*MaxTableIndex-1
         indiceVector=0;               
         estadoMotor=girando;
    }
}

