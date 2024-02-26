/* 
 * File:   DoubleLinkedList.c
 * Author: Mohammed Khairallah
 * linkedin : linkedin.com/in/mohammed-khairallah
 * Created on January 8, 2024, 10:364 PM
 */

#include "DoubleLinkedList.h"

/**
 * @brief Inserts a new node at the beginning of a doubly linked list.
 *
 * This function takes a double pointer to the head of the linked list and the data to be inserted into the new node.
 *
 * @param NodeHead - Double pointer to the head of the linked list.
 * @param Data - Data to be stored in the new node.
 * @return NodeStatus_t - Status of the node insertion operation (NODE_OK, NODE_NOK, or NODE_NULL_POINTER).
 */
NodeStatus_t Insert_Node_At_Beginning(struct Node **NodeHead, uint32_t Data){
    NodeStatus_t status = NODE_NOK;

    /* Check for NULL pointers in the input parameters */
    if(NULL == NodeHead){
        status = NODE_NULL_POINTER; // Set status as NODE_NULL_POINTER if any pointer is NULL
    }
    else{
        Node_t *NewNode = NULL;  

        // Allocate memory for a new node
        NewNode = (Node_t *)malloc(sizeof(Node_t));

        if(NULL == NewNode){  // Check if memory allocation failed
            status = NODE_NOK; // Set status as NODE_NOK if memory allocation failed
        }
        else{
            if(NULL == *NodeHead){ /* If the linked list is empty */
                *NodeHead = NewNode;  // Make the Head pointer points to the new node 
                NewNode->NodeData = Data; // Assign the data to the NodeData of the new node
                NewNode->LeftNodeLink = NULL;  // This is the only node 
                NewNode->RightNodeLink = NULL;  // This is the only node 
            }
            else{
                NewNode->RightNodeLink = *NodeHead;
                NewNode->LeftNodeLink = NULL;
                NewNode->NodeData = Data; // Assign the data to the NodeData of the new node
                (*NodeHead)->LeftNodeLink = NewNode;
                *NodeHead = NewNode;  // Make the Head pointer points to the new node 
            }
            status = NODE_OK;
        }
    }

    return status;
}

/**
 * @brief Inserts a new node at the end of a doubly linked list.
 *
 * This function takes a double pointer to the head of the linked list and the data to be inserted into the new node.
 *
 * @param NodeHead - Double pointer to the head of the linked list.
 * @param Data - Data to be stored in the new node.
 * @return NodeStatus_t - Status of the node insertion operation (NODE_OK, NODE_NOK, or NODE_NULL_POINTER).
 */
NodeStatus_t Insert_Node_At_End(struct Node **NodeHead, uint32_t Data){
    NodeStatus_t status = NODE_NOK;

    /* Check for NULL pointers in the input parameters */
    if(NULL == NodeHead){
        status = NODE_NULL_POINTER; // Set status as NODE_NULL_POINTER if any pointer is NULL
    }
    else{
        Node_t *NewNode = NULL; 

        // Allocate memory for a new node
        NewNode = (Node_t *)malloc(sizeof(Node_t));

        if(NULL == NewNode){  // Check if memory allocation failed
            status = NODE_NOK; // Set status as NODE_NOK if memory allocation failed
        }
        else{
            if(NULL == *NodeHead){  /* If the linked list is empty */
                *NodeHead = NewNode;  // Make the Head pointer points to the new node 
                NewNode->NodeData = Data;  // Assign the data to the NodeData of the new node
                NewNode->LeftNodeLink = NULL;  // This is the only node 
                NewNode->RightNodeLink = NULL;  // This is the only node 
            }
            else{
                Node_t *TempNode = *NodeHead; 

                while (TempNode->RightNodeLink)
                {
                    TempNode = TempNode->RightNodeLink;
                }
                
                TempNode->RightNodeLink = NewNode;
                NewNode->LeftNodeLink = TempNode;
                NewNode->RightNodeLink = NULL;
                NewNode->NodeData = Data;
            }
            status = NODE_OK;
        }
        
    }

    return status;
}

