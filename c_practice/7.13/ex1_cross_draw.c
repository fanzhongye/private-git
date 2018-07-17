#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.14
void map_angle( int angle)
{
   int a = 0;
   if (tan((angle-33)*PI/180)>=0)
      a=tan((angle-33)*PI/180)*3/2;
   else
      a=(-tan((angle-33)*PI/180))*3/2;
   while (a>0)
   {
      printf(" ");
      a--;
   }
}

void draw(int length , int angle)
{
   int row = 0;
	int col = 0;
	for (row =1;row<=(2*length);row++)
	{
      for (int i=row; i <= length;i++)
         {
            map_angle(angle);
         }
	   for (col=1;col<=3*length-row-1;col=col+1)
	    {
	      if (col==row-length)
	        {
	            printf("*");
               map_angle(angle);
           }
         else if (col<row-length)
         {
            printf(" ");
         }
         else
         {
            
            printf(" ");
            map_angle(angle);
            
         }  
	    }
	   printf("*\n");
	}
}

int main()
{
   int length;
   int angle=0;
   printf("input the length of short side:\n");
   scanf("%d", &length);

   printf("input the angle(larger than 60) :\n");
   scanf("%d", &angle);
   while (angle<=60)
   {
      printf("input the angle again(larger than 60) :\n");
      scanf("%d", &angle);
   }
   
   draw(length, angle);
   system("pause");
   return 0;
}