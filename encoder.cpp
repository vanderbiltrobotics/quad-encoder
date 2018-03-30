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
  double ch1pos, ch1rev, ch2pos, ch2rev, ch3pos, ch3rev, ch4pos, ch4rev;

  rc_initialize();

  //int runs = 500;

  while(true){
    // position of enocder attached to port A
    ch1pos = rc_get_encoder_pos(1); 
    ch1rev = ch1pos/255;
   // ch2pos = rc_get_encoder_pos(2);
   // ch2rev = ch2pos/255;
   // ch3pos = rc_get_encoder_pos(3);
   // ch3rev = ch3pos/255;
   // ch4pos = rc_get_encoder_pos(4);
   // ch4rev = ch4pos/255;
   printf("CH1\n Current position: %f\n Current Revolution: %f\n", ch1pos, ch1rev);
   // printf("CH2\n Current position: %f\n Current Revolution: %f\n", ch2pos, ch2rev);
   // printf("CH3\n Current position: %f\n Current Revolution: %f\n", ch3pos, ch3rev);
   // printf("CH4\n Current position: %f\n Current Revolution: %f\n", ch4pos, ch4rev);
    usleep(100000);
    //--runs;
  }
  printf(" All readings completed.\n");
}
