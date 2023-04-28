#include<stdio.h>
#include<stdlib.h>
#include"bank.h"

int counter;

customer arr[NUMBER_OF_CUSTOMERS];

int main()
{
    char choice;
    int search_id;
    int sender_id;
    int delete_id;
    int receiver_id;
    double transfer_cash;


    while (1)
    {
        printf("\n\nSelect One Of These Choices:\n\n");

        printf("1- Create New Customer (For This Choice Enter 1)\n");
        printf("2- Edit Customer Account (For This Choice Enter 2)\n");
        printf("3- Print Customer Information (For This Choice Enter 3)\n");
        printf("4- Transfer Money From Customer To Customer (For This Choice Enter 4)\n");
        printf("5- Delete Customer Account (For This Choice Enter 5)\n");
        printf("Select Your Choice : ");
        scanf("%i",&choice);
        printf("\n");

        switch(choice)
        {
        case 1:
            if((counter > NUMBER_OF_CUSTOMERS-1)&&(arr[NUMBER_OF_CUSTOMERS-1].id == -1))
            {
                CREATE_NEW_CUSTOMER();
            }
            else if(counter > NUMBER_OF_CUSTOMERS-1)
            {
                printf("The Maximum Number Of Customer Is %i So You Can't Add Anymore",NUMBER_OF_CUSTOMERS);

            }
            else
            {
                CREATE_NEW_CUSTOMER();
            }
            break;


        case 2:

            printf("Enter The ID Of The Customer : ");
            scanf("%i",&search_id);

            EDIT_CUSTOMER(search_id);
            break;

        case 3:

            printf("Enter The ID Of The Customer : ");
            scanf("%i",&search_id);

            PRINT_CUSTOMER_INFORMATION(search_id);
            break;

        case 4:
            printf("Enter The ID Of The Sender Customer : ");
            scanf("%i",&sender_id);

            printf("\n");

            printf("Enter The ID Of The Receiver Customer : ");
            scanf("%i",&receiver_id);

            printf("\n");

            printf("Enter The Cash You Want To Send : ");
            scanf("%lf",&transfer_cash);

            TRANSFER_MONEY(sender_id, receiver_id, transfer_cash);
            break;

        case 5:
            printf("Enter The ID Of The Account You Want To Delete : ");
            scanf("%i",&delete_id);
            DELETE_ACCOUNT(delete_id);
            break;


        }

    }



    return 0;
}
