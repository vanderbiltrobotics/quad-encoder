#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <ctime>

extern "C" {
	#include <roboticscape.h>
	#include <rc_usefulincludes.h>
//	#include <rc_defs.h>
}

int main(void) {

	double ch2pos, ch2rev;

	//uint64_t ptime = 0;
	struct timespec ptime, ctime;

	rc_initialize();
	rc_send_esc_pulse_normalized(1, 0.005);
	int dispcount = 10000;
	while(true) {
		ch2pos = rc_get_encoder_pos(2);
		ch2rev = ch2pos / 255;
		if (dispcount <= 0) {
			printf("Position: %f\n Revolution: %f\n", ch2pos, ch2rev);
			dispcount = 10000;
		} else {
			--dispcount;
		}
		//rc_send_esc_pulse_normalized(1, 0.005);
		clock_gettime(CLOCK_MONOTONIC, &ctime);
		if (difftime(ctime.tv_sec, ptime.tv_sec)*1000.0 + (ctime.tv_nsec - ptime.tv_nsec)/(1000.0*1000.0) >= 15.0) {
			rc_send_esc_pulse_normalized(1, 0.005);
			//ptime = time_t(NULL);
			printf("Pulse generated\n");
			clock_gettime(CLOCK_MONOTONIC, &ptime);
		}
	}
}