/**
 * @brief Inserts a new node after a specified position in a doubly linked list.
 *
 * This function takes a double pointer to the head of the linked list, the data to be inserted, and the position after which the new node should be inserted.
 *
 * @param NodeHead - Double pointer to the head of the linked list.
 * @param Data - Data to be stored in the new node.
 * @param position - Position after which the new node should be inserted.
 * @return NodeStatus_t - Status of the node insertion operation (NODE_OK, NODE_NOK, NODE_NULL_POINTER, or NODE_EMPTY).
 */
NodeStatus_t Insert_Node_After(struct Node **NodeHead, uint32_t Data, uint32_t position){
    NodeStatus_t status = NODE_NOK;
    uint32_t NodeLength = 1;
    uint32_t Tempposition = position;
    /* Check for NULL pointers in the input parameters */
    if((NULL == NodeHead) || (position == 0)){
        status = NODE_NULL_POINTER; // Set status as NODE_NULL_POINTER if any pointer is NULL
    }
    else{
        if(NULL == *NodeHead){ /* If the linked list is empty */
            status = NODE_EMPTY;
        }
        else{
            struct Node *TempNode = *NodeHead;
            while (NULL != TempNode->RightNodeLink)
            {
                TempNode = TempNode->RightNodeLink;
                NodeLength++;
            }

            if(position > NodeLength){
                status = NODE_NOK;
            }
            else{
                TempNode = *NodeHead;
                while (Tempposition > 1)
                {
                    TempNode = TempNode->RightNodeLink;
                    Tempposition--;
                }

                Node_t *NewNode = NULL;

                // Allocate memory for a new node
                NewNode = (Node_t *)malloc(sizeof(Node_t));

                if(NULL == NewNode){  // Check if memory allocation failed
                    status = NODE_NOK; // Set status as NODE_NOK if memory allocation failed
                }
                else{
                    NewNode->NodeData = Data;
                    NewNode->LeftNodeLink = TempNode;
                    NewNode->RightNodeLink = TempNode->RightNodeLink;
                    TempNode->RightNodeLink = NewNode;
                    if(NULL == NewNode->RightNodeLink){ /* check if the new node is the last node */
                        status = NODE_OK;
                    }
                    else{
                        (NewNode->RightNodeLink)->LeftNodeLink = NewNode;
                        status = NODE_OK;
                    }

                }

            }
        }

        
    }

    return status;
}

/**
 * @brief Inserts a new node before a specified position in a doubly linked list.
 *
 * This function takes a double pointer to the head of the linked list, the data to be inserted, and the position before which the new node should be inserted.
 *
 * @param NodeHead - Double pointer to the head of the linked list.
 * @param Data - Data to be stored in the new node.
 * @param position - Position before which the new node should be inserted.
 * @return NodeStatus_t - Status of the node insertion operation (NODE_OK, NODE_NOK, NODE_NULL_POINTER, or NODE_EMPTY).
 */
NodeStatus_t Insert_Node_Before(struct Node **NodeHead, uint32_t Data, uint32_t position){
    NodeStatus_t status = NODE_NOK;
    uint32_t NodeLength = 1;
    uint32_t Tempposition = position;

    /* Check for NULL pointers in the input parameters */
    if((NULL == NodeHead)||(0 == position)){
        status = NODE_NULL_POINTER; // Set status as NODE_NULL_POINTER if any pointer is NULL
    }
    else{
        if(NULL == *NodeHead){ /* If the linked list is empty */
            status = NODE_EMPTY;
        }
        else{
            struct Node *TempNode = *NodeHead;
            while (NULL != TempNode->RightNodeLink)
            {
                TempNode = TempNode->RightNodeLink;
                NodeLength++;
            }

            if(position > NodeLength){
                status = NODE_NOK;
            }
            else{
                TempNode = *NodeHead;

                while (Tempposition > 1)
                {
                    TempNode = TempNode->RightNodeLink;
                    Tempposition--;
                }

                Node_t *NewNode = NULL;

                // Allocate memory for a new node
                NewNode = (Node_t *)malloc(sizeof(Node_t));

                if(NULL == NewNode){  // Check if memory allocation failed
                    status = NODE_NOK; // Set status as NODE_NOK if memory allocation failed
                }
                else{
                    NewNode->NodeData = Data;
                    NewNode->RightNodeLink = TempNode;
            
                    if(NULL == TempNode->LeftNodeLink){ /* check if the tempNode is the first node */
                        *NodeHead = NewNode;
                        TempNode->LeftNodeLink = NewNode;
                        NewNode->LeftNodeLink = NULL;
                        status = NODE_OK;
                    }
                    else{
                        NewNode->LeftNodeLink = TempNode->LeftNodeLink;
                        (TempNode->LeftNodeLink)->RightNodeLink = NewNode;
                        TempNode->LeftNodeLink = NewNode;
                    }
                    status = NODE_OK;
                }
            }
        }
    }

    return status;
}

