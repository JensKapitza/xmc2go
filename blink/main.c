#include "xmc1100.h"
void delay(unsigned len)
{
	while(len--);
}
void initPorts()
{
	// LED's are on P1.0 and P1.1
	// So make these push-pull outputs
	P1_IOCR0 = BIT15 + BIT7;
}
int main()
{
	initPorts();
	while(1)
	{
		P1_OUT = 0x01;
		delay(50000);
		P1_OUT = 0x02;
		delay(300000);
	};
	return 0;
}
