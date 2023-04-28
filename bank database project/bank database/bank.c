
#include<stdio.h>
#include<stdlib.h>
#include"bank.h"

extern int counter;
extern customer arr[NUMBER_OF_CUSTOMERS];

void CREATE_NEW_CUSTOMER()
{
    customer new_customer;

    printf("Enter The Name Of The Customer Number %i : ",counter+1);
    fflush(stdin);
    gets(arr[counter].name);

    printf("\n");

    printf("Enter The ID Of The Customer Number %i : ",counter+1);
    scanf("%i",&(arr[counter].id));

    printf("\n");

    printf("Enter The Type Of The Customer Account Number %i  (debit or credit): ",counter+1);
    fflush(stdin);
    gets(arr[counter].type);
    fflush(stdin);

    printf("\n");

label :
    printf("Enter The Cash Of The Customer Number %i : ",counter+1);
    scanf("%lf",&(arr[counter].cash));

    if(arr[counter].cash < 0)
    {
        printf("Not Valid Cash\n\n");
        goto label;
    }

    printf("\n\n");

    counter++;

}


void EDIT_CUSTOMER(int search_id)
{
    int i;
    int flag=0;

    for(i=0; i <= counter; i++)
    {
        if(arr[i].id == search_id)
        {
            counter=i;
            CREATE_NEW_CUSTOMER();

        }
        else
        {
            flag++;
        }
    }

    if(flag == counter+1)
    {
        flag = 0;
        printf("Wrong ID , Please Make Sure And Try Again...\n\n");
    }

}


void PRINT_CUSTOMER_INFORMATION(int search_id)
{
    int i,flag=0;

    for(i=0; i <= counter; i++)
    {
        if(arr[i].id == search_id)
        {
            printf("The Name Of The Customer Number %i : %s",i+1,arr[i].name);
            printf("\n");

            printf("The ID Of The Customer Number %i : %i",i+1,arr[i].id);
            printf("\n");

            printf("The Type Of The Customer Account Number %i  (debit or credit): %s",i+1,arr[i].type);
            printf("\n");

            printf("The Cash Of The Customer Number %i : %lf",i+1,arr[i].cash);
            printf("\n");

        }
        else
        {
            flag++;
        }

    }

    if(flag == counter+1)
    {
        flag = 0;
        printf("Wrong ID , Please Make Sure And Try Again...\n\n");
    }

}


void TRANSFER_MONEY(int sender_id, int receiver_id, double transfer_cash )
{
    int i;
    int flag_money=0;
    int sender_flag=0;
    int receiver_flag=0;
    int index_sender;
    int index_receiver;

    for(i=0; i<= counter; i++)
    {
        if(sender_id == arr[i].id)
        {
            index_sender=i;
            sender_flag++;
        }

        if(receiver_id == arr[i].id)
        {
            index_receiver=i;
            receiver_flag++;
        }
    }


    if((sender_flag!=0)&&(receiver_flag!=0))
    {
        if(transfer_cash <= arr[index_sender].cash)
        {
            arr[index_sender].cash = arr[index_sender].cash - transfer_cash;
            arr[index_receiver].cash = arr[index_receiver].cash + transfer_cash;
        }
        else
        {
            printf("The Sender Have Only %lf ,So The Transfer Process Can't Be Done",arr[index_sender].cash);
        }

    }
    else if((receiver_flag == 0)&&(sender_flag != 0))
    {
        printf("The ID Of The Receiver Is Wrong...Make Sure And Try Again\n\n");
    }
    else if((sender_flag == 0)&&(receiver_flag != 0))
    {
        printf("The ID Of The Sender Is Wrong...Make Sure And Try Again\n\n");
    }
    else if((receiver_flag == 0)&&(sender_flag == 0))
    {
        printf("The ID Of The Sender Is Wrong...Make Sure And Try Again\n");
        printf("The ID Of The Receiver Is Wrong...Make Sure And Try Again\n");
    }


}

void DELETE_ACCOUNT(int delete_id)
{
    int i,j,flag=0;
    int k;

    for(i=0; i<= counter; i++)
    {
        if(delete_id == arr[i].id)
        {
            arr[i].id = -1;

            for(j=i+1,k=0; j <= counter; j++,k++)
            {
                arr[i+k] = arr[j];
            }
        }
        else
        {
            flag++;
        }
    }

    if(flag == counter+1)
    {
        flag = 0;
        printf("Wrong ID , Please Make Sure And Try Again");
    }
    else
    {
        counter--;
    }


}



