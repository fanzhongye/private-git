#include <stdio.h>
int main(void)
{
   int row = 0;
	int col = 0;
	for (row = 1;row<=6;row++)
	{
	    for (col=1;col<=8-row;col++)
	    {
	      if (col==row-3)
	        {
	            printf("*");
	        }
	        else 
	        {
	            printf(" ");
	        }
	    }
	   printf("*\n");
	}
    return 0;	
}