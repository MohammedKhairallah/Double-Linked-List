/*
 * File:   Application.c
 * Author: Mohammed Khairallah
 * linkedin : linkedin.com/in/mohammed-khairallah
 * Created on January 8, 2024, 10:364 PM
 */

#include "Application.h"

int main()
{
    printf("please wait");
    while (displaycount < 5)
    {
        printf(".");
        Sleep(250); // Delay for 250 milliseconds (for Windows)
        displaycount++;
    }
    puts("\nHello to Single Linked List \n");

    // Infinite loop for menu-driven operations
    while (1)
    {   
        instructions();           // Display menu of options
        scanf("%i", &UserChoice); // Get user choice
        printf("\n");

        switch (UserChoice)
        { // Perform operations based on user choice
        case 1:
            printf("please enter the data : ");
            scanf("%i", &data1);
            printf("\n");
            Insert_Node_At_Beginning(&NodeHead_1, data1);
            break;
        case 2:
            printf("please enter the data : ");
            scanf("%i", &data1);
            printf("\n");
            Insert_Node_At_End(&NodeHead_1, data1);
            break;
        case 3:
            printf("please enter the data : ");
            scanf("%i", &data1);
            printf("\n");
            puts("Note : The first postion = 1 \n"
                "please enter postion of the node :  ");
            scanf("%i", &NodePos);
            printf("\n");
            Insert_Node_After(&NodeHead_1, data1, NodePos);
            break;
        case 4:
            printf("please enter the data : ");
            scanf("%i", &data1);
            printf("\n");
            puts("Note : The first postion = 1 \n"
                "please enter postion of the node :  ");
            scanf("%i", &NodePos);
            printf("\n");
            Insert_Node_Before(&NodeHead_1, data1, NodePos);
            break;
        case 5:
            Delete_Node_At_Beginning(&NodeHead_1);
            break;
        case 6:
            Delete_Node_At_End(&NodeHead_1);
            break;
        case 7:
            puts("Note : The first postion = 1 \n"
                "please enter postion of the node :  ");
            scanf("%i", &NodePos);
            printf("\n");
            Delete_Node_At_Intermediate(&NodeHead_1, NodePos);
            break;
        case 8:
            Display_All_Nodes_Forward(NodeHead_1);
            printf("\n");
            break;
        case 9:
            Display_All_Nodes_Reverse(NodeHead_1);
            printf("\n");
            break;
        case 10:
            printf("Quit from application \n\n");
            exit(1); // Exit the application
            break;
        default:
            printf("User Choice out of range !!\n\n");
            break;
        }
    }
    return 0;
}

/* Function to Displays a menu of available options to the user */
void instructions(void)
{
    puts("Enter your choice:\n"
        " 1 to insert an element at the beginning of the linked list.\n"
        " 2 to insert an element at the end of the linked list.\n"
        " 3 to insert an element after a specific position in a linked list.\n"
        " 4 to insert an element before a specific position in a linked list.\n"
        " 5 to delete node from the beginning.\n"
        " 6 to delete node from the End.\n"
        " 7 to delete node from a specific position.\n"
        " 8 to Display all nodes Forward.\n"
        " 9 to Display all nodes Reverse.\n"
        " 10 to end.");
    printf("UserChoice : ");
}