#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
extern "C" {
  #include <roboticscape.h>
  #include <rc_usefulincludes.h>
}

int main(void)
{
  int ch1pos;

  rc_initialize();

  int runs = 200;

  while(runs){
    // position of enocder attached to port A
    ch1pos = rc_get_encoder_pos(1); 
    printf("Current position: %f\n", ch1pos);
    --runs;
  }
  printf(" All readings completed.\n");
}