/**
 * @brief Deletes the node at the beginning of a doubly linked list.
 *
 * This function takes a double pointer to the head of the linked list and deletes the node at the beginning.
 *
 * @param NodeHead - Double pointer to the head of the linked list.
 * @return NodeStatus_t - Status of the node deletion operation (NODE_OK, NODE_NOK, NODE_NULL_POINTER, or NODE_EMPTY).
 */
NodeStatus_t Delete_Node_At_Beginning(struct Node **NodeHead){
    NodeStatus_t status = NODE_NOK;

    /* Check for NULL pointers in the input parameters */
    if(NULL == NodeHead){
        status = NODE_NULL_POINTER; // Set status as NODE_NULL_POINTER if any pointer is NULL
    }
    else{
        if(NULL == *NodeHead){ /* If the linked list is empty */
            status = NODE_EMPTY;
        }
        else{
            Node_t *TempNode = *NodeHead;
            *NodeHead = TempNode->RightNodeLink; /* Update the head node */
            if(NULL == TempNode->RightNodeLink){ /* check if Tempnode is the only node */
                free(TempNode);
            }
            else{
                (*NodeHead)->LeftNodeLink = NULL;
                TempNode->RightNodeLink = NULL;
                free(TempNode);
            }
            
            status = NODE_OK;
        }
    }

    return status;
}

/**
 * @brief Deletes the node at the end of a doubly linked list.
 *
 * This function takes a double pointer to the head of the linked list and deletes the node at the end.
 *
 * @param NodeHead - Double pointer to the head of the linked list.
 * @return NodeStatus_t - Status of the node deletion operation (NODE_OK, NODE_NOK, NODE_NULL_POINTER, or NODE_EMPTY).
 */
NodeStatus_t Delete_Node_At_End(struct Node **NodeHead){
    NodeStatus_t status = NODE_NOK;
    uint32_t NodeLength = 1;

    /* Check for NULL pointers in the input parameters */
    if(NULL == NodeHead){
        status = NODE_NULL_POINTER; // Set status as NODE_NULL_POINTER if any pointer is NULL
    }
    else{
        if(NULL == *NodeHead){ /* If the linked list is empty */
            status = NODE_EMPTY;
        }
        else{
            struct Node *TempNode = *NodeHead;

            while (NULL != TempNode->RightNodeLink)
            {
                TempNode = TempNode->RightNodeLink;
                NodeLength++;
            }

            if(NULL == TempNode->LeftNodeLink){  /* check if the tempNode is the first node */
                *NodeHead = NULL;
                TempNode->RightNodeLink = NULL;
                TempNode->LeftNodeLink = NULL;
                free(TempNode);
            }
            else{
                (TempNode->LeftNodeLink)->RightNodeLink = NULL;
                TempNode->LeftNodeLink = NULL;
                free(TempNode);
            }

            status = NODE_OK;
        }
    }

    return status;
}

/**
 * @brief Deletes a node at an intermediate position in a doubly linked list.
 *
 * This function takes a double pointer to the head of the linked list and the position of the node to be deleted.
 *
 * @param NodeHead - Double pointer to the head of the linked list.
 * @param position - Position of the node to be deleted.
 * @return NodeStatus_t - Status of the node deletion operation (NODE_OK, NODE_NOK, NODE_NULL_POINTER, or NODE_EMPTY).
 */
