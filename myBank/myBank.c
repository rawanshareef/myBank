#include <stdio.h>
#include <stdbool.h>
#include "myBank.h"
#define open 1
#define close 0
#define first 901
#define ROWS 50
#define COLS 2

double accounts[ROWS][COLS]= {{0},{0}};

 void OpenNewAccount(double amount)
 {
     bool flag=false;
     for(int i=0;i<ROWS;i++)
     {
        if(accounts[i][0]==close)
        {
             flag=true;
             accounts[i][0]=open;
             accounts[i][1]=amount;
             printf("New account number is: %d",i+first);
             return;
         }
     }
     if(flag==false){
     printf("Invalid account number");
     }
 }





 void CheckAccount(int account_number)
 {
     int x=account_number-first;
     if(x>=0&&x<50)
     {
         if(accounts[x][0]==open)
         {
             printf("The balance of account %d is: %.2f",account_number,accounts[x][1]);
             return;
         }
         else
         {
           printf("The account is closed\n");  
           return;
         }
     } 
     printf("Faild to read the account number\n");
 }



void deposit(int account_number,double amount)
{
   int s=account_number-first;
    if(s>=0&&s<50)
    {
      if(accounts[s][0]==open)
      {
        double y=accounts[s][1]+amount;
        accounts[s][1]=y;
        printf("The new balance is: %.2f",accounts[s][1]);
        return;
      }
      printf("This account is closed");  
      return;
     }
    printf("Invalid account number");
}



void CashWithdrawal(int account_number,double amount){
       int z=account_number-first;
        if(z>=0&&z<50)
        {
         if(accounts[z][0]==open&&accounts[z][1]>=amount)
         {
             double newbalance=accounts[z][1]-amount;
             accounts[z][1]=newbalance;
             printf("The balance is:%.2f",accounts[z][1]);
             return;
        }
        if(accounts[z][0]==close){
           printf("This account is closed");  
           return;
        }
        if(accounts[z][1]<=amount){
          printf("Cannot withdraw more than the balance");  
           return;  
        }   
     }
         printf("Invalid account number");
}


void AccountClosing(int account_number)
{
       int f=account_number-first;
     if(f>=0&&f<50)
     {
         if(accounts[f][0]==open)
         {
             accounts[f][0]=close;
             accounts[f][1]=0.0;
        printf("Closed account number %d",account_number);
        return;
         }
         else{
           printf("The account number is already closed");    
           return;
         }
     }
     printf("Invalid account number");
}


void AddInterest(double insert_rate)
{
    for(int i=0;i<50;i++)
     {
        if(accounts[i][0]==open)
        {
            accounts[i][1]+=  accounts[i][1]*((double)insert_rate/100);
        }
     }
}




void PrintAll()
{
    for(int i=0;i<50;i++)
    {
        if(accounts[i][0]==open)
        {
            printf("The balance of account number %d is:%.2f\n",first+i,accounts[i][1]);
        }
    }
} 


void CloseAllAccountes(){
    for(int i=0;i<50;i++){
        accounts[i][0]=close;
        accounts[i][0]=0.0;
    }
printf("All the accounts are closed");
}
