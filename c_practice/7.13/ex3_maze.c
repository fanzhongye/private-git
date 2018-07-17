#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20   /*最大列数*/
#define M 20   /*最大行数*/

int maze[N][M];
typedef struct  {
   int row;
   int col;
}Position;

typedef struct {
   Position coordinate;
   int top;
}route_Stack;

void initStack(route_Stack *rs)/*初始化栈*/
{
   rs->top = -1;
}

int checkEmpty(route_Stack *rs)/*检查栈是否为空*/
{
   return (rs->top == -1 ? 1 : 0);
}
/*入栈操作*/
int push(route_Stack *rs, int data)
{
   
}

void manual_maze(int m,int n)
{
   int i, j;
   printf("input the maze,0 or 1:\n");
   for (i = 0; i < m ; i++)
   {
      for (j = 0; j < n;j++)
      {
         scanf("%d", &maze[i][j]);
      }
   }
}

void auto_maze(int m,int n)
{
   int i, j;
   int num = m * n/2;
   srand((unsigned) time(NULL));
   for (i = 0; i < m;i++)
   {
      for (j = 0; j < n;j++)
      {
         if(num>0)
         {
            maze[i][j] = rand() % 2;
            if(1==maze[i][j])
            {
               num--;
            }
         }
         else
         {
            maze[i][j] = 0;
         }
      }
   }
}

void print_maze(int m,int n)
{
   int i, j;
   printf("\nprint the maze:\n");
   for (i = 0; i < m;i++)
   {
      printf("\n");
      for (j = 0; j < n;j++)
      {
         if (maze[i][j]==0)
            printf("0  ");
         if (maze[i][j]==1)
            printf("1  ");
      }
   }
   printf("\n");
}


void entrance_and_exit(int m,int n,int *start,int *end)
{
   int i, j;
   printf("\nset entrance and exit:\n");
   for (i = 0; i < m;i++)
   {
      printf("\n");
      for (j = 0; j < n;j++)
      {
         if ((i==(start[0]-1)&&j==(start[1]-1))||(i==(end[0]-1)&&j==(end[1]-1)))
            printf("*  ");
         else if (maze[i][j]==0)
            printf("0  ");
         else if (maze[i][j]==1)
            printf("1  ");
      }
   }
   printf("\n");
}

void maze_route(int m,int n,int *start,int *end)
{

}

int main()
{
   int n = 0;
   int m = 0;
   int start[2] = {0, 0};
   int end[2] = {0, 0};
   int choose = 0;
   /*自定义迷宫大小*/
   printf("input the number of row:\n");
   scanf("%d", &m);
   while( (m>M) || (m<=0))
   {
      printf("input the number of row(within 1-20):\n");
      scanf("%d", &m);
   }
   printf("input the number of col:\n");
   scanf("%d", &n);
   while( (n>N) || (n<=0))
   {
      printf("input the number of col(within 1-20):\n");
      scanf("%d", &n);
   }
   /*选择迷宫生成方式*/
   printf("choose the way of getting maze\n1. create the maze manually\n2. create the maze automatically\n");
   scanf("%d", &choose);
   if (1==choose)
   {
      manual_maze(m, n);
   }
   if (2==choose)
   {
      auto_maze(m, n);
   }
   print_maze(m, n);
   /*设置迷宫起点，终点*/
   printf("input the entrance of maze(range from (1 1) to (%d %d) :\n",m,n);
   scanf("%d%d",&start[0],&start[1]);
   printf("input the exit of maze(range from (1 1) to (%d %d) :\n",m,n);
   scanf("%d%d", &end[0],&end[1]);
   entrance_and_exit(m, n,start,end);

   /*计算路径*/
   //maze_route();
   //system("pause");
   return 0;
}

