/* 
 * File:   DoubleLinkedList.h
 * Author: Mohammed Khairallah
 * linkedin : linkedin.com/in/mohammed-khairallah
 * Created on January 8, 2024, 10:364 PM
 */

#ifndef _DOUBLELINKEDLIST_H
#define _DOUBLELINKEDLIST_H

/* Section : Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Section : Macro Declarations */



/* Section : Macro Functions Declarations */


/* Section : Data type Declarations */

/* 
   This typedef enum represents different statuses related to node operations.
   It contains the following enumerators:

   Explanation of enumerators:
   - NODE_NOK: Represents a status where a node operation was not performed successfully.
   - NODE_OK: Represents a status indicating that a node operation was performed successfully.
   - NODE_EMPTY: Represents a status denoting that a node is empty (contains no data or no valid content).
   - NODE_NULL_POINTER: Represents a status when a NULL pointer is passed to the Node.

   NodeStatus_t is an alias for this enumeration, and it can be used to conveniently denote and manage different statuses related to node operations within a program.
*/
typedef enum{
    NODE_NOK = 0,      /* Node operation not performed successfully */
    NODE_OK,           /* Node operation performed successfully  */  
    NODE_EMPTY,        /* Node is empty */
    NODE_NULL_POINTER  /* NULL pointer passed to the Node */
}NodeStatus_t; 

typedef struct Node
{
    uint32_t NodeData;   /* Stores an unsigned 32-bit integer data in the node */
    struct Node *LeftNodeLink;
    struct Node *RightNodeLink;
}Node_t;  /* end structure Node */


/* Section : Functions Declaration */

NodeStatus_t Insert_Node_At_Beginning(struct Node **NodeHead, uint32_t Data); 
NodeStatus_t Insert_Node_At_End(struct Node **NodeHead, uint32_t Data); 
NodeStatus_t Insert_Node_After(struct Node **NodeHead, uint32_t Data, uint32_t position); 
NodeStatus_t Insert_Node_Before(struct Node **NodeHead, uint32_t Data, uint32_t position); 
NodeStatus_t Delete_Node_At_Beginning(struct Node **NodeHead); 
NodeStatus_t Delete_Node_At_End(struct Node **NodeHead); 
NodeStatus_t Delete_Node_At_Intermediate(struct Node **NodeHead, uint32_t position);
NodeStatus_t Display_All_Nodes_Forward(struct Node *NodeHead);
NodeStatus_t Display_All_Nodes_Reverse(struct Node *NodeHead);

#endif  //_DOUBLELINKEDLIST_H