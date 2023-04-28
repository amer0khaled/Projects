
#ifndef bank_H
#define bank_H

typedef struct customer
{
    char name[50];
    double cash ;
    char type[7] ;
    int id ;
} customer ;

#define NUMBER_OF_CUSTOMERS 3

void CREATE_NEW_CUSTOMER(void) ;
void  EDIT_CUSTOMER(int id ) ;
void PRINT_CUSTOMER_INFORMATION(int search_id) ;
void TRANSFER_MONEY(int sender_id, int receiver_id, double transfer_cash );
void DELETE_ACCOUNT(int delete_id);
#endif
