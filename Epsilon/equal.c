#include<stdio.h>
#include<stdlib.h>

int equal(double a,double b,double t,double e)
	{
	if(abs(a-b)<t){return 1;}
	if(abs(a-b)/(abs(a)+abs(b))<e/2){return 1;}
	else{return 0;}
	}
