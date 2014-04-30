/*
 * simulador.c
 *
 *  Created on: 29/04/2014
 *      Author: Flavio
 */

#include "simulator/simulator.h"
#include "uart/uart.h"

void simulator_init(void)
{
	UARTInit( SIM_COMM_PORT, SIM_COMM_BAUD );
}

ULONG receiveECG(void)
{
	UCHAR bReceived = false;
	ULONG unReceivedECG = 0;
	ULONG uchReceivedChar1  = 0;
	ULONG uchReceivedChar2  = 0;
	while(!bReceived)
	{
		while(uchReceivedChar1 & LVALUE)	// Se recebeu um LVALUE, espera um HVALUE
		{
			uchReceivedChar1 = UARTGetChar( SIM_COMM_PORT, false );
		}
		uchReceivedChar2 = UARTGetChar( SIM_COMM_PORT, false );
		if(uchReceivedChar2 == NO_DATA)		// Se ainda nao chegou outro dado
		{
			while(uchReceivedChar2 == NO_DATA)		// Aguarda receber um dado
			{
				uchReceivedChar2 = UARTGetChar( SIM_COMM_PORT, false );
			}
		}
		if(uchReceivedChar1 & LVALUE)	// Se recebeu o LVALUE
		{
			unReceivedECG |= ((uchReceivedChar1 & PACKET_MASK) << PACKET_BITS); // Seta os msb
			unReceivedECG |= (uchReceivedChar2 & PACKET_MASK);	// Seta os lsb
			bReceived = true;
		}
		// Se nao recebeu LVALUE, houve perda de dados, reinicia-se o ciclo
	}
	return unReceivedECG;
}
