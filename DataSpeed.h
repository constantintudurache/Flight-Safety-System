/****************************************************
 *  DataSpeed.h                                         
 *  Created on: 07-may.-2024 17:28:35                      
 *  Implementation of the Class DataSpeed       
 *  Original author: The Administrator                     
 ****************************************************/
#include "Interfaces.h"

#if !defined(EA_54D98CC2_F517_4c7b_9083_C57260FB88D6__INCLUDED_)
#define EA_54D98CC2_F517_4c7b_9083_C57260FB88D6__INCLUDED_


#ifdef __cplusplus
extern "C" {
#endif

#include "T6-Mode.h"
#include "DataAltitudeObstacle.h"

/*T6-Mode *m_T6-Mode;
DataAltitudeObstacle *m_DataAltitudeObstacle;*/


int get_alt_speed();
int get_aircraft_speed();
void set_alt_speed(int indicatedSpeed);
void set_aircraft_speed(int realSpeed);
int get_engine_power () ;
void set_engine_power(int value);


#ifdef __cplusplus
}
#endif


#endif /*!defined(EA_54D98CC2_F517_4c7b_9083_C57260FB88D6__INCLUDED_)*/
 
