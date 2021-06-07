#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>

int main ()
{ 
  float t;
  float h;
  float heiz;
  float luft;
  char in_t[10];
  char in_h[10];
  char in_heiz[10];
  char in_luft[10];
  int fd ;
  
 
  if ((fd = serialOpen ("/dev/ttyACM0", 9600)) < 0)
  {
    fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
    return 1 ;
  }

// Loop, getting and printing characters

//  while (serialDataAvail (fd))
  //  {delay(2000);
    //  printf ("%3d", serialGetchar (fd)) ;
      //fflush (stdout) ;
    //}
  
  for (;;)
  { if (serialGetchar(fd) == 't'){
      for (int i = 0; i<4; i++){
        in_t[i] = serialGetchar(fd);
      }
      for (int i = 0; i<4; i++){
        in_h[i] = serialGetchar(fd);
      }
      for (int i = 0; i<4; i++){
        in_heiz[i] = serialGetchar(fd);
      }
      for (int i = 0; i<4; i++){
        in_luft[i] = serialGetchar(fd);
      }
      t = atof (in_t);
      h = atof (in_h);
      heiz = atof (in_heiz);
      luft = atof (in_luft);
      printf("Temperatur:%.2f Grad Celsius \n", t);
      printf("Luftfeuchtigkeit:%.2f %% \n", h);
      printf("Heizleistung: %.2f %% \n", heiz);
      printf("Lüfterleistung: %.2f %% \n", luft);
      
      fflush (stdout) ;
    }
   //  else{
   //    if (serialGetchar(fd) == 'h'){
   //     for (int j = 0; j<4; j++){
    //      input[j] = serialGetchar(fd);
  //      }
   //     h = atof (input);
   //     printf("Luftfeuchtigkeit:%.2f \n", h);
   //     fflush (stdout) ;
       //}
    // }

  }
 
  //for (;;)
  //{ if (serialGetchar(fd) == 10){
    //  int i=0;
     // while(serialGetchar(fd)!=13){
      //  input[i] = serialGetchar(fd);
       // i++;
     // }
     // t = atof (input);
     // printf("Temperatur:%.2f \n", t);
    //}
    //putchar (serialGetchar (fd)) ;
    //fflush (stdout) ;
  //}
}
