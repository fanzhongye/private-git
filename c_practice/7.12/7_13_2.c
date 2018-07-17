#define PI 3.14
#include <stdio.h>
int main(void) { 
	float v = 0.0;
	int r =0;
	int r_numerator = 0;
	int r_denominator =0;
	scanf("%d",&r_numerator);
	scanf("%d",&r_denominator);
	if (0==r_denominator)
	{
	    printf(" denominator is 0,fail");
	}
	else
	{
	    r = r_numerator/r_denominator;
	    v = PI*r*r*r*4.0/3.0;
	    printf("the radius is %d m\n", r);
	    printf("the volume is %f m^3", v);
	}
	return 0;
}