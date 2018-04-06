#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <time.h>
extern "C" {
	#include <roboticscape.h>
	#include <rc_usefulincludes.h>
}

int main(void) {
	double ch1pos = 0.0, ch1CurPos = 0.0, ch1rev = 0.0, ch1FullDeg = 0.0, ch1PosDeg = 0.0, ch1vel = 0.0 ;
	double ch2pos = 0.0, ch2CurPos = 0.0, ch2rev = 0.0, ch2FullDeg = 0.0, ch2PosDeg = 0.0, ch2vel = 0.0 ;
	double ch3pos = 0.0, ch3CurPos = 0.0, ch3rev = 0.0, ch3FullDeg = 0.0, ch3PosDeg = 0.0, ch3vel = 0.0 ;
	double ch4pos = 0.0, ch4CurPos = 0.0, ch4rev = 0.0, ch4FullDeg = 0.0, ch4PosDeg = 0.0, ch4vel = 0.0 ;
	double difference = 0.0;
	int counts = 0;
	rc_initialize();
	int dispcount = 1000000;
	int outcount = 100; 
	//std::chrono::steady_clock::time_point _start(std::chrono::steady_clock::now());
	//auto start = std::chrono::steady_clock::now();
	//printf("%f\n", start);
	
	//counts number of ticks
	clock_t t;
	t = clock(); 
	double tsec = 0.0;
	while(true) {
		if ( outcount <= 0) {
			if (dispcount <= 0) {
				//reads the the position of motor and number of revolutions that it performed.
		                ch1pos = rc_get_encoder_pos(1);
               			ch1rev = ch1pos / 255;
                		ch1FullDeg = ch2pos / 0.70833333;
                		ch1PosDeg = (ch1rev - floor(ch1rev))*360;
                		//ch2pos = rc_get_encoder_pos(2);
                		//ch2rev = ch2pos / 255;
                		//ch2FullDeg = ch2pos / 0.70833333;
                		//ch2PosDeg = (ch2rev - floor(ch2rev))*360;
                		//ch3pos = rc_get_encoder_pos(3);
                		//ch3rev = ch3pos / 255;
                		//ch3FullDeg = ch3pos / 0.70833333;
                		//ch3PosDeg = (ch3rev - floor(ch3rev))*360;
                		//ch4pos = rc_get_encoder_pos(4);
                		//ch4rev = ch2pos / 255;
                		//ch4FullDeg = ch4pos / 0.70833333;
                		//ch4PosDeg = (ch4rev - floor(ch4rev))*360;

				printf("Revolution: %f\nDegrees: %f\n", ch1rev, ch1PosDeg);
				dispcount = 1000000;
				t = clock() - t;
				tsec = double(t)/CLOCKS_PER_SEC;
                		printf("Number of ticks elapsed: %f \nSeconds elapsed: %f \n",(float)t, tsec);
				ch1vel = (ch1pos - ch1CurPos)/tsec;
				printf("Current velocity: %f \n", ch1vel);
				ch1CurPos = ch1pos;
				t = clock();
				dispcount = 1000000;
				outcount = 100;
			} else {
				--dispcount;
				outcount = 100;
			}
		}else{
			--outcount;
		}
	}
}
