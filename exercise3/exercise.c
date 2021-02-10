#include<math.h>
#include<complex.h>
#include<stdio.h>

int main(void){
	double inp1=5;
	double inp2=0.5;
	double inp3=-2;
	double ans1=lgamma(inp1);
	printf("Gamma(%g)=%g\n",inp1,ans1);
	double ans2=j1(inp2);
	printf("Bessel(%g)=%g\n",inp2,ans2);
	complex ans3=csqrt(inp3);
	printf("sqrt(%g)=%g +i%g\n",inp3,creal(ans3),cimag(ans3));
	complex ans4=cexp(I*M_PI);
	printf("exp(iπ)=%g + i%g\n",creal(ans4),cimag(ans4));
	complex ans5=cexp(I);
	printf("exp(i)=%g + i%g\n",creal(ans5),cimag(ans5));
	complex ans6=cpow(I,M_E);
	printf("i^e=%g +i%g\n",creal(ans6),cimag(ans6));
	complex ans7=cpow(I,I);
	printf("i^i=%g +i%g\n",creal(ans7),cimag(ans7));
	float x_float = 1.f/9;
	double x_double = 1./9;
	long double x_long_double = 1.L/9;
	printf("float=%.25g\ndouble=%.25lg\nlong double=%.25Lg\n",x_float,x_double,x_long_double);
return 0;
}
