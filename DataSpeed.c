/****************************************************
 *  DataSpeed.c                                         
 *  Created on: 07-may.-2024 17:28:35                      
 *  Implementation of the Class DataSpeed       
 *  Original author: The Administrator                     
 ****************************************************/

#include "DataSpeed.h"

int indicatedSpeed;
int realSpeed;
int engine_power;


int get_alt_speed()
{
	return indicatedSpeed;
}

int get_aircraft_speed()
{
	return realSpeed;
}

void set_aircraft_speed(int value)
{
	indicatedSpeed = value;
}

void set_alt_speed(int value)
{
	realSpeed = value;
} 

int get_engine_power () {
    return engine_power;
}

void set_engine_power(int value){
    
    engine_power = value;
    
}

