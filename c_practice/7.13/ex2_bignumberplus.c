#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define Char(X) (X + '0')
#define Int(X) (X - '0')
int checkNum(char *num)
{
    int i;
    for(i = 0; i < strlen(num); i++)
    {
        if(num[i] < '0' || num[i] > '9'||num[0]=='0'||num[0]=='-')
        {
            return 1;
        }
    }
    return 0;
}


char *bignumberplus(char *num_1,char *num_2)
{  int k = 0;
   char *result=NULL;
   int result_len=0;
   char *temp = NULL;
   int temp_len = 0;
   int value = 0;
   int carry = 0;
   int remain = 0;
   int offset = 0;
   int add_carry = 0;
   int add_value = 0;
   result_len = strlen(num_1) + strlen(num_2) - 1;
   temp = (char *)malloc((result_len+2)*sizeof(char));
   result = (char *)malloc((result_len+2)*sizeof(char));
   memset(result, '0', (result_len+1)*sizeof(char));
   
   for (int j = strlen(num_2)-1; j >=0 ; j--)
   {
      
      temp_len = strlen(num_1) + strlen(num_2) - 1;
      memset(temp, '0', (temp_len + 1) * sizeof(char));
      for (int i = strlen(num_1)-1; i >=0 ; i--)
      {
         value = Int(num_1[i]) * Int(num_2[j])+carry;
         carry = value / 10;
         remain = value % 10;
         temp[(temp_len--)-offset] = Char(remain);
         
      }
      temp[temp_len-offset] = Char(carry);
      offset++;
      carry = 0;

     // printf("%s\n",temp);

      for(k = result_len; k >= 0; k--)
      {
         add_value = Int(temp[k]) + Int(result[k]) + add_carry;
         add_carry = add_value/ 10;
         result[k] = Char(add_value % 10);
      }
      
   }
      if (result[0]=='0')
      {
         result[0] = ' ';
      }
      printf("result: %s\n\n", result);
      free(temp);
      free(result);
      return result;
}

int main()
{
   char num_1[100];
   char num_2[100];
   char *result=NULL;
   while(1)
   {
      printf("*************Start the game***************\n");
      printf("Input big number 1 :");
      scanf("%s", num_1);
      printf("Input big number 2 :");
      scanf("%s", num_2);
      if(strlen(num_1) > 50 || strlen(num_2) > 50)
           {
               printf("Out of range,no more than 50 figures\n\n");
           }
           if(checkNum(num_1) || checkNum(num_2))
           {
               printf("ERROR: input must be an positive integer,and start without 0 \n\n");
           }
      else
      {
         printf("\nnumber 1 :%s\nnumber 2 :%s\n", num_1, num_2);
         result = bignumberplus(num_1, num_2);
      }
   }
   system("pause");
   return 0;
}
