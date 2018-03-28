#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

extern "C" {
	#include <roboticscape.h>
	#include <rc_usefulincludes.h>
//	#include <rc_defs.h>
}

int main(void){

	double ch1pos, ch1rev;

	uint64_t ptime = 0;

	rc_intialize();

	while(true){ 
		
		ch2pos = rc_get_encoder_pos(2);
		ch2rev = ch2pos / 255;
		if(time_t(NULL) >= ptime + 0.015){
			rc_send_esc_pulse_normalized(1, 0.005);
			ptime = time_t(NULL) + 0.02;
		//	printf("Pulse generated at %f\n", ptime);
		}
	}
}
