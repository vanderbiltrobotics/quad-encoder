#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

extern "C" {
  #include <roboticscape.h>
  #include <rc_usefulincludes.h>
}

int main(void)
{
  double ch1pos, ch1rev;
  //25% duty cycle on a 50 Hz cycle = 0.25(0.02)= 0.005s
  // uint64_t ptime = time_t(NULL); 

  rc_initialize();

  //int runs = 500;

  while(true){
    // position of enocder attached to port A
    ch1pos = rc_get_encoder_pos(2); 
    ch1rev = ch1pos/255;
    printf("Current position: %f\n Current Revolution: %f\n", ch1pos, ch1rev);
    usleep(100000);
    //--runs;
  }
  printf(" All readings completed.\n");
}
