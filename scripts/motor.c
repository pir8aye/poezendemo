#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
//  printf ("Raspberry Pi blink\n") ;
  int p1,p2,p3;
  if (argc < 3) {
    printf("usage: motor <steps> <delay> (larger delay = slower) <direction> (0/1)\n");
    exit(1);
  }

  p1 = atoi(argv[1]); /* better to use strtol */
  p2 = atoi(argv[2]); /* better to use strtol */
  p3 = atoi(argv[3]); /* better to use strtol */
  printf("steps=%d delay=%d\n", p1,p2);

  if (wiringPiSetup () == -1)
    return 1 ;

  pinMode (0, OUTPUT) ;         // aka BCM_GPIO pin 17
  pinMode (2, OUTPUT) ;         // aka BCM_GPIO pin 27

  if (p3==0){
    digitalWrite (2, 1) ;       // On
  }else{
    digitalWrite (2, 0) ;       // On
  }

  double accel,decel;
  double acceloffset=0.03;
  int totalsteps=p1;
  for (int i=0;i<totalsteps;i++)
  {
    int extradelay=0;
    digitalWrite (0, 1) ;       // On
    delay (1+p2) ;               // mS
    digitalWrite (0, 0) ;       // Off
    delay (1+p2) ;
  }
  return 0 ;
}

