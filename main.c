#include "Nokia5110.h"
#include "jogo.h"
//#include "bitmap.h"
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/tm4c123gh6pm.h"
#include "driverlib/debug.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/adc.h"
#include "driverlib/timer.h"
#include "driverlib/hibernate.h"
#include "driverlib/interrupt.h"




int main(void){
                        SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
                        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);//Habilita o portal F
                        //desbloquear SW2(pin 0) e interrupcao botao
                        HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;
                        HWREG(GPIO_PORTF_BASE+GPIO_O_CR) |= GPIO_PIN_0;
                        //define como input
                        GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);
                        GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
                        GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);

                        GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_4|GPIO_PIN_0, GPIO_FALLING_EDGE);
                        GPIOIntEnable(GPIO_PORTF_BASE,GPIO_PIN_4|GPIO_PIN_0);
                        GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_3);

                        //botao2();

                        run();
}

