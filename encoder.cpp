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
  double ch1pos, ch1rev, ch1deg, ch2pos, ch2rev, ch2deg, ch3pos, ch3rev, ch3deg, ch4pos, ch4rev, ch4deg;
  int 
  rc_initialize();

  //int runs = 500;

  while(true){
    // position of enocder attached to port A
    ch1pos = rc_get_encoder_pos(1); 
    ch1rev = ch1pos/255;
    ch1deg = (ch2rev - floor(ch2rev))*360);
   // ch2pos = rc_get_encoder_pos(2);
   // ch2rev = ch2pos/255;
   // ch2deg = (ch2rev - floor(ch2rev))*360;
   // ch3pos = rc_get_encoder_pos(3);
   // ch3rev = ch3pos/255;
   // ch3deg = (ch3rev - floor(ch3rev))*360;
   // ch4pos = rc_get_encoder_pos(4);
   // ch4rev = ch4pos/255;
   // ch4deg = (ch3deg - floor(ch4rev))*360;

   printf("CH1\nRevolution: %f\nDegree: %f\n",  ch1rev, ch1deg);
   // printf("CH2\nRevolution: %f\n", ch2pos, ch2rev);
   // printf("CH3\nRevolution: %f\n", ch3pos, ch3rev);
   // printf("CH4\nRevolution: %f\n", ch4rev, );
    usleep(100000);
    //--runs;
  }
  printf(" All readings completed.\n");
}
