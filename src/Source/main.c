/**
 * Name        : main.c
 * Version     :
 * Description : main definition for FreeRTOS application
 */

/*
 * FreeRTOS includes
 */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "system_LPC17xx.h"
#include "LPC17xx.h"

#include "defs.h"

#include "simulator/simulator.h"

#define USERTASK_STACK_SIZE configMINIMAL_STACK_SIZE

void __error__(char *pcFilename, unsigned long ulLine) {
}

static void setupHardware(void) {
	simulator_init();
	SystemClockUpdate();
}

/**
 * Task para realizar a comunicacao com o simulador utilizando a porta paralela
 */
void vSimCommTask(void *pvParameters) {
	UINT unReceivedEcg;
	while (1) {
		unReceivedEcg = receiveECG();
		// TODO: Colocar o valor recebido no conversor DA
		vTaskDelay(SIM_COMM_TIME);
	}
}

/**
 * Program entry point 
 */
int main(void) {
	setupHardware();

	/* 
	 * Start the tasks defined within this file/specific to this demo. 
	 */
	xTaskCreate( vSimCommTask, ( signed portCHAR * ) "SimCommTask", USERTASK_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL );
//	xTaskCreate( vUserTask2, ( signed portCHAR * ) "Task2", USERTASK_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL );

	/* 
	 * Start the scheduler. 
	 */
	vTaskStartScheduler();

	/* 
	 * Will only get here if there was insufficient memory to create the idle task. 
	 */
	return 1;
}
