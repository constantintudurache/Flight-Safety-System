/****************************************************
 *  T1-AltitudeControl.c                                         
 *  Created on: 07-may.-2024 17:28:37                      
 *  Implementation of the Class T1-AltitudeControl       
 *  Original author: The Administrator                     
 ****************************************************/

#include "T1-AltitudeControl.h"
#include "T6-Mode.h"

sem_t sem_altitude;
sem_t sem_inclination_x;
sem_t sem_inclination_y;
sem_t sem_obstacle;

void init_sem_T1(){
	sem_init(&sem_altitude, 0, 1);
	sem_init(&sem_inclination_x, 0, 1);
	sem_init(&sem_inclination_y, 0, 1);
	sem_init(&sem_obstacle, 0, 1);
}

void alertPilotDescending()
{
	
}

void displayAltitude()
{
	
} 

void *t1 (){


  printf ("Sensor 1 \n");
  int dig_value, visibility, counter = 0;

  while(1) {

	if(getMode() == 0) {
		//altitude = read_single_sensor (3);
		sem_wait(&sem_altitude);
		set_altitude(read_single_sensor (3));
		sem_post(&sem_altitude);
		
		if (get_altitude() > 800 || get_altitude() < 300)
			   set_led_1 (1);
		
		else
		   set_led_1 (0);
		//printf ("value 0 = %d \n", sensor);

		dig_value = read_infrared ();
		visibility = read_single_sensor (0);

		if(dig_value == 0 && visibility > 600){
		   set_led_2(1);
		   sem_wait(&sem_obstacle);
		   set_obstacle(1);
		   sem_post(&sem_obstacle);
		   
		}
		else{
				//sem_wait(&sem_obstacle);
				//set_obstacle(1);
				//sem_post(&sem_obstacle);
				
				if(dig_value == 0 && visibility < 600 ){
					sem_wait(&sem_obstacle);
					set_obstacle(1);
					sem_post(&sem_obstacle);
					
					//printf("obs = %d\n", get_obstacle());
					if(get_altitude() < 600 && get_obstacle() == 1){
						
							sem_wait(&sem_inclination_x);
							//printf("cnt= %d \n ", counter);
							set_inclination_x(15);
							
							if (counter > 12) {
								counter = 0;
								sem_wait(&sem_obstacle);
								set_obstacle(0);
								sem_post(&sem_obstacle);
								sem_post(&sem_inclination_x);
								//printf("cnt2= %d \n ", counter);
								
								
							
						}
						counter++;
						//printf("obs = %d\n", get_obstacle());
						sem_post(&sem_inclination_x);
						//sem_post(&sem_obstacle);
					}  	
					if(get_altitude() > 700 && get_obstacle() == 1){
							sem_wait(&sem_inclination_x);
							set_inclination_x(-15);
							if (counter > 12) {
								counter = 0;
								sem_wait(&sem_obstacle);
								set_obstacle(0);
								sem_post(&sem_obstacle);
								sem_post(&sem_inclination_x);
								//printf("cnt2= %d \n ", counter);
								
								
							
						}
						counter++;
						//printf("obs = %d\n", get_obstacle());
						sem_post(&sem_inclination_x);
					   
						
					}
					if(get_altitude() >= 600 && get_altitude() <= 700 && get_obstacle() == 1){
							sem_wait(&sem_inclination_y);
							set_inclination_y(35);
							if (counter > 12) {
								counter = 0;
								sem_wait(&sem_obstacle);
								set_obstacle(0);
								sem_post(&sem_obstacle);
								sem_post(&sem_inclination_y);
								//printf("cnt2= %d \n ", counter);
								
								
							
						}
						counter++;
						//printf("obs = %d\n", get_obstacle());
						sem_post(&sem_inclination_y);
					   
							
						
					}
					//counter++;
						
				}
				else if (visibility < 600 && get_obstacle() == 1){
								
								if (counter > 12) {
								counter = 0;
								sem_wait(&sem_obstacle);
								set_obstacle(0);
								sem_post(&sem_obstacle);
								sem_post(&sem_inclination_x);
								//printf("cnt2= %d \n ", counter);
								
								
							//}
							
							//printf("15\n") ;
							//delay(1000);
						}
						counter++;
					}
						
			 
				//printf("obstacle\n");
				//delay(1000);
			
			//sem_post(get_sem());
			//set_inclination_x(0); 
			//set_inclination_y(0); 
			set_led_2(0);
			}
			//counter ++;
			
			
		}
		else {
				sem_wait(&sem_altitude);
				set_altitude(read_single_sensor (3));
				sem_post(&sem_altitude);
		
			}
		delay(400);
	//printf("vis %d \n ", read_single_sensor(0));
	
	
  }
 
  pthread_exit (NULL);
}

