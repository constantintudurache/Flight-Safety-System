/****************************************************
 *  T6-Mode.c                                         
 *  Created on: 07-may.-2024 17:28:38                      
 *  Implementation of the Class T6-Mode       
 *  Original author: The Administrator                     
 ****************************************************/

#include "T6-Mode.h"

int mode;



void indicatedCurrentMode()
{
	
} 

void *t6 (){
  while(1) {


	if (read_button() == 0){
	    mode = (mode + 1) % 2;
	    printf ("Aircraft mode = %d  \n \n", mode);
	}
	
	
	
        
        delay (200);
  }
  pthread_exit (NULL);
}

int getMode() {
	return mode;
}

