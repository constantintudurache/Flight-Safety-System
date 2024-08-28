/****************************************************
 *  T1-AltitudeControl.h                                         
 *  Created on: 07-may.-2024 17:28:36                      
 *  Implementation of the Class T1-AltitudeControl       
 *  Original author: The Administrator                     
 ****************************************************/

#if !defined(EA_ADFB15C8_4C8A_4b0e_AC41_C0AD43EB08E5__INCLUDED_)
#define EA_ADFB15C8_4C8A_4b0e_AC41_C0AD43EB08E5__INCLUDED_


#ifdef __cplusplus
extern "C" {
#endif

#include "DataAltitudeObstacle.h"
#include "DataJoystick.h"
#include "Interfaces.h"

/*DataAltitudeObstacle *m_DataAltitudeObstacle;
DataJoystick *m_DataJoystick;
Interfaces *m_Interfaces;*/


void alertPilotDescending();
void displayAltitude();
void *t1();

//int getAltitude();

#ifdef __cplusplus
}
#endif

#endif /*!defined(EA_ADFB15C8_4C8A_4b0e_AC41_C0AD43EB08E5__INCLUDED_)*/
 
