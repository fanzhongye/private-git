#include <stdio.h>
#define power_5(x) ((x)*(x)*(x)*(x)*(x))
#define power_4(x) ((x)*(x)*(x)*(x))
#define power_3(x) ((x)*(x)*(x))
#define power_2(x) ((x)*(x))
#define power_1(x) (x)

int func(int x);
int main(void) { 
	int x = 0;
	scanf("%d",&x);
	printf ("%d",func(x));
	return 0;
}

int func (int x)
{
    int y = 0;
    y = 3*power_5(x) +2*power_4(x) -5*power_3(x) -power_2(x) + 7*power_1(x) -6;
    return y;
}