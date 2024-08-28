/****************************************************
 *  T3-Speed.c                                         
 *  Created on: 07-may.-2024 17:28:37                      
 *  Implementation of the Class T3-Speed       
 *  Original author: The Administrator                     
 ****************************************************/

#include "T3-Speed.h"

sem_t sem_aircraft_speed;
sem_t sem_alt_speed;

void init_sem_T3(){
	
	sem_init(&sem_aircraft_speed, 0, 1);
	sem_init(&sem_alt_speed, 0, 1);
	
}

void displayIndicatedEnginePower(int engine_power)
{
	
}

void displayTransferedEnginePower(int engine_power)
{
	
} 

void *t3 (){

  printf ("Sensor 3 \n");

  while(1) {
	  //if (mode == 0) {
		sem_wait(&sem_alt_speed);
		set_alt_speed(read_single_sensor (2)); 
		sem_post(&sem_alt_speed);

		if (get_alt_speed() < 900){
			   //aircraft_speed = alt_speed;
		   sem_wait(&sem_aircraft_speed);
		   set_aircraft_speed(get_alt_speed());
		   sem_post(&sem_aircraft_speed);
		}
		//printf ("Aircraft speed : %d \n", get_aircraft_speed ());
		//printf ("Potentiometer speed : %d \n", get_alt_speed());
		   
			
			delay (300);
	  //}
  }
  pthread_exit (NULL);
}
