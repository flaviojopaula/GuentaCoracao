#include "../Include/dac.h"

VOID DAC_init()
{
	LPC_PINCON->PINSEL1 = 0x00200000;			// Set P0.26 to DAC output
	LPC_DAC->CNTVAL 	= 0x00FF;				// Timer reload value
	LPC_DAC->CTRL 		|= ( 0x1 << 1 );		// Double-buffering feature
	LPC_DAC->CR 		|= ( 0x1 << 16 );		// Low-power: maximum update rate is 400 kHz
	DAC_set_update_rate();
}

VOID DAC_start()
{
	LPC_DAC->CTRL |= ( 0x1 << 2 );				// Timer enabled
}

VOID DAC_stop()
{
	LPC_DAC->CTRL &= ~( 0x1 << 2 );				// Timer disabled
}

BOOL DAC_set_value(USHORT value)
{
	// TODO: verificar o tamanho do USHORT
	// Assumindo USHORT 16 bits
	// TODO: verificar se esse if e necessario com double-buffering
	if( LPC_DAC->CTRL & 0x1 )					// Check if last data was updated
	{
		// TODO: converter o valor
		value 			&= ~( 0x3F << 10 );		// Clear 6 MSB since the resolution is 10 bits
		LPC_DAC->CR 	|= ( value << 6 );		// Set VALUE bits (CR[6:15])
		LPC_DAC->CR 	&= ~( value << 6 );		// Clear VALUE bits (CR[6:15])
		return true;
	}
	else return false;

}

VOID DAC_set_update_rate()
{
}
