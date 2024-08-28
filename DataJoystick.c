/****************************************************
 *  DataJoystick.c                                         
 *  Created on: 07-may.-2024 17:28:35                      
 *  Implementation of the Class DataJoystick       
 *  Original author: The Administrator                     
 ****************************************************/

#include "DataJoystick.h"

int indicated_x;
int indicated_y;
int real_x;
int real_y;



int get_inclination_x()
{
	return indicated_x;
}

int get_inclination_y()
{
	return indicated_y;
}

int getRealX()
{
	return 0;
}

int getRealY()
{
	return 0;
}

void set_inclination_x(int value)
{
	indicated_x = value;
}

void set_inclination_y(int value)
{
	indicated_y = value;
}

void setRealX(int real_x)
{
	
}

void setRealY(int real_y)
{
	
} 

