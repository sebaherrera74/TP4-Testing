#include "motorPasoPaso.h" 
#include "mock_funcaux.h"

void paso_1(void){
	gpioWrite(GPIO1,0);
	gpioWrite(GPIO2,1);
	gpioWrite(GPIO3,1);
	gpioWrite(GPIO4,1);
}



void paso_1_Expected(void){
	gpioWrite_Expect(GPIO1,0);
	gpioWrite_Expect(GPIO2,1);
	gpioWrite_Expect(GPIO3,1);
	gpioWrite_Expect(GPIO4,1);
}

void paso_2_Expected(void){
	gpioWrite_Expect(GPIO1,1);
	gpioWrite_Expect(GPIO2,0);
	gpioWrite_Expect(GPIO3,1);
	gpioWrite_Expect(GPIO4,1);
}