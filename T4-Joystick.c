/****************************************************
 *  T4-Joystick.c                                         
 *  Created on: 07-may.-2024 17:28:37                      
 *  Implementation of the Class T4-Joystick       
 *  Original author: The Administrator                     
 ****************************************************/

#include "T4-Joystick.h"
#include "T6-Mode.h"

sem_t sem_inclination_x;
sem_t sem_inclination_y;

void init_sem_T4(){
	
	sem_init(&sem_inclination_x, 0, 1);
	sem_init(&sem_inclination_y, 0, 1);
	
}

void displayAircraftPosition(int ax, int ay)
{
	
}

void displayJoystickPostion(int jx, int jy)
{
	
} 

void *t4 (){

  printf ("Sensor 3 \n");
  int x_value, y_value, prev_x = 0;
  while(1) {
	if(getMode() == 0) {
			x_value = Read_X_Giroscope ();
		if (!(x_value > 15 || x_value < -15) && abs(x_value - prev_x) > 1 && (get_altitude() > 200) && (get_altitude() < 800) && get_obstacle() == 0){
			sem_wait(&sem_inclination_x);
			//sem_wait(&sem_obstacle);
			set_inclination_x(x_value);
			sem_post(&sem_inclination_x);
		}
		if (get_altitude() <= 200 && get_obstacle() == 0){
			sem_wait(&sem_inclination_x);
			//sem_wait(&sem_obstacle);
			set_inclination_x(0);
			sem_post(&sem_inclination_x);
		}
		if (get_altitude() >= 800 && get_obstacle() == 0){
			sem_wait(&sem_inclination_x);
			//sem_wait(&sem_obstacle);
			set_inclination_x(0);
			sem_post(&sem_inclination_x);
		}
			
			//printf ("value of pitch = %d \n", get_inclination_x());

			y_value = Read_Y_Giroscope ();
		if (!(y_value > 45 || y_value < -45) && get_obstacle() == 0){
			sem_wait(&sem_inclination_y);
			//sem_wait(&sem_obstacle);
			set_inclination_y(y_value);
			sem_post(&sem_inclination_y);
			}
		if ((get_inclination_y() > 35 || get_inclination_y() < -35) || get_altitude() <= 250)
			set_led_1(1);
		else
			set_led_1(0);
			//printf ("value of roll = %d \n \n", get_inclination_y()); 
		
		if (get_aircraft_speed () > 900 || get_altitude () > 800 || get_altitude () < 300)
		   printf ("Risk situation \n"); 
			
			
	}
	else {
			x_value = Read_X_Giroscope ();
			sem_wait(&sem_inclination_x);
			set_inclination_x(x_value);
			sem_post(&sem_inclination_x);
			
			y_value = Read_Y_Giroscope ();
			
			sem_wait(&sem_inclination_y);
			set_inclination_y(y_value);
			sem_post(&sem_inclination_y);
			
			if ((get_inclination_y() > 35 || get_inclination_y() < -35) || get_altitude() <= 250)
				set_led_1(1);
			else
				set_led_1(0);
		}
		delay (250);
  }
  pthread_exit (NULL);
}

