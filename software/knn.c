#include "system.h"
#include "periphs.h"
#include <iob-uart.h>
#include "iob_timer.h"
#include "iob_knn.h"
#include "random.h" //random generator for bare metal
#include "stdlib.h"
#include "stdint.h"

//uncomment to use rand from C lib 
//#define cmwc_rand rand

#ifdef DEBUG //type make DEBUG=1 to print debug info
#define S 12  //random seed
#define N 10  //data set size
#define K 4   //number of neighbours (K)
#define C 4   //number data classes
#define M 4   //number samples to be classified
#else
#define S 12   
#define N 100000
#define K 10  
#define C 4  
#define M 100 
#endif

#define INFINITE ~0

//
//Data structures
//


int main() {

 	uart_init(UART_BASE,FREQ/BAUD);  
	srand(S);

	knn_init(KNN_BASE);
	knn_start();
	knn_reset();

	int x = 0, x_1 = rand(), x_2 = rand(), x_3 = rand();
	signed long long int y = 0, y_hardware = 0;

	knn_setx(x_3);
	knn_setx(x_2);
	knn_setx(x_1);


	for(int i=3; i<100; i++){
		x = rand();
		knn_setx(x);

		y = x*x_1+x_2*x_3;

		x_3=x_2;
		x_2=x_1;
		x_1=x;

		uart_printf("\nIteração = %d, y = %d, y_hardware = %d \n", i, y, knn_read_y());
	}

	knn_stop();
	return 0;
  
}


