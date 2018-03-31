#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <chrono>
#include <thread>
extern "C" {
	#include <roboticscape.h>
	#include <rc_usefulincludes.h>
}

int main(void) {

	double ch2pos = 0.0,ch2rev = 0.0, ch2FullDeg = 0.0, ch2PosDeg = 0.0, ch2RelZero = 0.0 ;
	int counts = 0;
	//int modpos;
	rc_initialize();
	int dispcount = 100;
	std::chrono::steady_clock::time_point _start(std::chrono::steady_clock::now());
	const double DELAY = 0.05;
	while(true) {
		
		//Reads the the position of motor and number of revolutions that it performed.
		ch2pos = rc_get_encoder_pos(2);
		ch2rev = ch2pos / 255;
		ch2FullDeg = ch2pos / 0.70833333;
		ch2PosDeg = (ch2rev - floor(ch2rev))*360;

		if (dispcount <= 0) {
			printf("Revolution: %f\nDegrees: %f\n", ch2rev, ch2PosDeg);
			dispcount = 100;

		} else {
			--dispcount;
		}
		std::chrono::steady_clock::time_point _end(std::chrono::steady_clock::now());
		double diff = (2000.0-DELAY/500.0)/1000.0/1000.0;
		if (std::chrono::duration_cast<std::chrono::duration<double>>(_end - _start).count() > diff) {
			rc_send_esc_pulse_normalized(1, DELAY);
		//	printf("Pulse generated. Diff: %.6f\n", diff);
						}
	}
}
