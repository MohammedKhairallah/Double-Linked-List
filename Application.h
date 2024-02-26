/* 
 * File:   Application.h
 * Author: Mohammed Khairallah
 * linkedin : linkedin.com/in/mohammed-khairallah
 * Created on January 8, 2024, 10:364 PM
 */

#ifndef _APPLICATION_H
#define _APPLICATION_H

/* Section : Includes */
#include <windows.h>
#include "DoubleLinkedList.h"

/* Section : Macro Declarations */



/* Section : Macro Functions Declarations */


/* Section : Data type Declarations */

Node_t *NodeHead_1 = NULL;   /* initially there are no nodes */
uint32_t data1 ;             /* Variable for user input for data of the linked list */
uint16_t NodePos;            /* Variable for user input for position of the linked list*/
uint8_t UserChoice ;         /* Variable for user choices */
uint8_t displaycount;        /* Variable to count the display of dots while waiting */



/* Section : Functions Declaration */

void instructions( void );  // Function to Displays a menu of available options to the user

#endif  //_APPLICATION_H