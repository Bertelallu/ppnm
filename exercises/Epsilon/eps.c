#include<stdio.h>
#include<limits.h>
#include<float.h>
#include<stdlib.h>

void maximum(void){
	int i=1; while(i+1>i){
		i++;
		}
	printf("my max int = %i\n",i);

	for(i=1;i+1>i;)
		{
		i++;
		}
	printf("my max int = %i\n",i);

	i=1; do
		{
		i++;
		}while(i+1>i);
	printf("my max int = %i\n",i);
	double imax=INT_MAX;
	printf("But INT_MAX=%g\n",imax);
}

void minimum(void){
	int i=0; while(i-1<i){
		i=i-1;
		}
	printf("my min int = %i\n",i);

	for(i=0;i-1<i;)
		{
		i=i-1;
		}
	printf("my min int = %i\n",i);

	i=0; do
		{
		i=i-1;
		}while(i-1<i);
	printf("my min int = %i\n",i);
	double imin=INT_MIN;
	printf("But INT_MIN=%g\n",imin);
	}

void difference(void){

	printf("while loops\n");
	float x=1; while(1+x!=1){x/=2;} x*=2;
	printf("machine epsilon float=%g\n",x);
	printf("from header float= %g\n",FLT_EPSILON);
	double e=1; while(1+e!=1){e/=2;} e*=2;
	printf("machine epsilon double=%g\n",e);
	printf("from header double= %g\n",DBL_EPSILON);
	long double p; p=1; while(1+p!=1){p/=2;} p*=2;
	printf("machine epsilon long double=%Lg\n",p);
	printf("from header long double= %Lg\n",LDBL_EPSILON);

	printf("for loops\n");
	float y; for(y=1; 1+y!=1; y/=2){} y*=2;
	printf("machine epsilon float=%g\n",y);
	printf("from header float= %g\n",FLT_EPSILON);
	double f; for(f=1; 1+f!=1; f/=2){} f*=2;
	printf("machine epsilon double=%g\n",f);
	printf("from header double= %g\n",DBL_EPSILON);
	long double q; for(q=1; 1+q!=1; q/=2){} q*=2;
	printf("machine epsilon long double=%Lg\n",q);
	printf("from header long double= %Lg\n",LDBL_EPSILON);

	printf("do loops\n");
	float z=2; do{z/=2;}while(1+z!=1); z*=2;
	printf("machine epsilon float=%g\n",z);
	printf("from header float= %g\n",FLT_EPSILON);
	double g=2; do{g/=2;}while(1+g!=1); g*=2;
	printf("machine epsilon double=%g\n",g);
	printf("from header double= %g\n",DBL_EPSILON);
	long double r=2; do{r/=2;}while(1+r!=1); r*=2;
	printf("machine epsilon long double=%Lg\n",r);
	printf("from header long double= %Lg\n",LDBL_EPSILON);
	}

void intmaxfloat(){
	printf("floats\n");
	int max=INT_MAX/4; int n;
	float sum_up_float=0;
	for(n=1; n<=max;n++) {sum_up_float+=1.0f/n;}
	printf("Bottom up sum=%g\n",sum_up_float);

	float sum_down_float=0;
	for(n=max; n>0;n=n-1){
	sum_down_float+=1.0f/n;
	}
	printf("top down sum=%g\n",sum_down_float);
}

void intmaxdouble(){
	printf("doubles\n");
	int max=INT_MAX/4; int n;
	double sum_up_double=0;
	for(n=1; n<=max;n++) {
	sum_up_double+=1.0/n;
	}
	printf("Bottom up sum=%g\n",sum_up_double);

	double sum_down_double=0;
	for(n=max; n>0;n=n-1){
	sum_down_double+=1.0/n;
	}
	printf("top down sum=%g\n",sum_down_double);
}
int equal(double,double,double,double);

int main(void){
//	maximum();
//	minimum();
//	difference();
//	intmaxfloat();
//	intmaxdouble();
	printf("%d\n",equal(10,11,1,2));
return 0;
}

