#include "interconnect.h"
#include "iob_knn.h"
#include "KNNsw_reg.h"
#include "stdint.h"

static int base;

void knn_start(){
  IO_SET(base, KNN_en, 1);
}

void knn_stop(){
  IO_SET(base, KNN_en, 0);
  knn_reset();
}

void knn_init(int base_address){
  base = base_address;
  }

void knn_setx(int x){
	IO_SET(base, KNN_x, x);
}

signed long long int knn_read_y(){

	signed long long int y;
	int y_low, y_high;

	IO_GET(base, KNN_y_low);
	y_high = (int) IO_GET(base, KNN_y_high);
  	y_low = (int) IO_GET(base, KNN_y_low);
  	y = y_high;
  	y <<= 32;
  	y |= y_low;

  	return y;

}

void knn_reset(){
	IO_SET(base, KNN_rst, 1);
	IO_SET(base, KNN_rst, 0);
}
