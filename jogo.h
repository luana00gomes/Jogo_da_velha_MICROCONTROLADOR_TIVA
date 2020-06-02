/*
 * jogo.h
 *
 *  Created on: 30 de nov de 2019
 *      Author: Luna
 */

#ifndef JOGO_H_
#define JOGO_H_

#include "Nokia5110.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "inc/hw_ssi.h"
#include "inc/hw_uart.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/hibernate.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"
#include "driverlib/lcd.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"
#include "driverlib/ssi.h"
#include "driverlib/rom.h"

void inicia (void);
void partida (void);
void run (void);
void playerMov (int *ocupado, char peca);
void machineMov (int *ocupado,  char peca);
void setaPosicao(int *ocupado, int x);
void botao2 ();
void win(char* M, char x);
void loose(char* v, char x);

#endif /* JOGO_H_ */
