/*
 * simulador.h
 *
 *  Created on: 29/04/2014
 *      Author: Flavio
 */

#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include "defs.h"

#define NO_DATA -1

/**
 * Defines relativos ao Protocolo
 */
#define TYPE_BIT 7
#define HVALUE	1 << TYPE_BIT
#define LVALUE	0 << TYPE_BIT
#define PACKET_BITS	5
#define PACKET_MASK 0b11111

/**
 * Inicia a comunicacao serial para o simulador de ECG
 */
void simulator_init(void);

/**
 * Recebe um valor de ECG de 10 bits utilizando o seguinte protocolo:
 *
 * 	  [ bit7   bit6   bit5   bit4   bit3   bit2   bit1   bit0 ]
 *
 * O bit7 corresponde ao tipo do dado. Se for HVALUE, os bits 4~0
 * representam os bits 9~5 do dado de ECG. Se for LVALUE, tais bits
 * representam os bits 4~0 do dado de ECG.
 *
 * @return: Valor de ECG recebido ou NO_DATA em caso contrario
 */
ULONG receiveECG(void);

#endif /* SIMULATOR_H_ */
