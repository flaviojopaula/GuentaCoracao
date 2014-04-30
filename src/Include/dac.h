#ifndef DAC_H_
#define DAC_H_

#include "lpc17xx.h"
#include "defs.h"

/**
 * Configure the DAC peripheral
 */
VOID DAC_init();

/**
 * Start DAC update
 */
VOID DAC_start();

/**
 * Stop DAC update
 */
VOID DAC_stop();

/**
 * Set the value to be converted by the DAC
 * @param: value 	-	integer between 0 and 3300
 */
BOOL DAC_set_value(USHORT value);

/**
 * Set the period between successive updates
 */
VOID DAC_set_update_rate();

#endif
