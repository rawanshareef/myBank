#include<stdio.h>
#include <stdbool.h>
#include "myBank.h"
char choice=' ';

int main(){
    
       do{
          printf("\n Please choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n ");

         if(scanf(" %c", &choice)!=1) {
         printf("Faild to read the transaction type\n");  
        }

           switch (choice)
           {
           case 'O':
           {
              double amount2=0;
              printf("Please enter amount for deposit:");
              if(scanf("%lf",&amount2)==1)
              {
                  if(amount2<0)
                   {
                   printf("Invalid amount \n");
            
                   }
                   else
                   {
                     OpenNewAccount(amount2);
                    } 
               } 
               else
               {
                 printf("Failed to read the amount\n"); 
               }
     
            }   
          break;

           case 'B':
             {
              int account_number=0;
              printf("Please enter account number:");
              scanf("%d",&account_number);
              if(account_number<0||(account_number<901&&account_number>950))
              {
                 printf("Invalid account number");
              }
              CheckAccount(account_number);
             }

           break;


           case 'D':
           {
             int account_number=0;
             double amount=0;
             printf("Please enter account number:");
             if(scanf("%d", &account_number)!=1)
             {
                 printf("Failed to read the account number\n"); 
                 break;
             }

             printf("Please enter amount for deposit:");
             if((scanf("%lf",&amount)==1))
             {
                  if(amount<0)
                  {
                      printf("Cannot deposit a negative amount\n");
                  }
             }   
             else
             {
                 printf("Failed to read the amount\n"); 
                 break;
             } 
               
           deposit(account_number,amount);
           }  
           break;

           case 'W':
           {
             int account_number=0;
             double amount=0;
            printf("Please enter account number:");
            if(scanf("%d", &account_number)!=1)
             {
                printf("Failed to read the account number\n"); 
                break;
             }
             printf("Please enter amount to withdraw:");
             if((scanf("%lf",&amount)!=1))
                {
                 printf("Failed to read the amount\n"); 
                 break;
               }
           else
            {
               CashWithdrawal(account_number,amount);
            }
           }

           break;

           case 'C':
           {
            int account_number=0;
            printf(" Please enter account number:");
            if(scanf("%d",&account_number)==1)
            {
              AccountClosing(account_number);
            }
          else{
              printf("Faild to read the account number\n");
              }
            }
            break;




             case 'I':
             {
                double insert_rate=0;
                printf("Please enter interest rate");
                if(scanf("%lf", &insert_rate)==1)
                {
                   if(insert_rate<0)
                   {
                    printf("Invalid interest rate:");
                   }
                  AddInterest(insert_rate);
                  break;;
               }
             printf("Faild to read the interest rate");
              }
             break;

             case 'P':
             {
                 PrintAll();
             }
             break;

             case 'E':
             CloseAllAccountes();
             break;
             default:
             printf("Invalid transaction type");
             }
             }   
        while(choice!='E');
 return 0;
}


