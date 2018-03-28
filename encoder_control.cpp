#include <math.h>
#include <unitsd.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

extern "C" {
	#include <roboticscape.h>
	#include <rc_usefullincludes.h>
}

int main(void){

	double ch1pos, ch1rev;

	unit64_t ptime = time_t(0);

	rc_intialize();

	while(true){ 
		
		ch2pos = rc_get_encoder_pos(2);
		ch2rev = ch2pos / 255;
		if(time_t