NodeStatus_t Delete_Node_At_Intermediate(struct Node **NodeHead, uint32_t position){
    NodeStatus_t status = NODE_NOK;
    uint32_t NodeLength = 1;
    uint32_t Tempposition = position;

    /* Check for NULL pointers in the input parameters */
    if(NULL == NodeHead){
        status = NODE_NULL_POINTER; // Set status as NODE_NULL_POINTER if any pointer is NULL
    }
    else{
        if(NULL == *NodeHead){ /* If the linked list is empty */
            status = NODE_EMPTY;
        }
        else{
            struct Node *TempNode = *NodeHead;

            while (NULL != TempNode->RightNodeLink)
            {
                TempNode = TempNode->RightNodeLink;
                NodeLength++;
            }

            if(position > NodeLength){
                status = NODE_NOK;
            }
            else{
                TempNode = *NodeHead;

                while (Tempposition > 1)
                {
                    TempNode = TempNode->RightNodeLink;
                    Tempposition--;
                }

                if((NULL == TempNode->LeftNodeLink)&&(NULL == TempNode->RightNodeLink)){ /* check if the tempNode is the only node*/
                    *NodeHead = TempNode->RightNodeLink;
                    free(TempNode);
                }
                else if(NULL == TempNode->LeftNodeLink){ /* check if the tempNode is the first node */
                    *NodeHead = TempNode->RightNodeLink;
                    (TempNode->RightNodeLink)->LeftNodeLink = NULL;
                    TempNode->RightNodeLink = NULL;
                    TempNode->LeftNodeLink = NULL;
                    free(TempNode);
                }
                else if (NULL == TempNode->RightNodeLink){  /* check if the tempNode is the last node */
                    (TempNode->LeftNodeLink)->RightNodeLink = TempNode->RightNodeLink;
                    TempNode->LeftNodeLink = NULL;
                    TempNode->RightNodeLink = NULL;
                    free(TempNode);
                }
                else{
                    (TempNode->LeftNodeLink)->RightNodeLink = TempNode->RightNodeLink;
                    (TempNode->RightNodeLink)->LeftNodeLink = TempNode->LeftNodeLink;
                    TempNode->LeftNodeLink = NULL;
                    TempNode->RightNodeLink = NULL;
                    free(TempNode);
                }
                
                status = NODE_OK;
            }
        }
    }

    return status;
}

/**
 * @brief Displays all nodes in forward order in a doubly linked list.
 *
 * This function takes the head of the linked list and prints the data of all nodes in forward order.
 *
 * @param NodeHead - Pointer to the head of the linked list.
 * @return NodeStatus_t - Status of the node display operation (NODE_OK, NODE_NOK, or NODE_NULL_POINTER).
 */
NodeStatus_t Display_All_Nodes_Forward(struct Node *NodeHead){
    NodeStatus_t status = NODE_NOK;

    /* Check for NULL pointers in the input parameters */
    if(NULL == NodeHead){
        status = NODE_NULL_POINTER; // Set status as NODE_NULL_POINTER if any pointer is NULL
    }
    else{
        struct Node *TempNode = NodeHead;

        printf("\nTraversal in forward direction ==> ");
        printf("Data : ");
        printf("%d -> ", TempNode->NodeData);
        while(TempNode->RightNodeLink){
            TempNode = TempNode->RightNodeLink;
            printf("%d -> ", TempNode->NodeData);
        }
        if(NULL == TempNode->RightNodeLink){
            printf("NULL");
        }
        printf("\n");
    }

    return status;
}

/**
 * @brief Displays all nodes in reverse order in a doubly linked list.
 *
 * This function takes the head of the linked list and prints the data of all nodes in reverse order.
 *
 * @param NodeHead - Pointer to the head of the linked list.
 * @return NodeStatus_t - Status of the node display operation (NODE_OK, NODE_NOK, or NODE_NULL_POINTER).
 */
NodeStatus_t Display_All_Nodes_Reverse(struct Node *NodeHead){
    NodeStatus_t status = NODE_NOK;

    /* Check for NULL pointers in the input parameters */
    if(NULL == NodeHead){
        status = NODE_NULL_POINTER; // Set status as NODE_NULL_POINTER if any pointer is NULL
    }
    else{
        struct Node *TempNode = NodeHead;

        printf("\nTraversal in reverse direction ==> ");
        printf("Data : ");
        while(TempNode->RightNodeLink != NULL){
            TempNode = TempNode->RightNodeLink;
        }
        while(TempNode != NULL){
            printf("%d -> ", TempNode->NodeData);
            TempNode = TempNode->LeftNodeLink;
        }
        if(NULL == TempNode){
            printf("NULL");
        }
        printf("\n");
    }

    return status;
}
