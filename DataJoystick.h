/****************************************************
 *  DataJoystick.h                                         
 *  Created on: 07-may.-2024 17:28:35                      
 *  Implementation of the Class DataJoystick       
 *  Original author: The Administrator                     
 ****************************************************/

#include "Interfaces.h"
#if !defined(EA_F51A1B81_6667_4a88_846B_E8DD59808EA5__INCLUDED_)
#define EA_F51A1B81_6667_4a88_846B_E8DD59808EA5__INCLUDED_


#ifdef __cplusplus
extern "C" {
#endif

int get_inclination_x();
int get_inclination_y();
int getRealX();
int getRealY();
void set_inclination_x(int value);
void set_inclination_y(int value);
void setRealX(int real_x);
void setRealY(int real_y);


#ifdef __cplusplus
}
#endif


#endif /*!defined(EA_F51A1B81_6667_4a88_846B_E8DD59808EA5__INCLUDED_)*/
 
