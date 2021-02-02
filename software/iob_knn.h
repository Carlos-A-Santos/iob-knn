#pragma once
#include "stdint.h"

//Functions
void knn_start();	
void knn_stop();
void knn_reset();
void knn_init( int base_address);
void knn_setx(int x);	
signed long long int knn_read_y();
