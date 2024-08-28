/****************************************************
 *  DataAltitudeObstacle.c                                         
 *  Created on: 07-may.-2024 17:28:35                      
 *  Implementation of the Class DataAltitudeObstacle       
 *  Original author: The Administrator                     
 ****************************************************/

#include "DataAltitudeObstacle.h"

int isObstacleDetected;
int altitude;



int get_obstacle()
{
	return isObstacleDetected;
}

int get_altitude()
{
	return altitude;
}

void set_obstacle(int value)
{
	isObstacleDetected = value;
}

void set_altitude(int value)
{
	altitude = value;
} 

