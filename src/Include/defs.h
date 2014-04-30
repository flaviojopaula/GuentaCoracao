#ifndef DEFS_H_
#define DEFS_H_

#define INT int
#define UINT unsigned int
#define CHAR char
#define UCHAR unsigned char
#define SHORT short
#define USHORT unsigned short
#define LONG long
#define ULONG unsigned long
#define FLOAT float
#define DOUBLE double

#ifndef false
#define false 0
#endif

#ifndef true
#define true 1
#endif


/*
 * Porta da UART para comunicacao serial com o simulador
 */
#define SIM_COMM_PORT 	0

/*
 * Baud Rate para comunicacao serial com o simulador
 */
#define SIM_COMM_BAUD 	9600

/*
 * Tempo destinado a vSimCommTask
 */
#define SIM_COMM_TIME	100

#endif
