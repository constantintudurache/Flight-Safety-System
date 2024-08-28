/****************************************************
 *  T2-DetectObstacle.c                                         
 *  Created on: 07-may.-2024 17:28:37                      
 *  Implementation of the Class T2-DetectObstacle       
 *  Original author: The Administrator                     
 ****************************************************/

#include "T2-DetectObstacle.h"

void warnPilotObstacleDetected()
{
	
} 

void *t2 (){  

  printf ("Sensor 2 \n");
  int dig_value;
  while(1) {
	dig_value = read_infrared ();
	

	if (dig_value == 0)
	   set_led_1 (1);
	else
	   set_led_1 (0);
        //printf ("value 3 = %d \n", sensor);
	delay(200);
  }
  pthread_exit (NULL);
}

