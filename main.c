#include <stdio.h>    // Used for printf() statements
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <wiringPi.h> // Include WiringPi library!

#include <pthread.h>

#include <math.h>
#include <time.h>

#include "T1-AltitudeControl.h"
#include "T2-DetectObstacle.h"
#include "T3-Speed.h"
#include "T4-Joystick.h"
#include "T5-EngineControl.h"
#include "T6-Mode.h"


// #define TRUE 1
// #define FALSE 0

#define NUM_THREADS 7
#define delta 3

void init_sems(){
	init_sem_T1();
	init_sem_T3();
	init_sem_T4();
	init_sem_T5();
}

void *t7 (){
  while(1) {

	printf ("Altitude = %d \n \n", get_altitude());
	printf ("Engine power indicated by the pilot = %d \n \n", read_single_sensor (2));
	printf ("Engine power transferred to the aircraft = %d \n \n", get_engine_power());
	printf ("Joystick position (x,y) = %d %d \n \n", Read_X_Giroscope (), Read_Y_Giroscope());
	printf ("Aircraft position (x,y) = %d %d \n \n", get_inclination_x (), get_inclination_y ());
	//printf ("Aircraft mode = %d  \n \n", mode);
	
        
        delay (3000);
  }
  pthread_exit (NULL);
}


int main(void)
{
    init_sems();
    int n;
    init_devices ();

    pthread_t thread [NUM_THREADS]; 

    pthread_create(&thread[0], NULL, t1, NULL);
    pthread_create(&thread[1], NULL, t2, NULL);
    pthread_create(&thread[2], NULL, t3, NULL);
    pthread_create(&thread[3], NULL, t4, NULL);
    pthread_create(&thread[4], NULL, t5, NULL);
    pthread_create(&thread[5], NULL, t6, NULL);
    pthread_create(&thread[6], NULL, t7, NULL);

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    pthread_join(thread[2], NULL);
    pthread_join(thread[3], NULL);
    pthread_join(thread[4], NULL);
    pthread_join(thread[5], NULL);
    pthread_join(thread[6], NULL);
    
    close_devices ();

    return (0);
}
