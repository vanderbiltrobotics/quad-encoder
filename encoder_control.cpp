#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
//#include <ctime>
#include <chrono>
#include <thread>
extern "C" {
	#include <roboticscape.h>
	#include <rc_usefulincludes.h>
//	#include <rc_defs.h>
}

int main(void) {

	double ch2pos, ch2rev,presTime, diffTime;
        //double tickCount = (double) getTickCount();
	//uint64_t ptime = 0;
	//struct timespec ptime, ctime;
	//auto start = std::chrono::steady_clock::time_point_start(std::chrono::steady_clock::now());
	//auto endTime = std::chrono::steady_clock::time_point_end(std::chrono::steady_clock::now());
	rc_initialize();
	//rc_send_esc_pulse_normalized(1, 0.005);
	int dispcount = 100;
	std::chrono::steady_clock::time_point _start(std::chrono::steady_clock::now());
	const double DELAY = 0.05;
	while(true) {
		//Reads the the position of motor and number of revolutions that it performed.
		ch2pos = rc_get_encoder_pos(2);
		ch2rev = ch2pos / 255;

		//presTime = ((double)getTickCount()  -tickCount)/getTickFrequency();
		if (dispcount <= 0) {
			printf("Position: %f\n Revolution: %f\n", ch2pos, ch2rev);
			dispcount = 100;
		} else {
			--dispcount;
		}
		std::chrono::steady_clock::time_point _end(std::chrono::steady_clock::now());
		//rc_send_esc_pulse_normalized(1, 0.005);
		//clock_gettime(CLOCK_MONOTONIC, &ctime);
		//if (difftime(ctime.tv_sec, ptime.tv_sec)*1000.0 + (ctime.tv_nsec - ptime.tv_nsec)/(1000.0*1000.0) >= 15.0) {
		double diff = (2000.0-DELAY/500.0)/1000.0/1000.0;
		if (std::chrono::duration_cast<std::chrono::duration<double>>(_end - _start).count() > diff) {
			rc_send_esc_pulse_normalized(1, DELAY);
			//ptime = time_t(NULL);
			printf("Pulse generated. Diff: %.6f\n", diff);
			//clock_gettime(CLOCK_MONOTONIC, &ptime);
			//presTime = ((double)getTickCount() - tickCount)/getTickFrequency();
		}
	}
}
