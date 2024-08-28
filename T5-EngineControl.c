/****************************************************
 *  T5-EngineControl.c                                         
 *  Created on: 07-may.-2024 17:28:37                      
 *  Implementation of the Class T5-EngineControl       
 *  Original author: The Administrator                     
 ****************************************************/

#include "T5-EngineControl.h"
#include "T6-Mode.h"

sem_t sem_engine_power;

void init_sem_T5(){
	
	sem_init(&sem_engine_power, 0, 1);
	
}

void alertPilot()
{
	
} 

void *t5 (){
  while(1) {
	if (getMode() == 0) {
		sem_wait(&sem_engine_power);
		set_engine_power(read_single_sensor (2));
		sem_post(&sem_engine_power);
		

		if ((get_inclination_x() > 1 || get_inclination_x() < -1) && (get_inclination_y() > 1 || get_inclination_y() < -1)){
			sem_wait(&sem_engine_power);
			set_engine_power(get_engine_power() + 250);
			sem_post(&sem_engine_power);
			}
		else if (get_inclination_x() > 1 || get_inclination_x() < -1){
			sem_wait(&sem_engine_power);
			set_engine_power(get_engine_power() + 150);
			sem_post(&sem_engine_power);}
		else if ((get_inclination_y() > 1 || get_inclination_y() < -1) && (get_engine_power() < 600)){
			sem_wait(&sem_engine_power);
			set_engine_power(get_engine_power() + 100);
			sem_post(&sem_engine_power);
			}

		if(get_engine_power() < 500)
		  set_led_1(1);
		else 
		  set_led_1(0);

		if(get_engine_power() < 400){
			sem_wait(&sem_engine_power);
			set_engine_power(600);
			sem_post(&sem_engine_power);
		}

		if(get_engine_power() > 900){
			sem_wait(&sem_engine_power);
			set_engine_power(800);
			sem_post(&sem_engine_power);
		}

		//printf ("value of the engine power = %d \n \n", get_engine_power()); 
			
			
	}
	else {
		sem_wait(&sem_engine_power);
		set_engine_power(read_single_sensor (2));
		sem_post(&sem_engine_power);
		}
		
	delay (250);
  }
  pthread_exit (NULL);
}

