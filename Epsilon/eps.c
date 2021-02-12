#include<stdio.h>
#include<limits.h>
#include<float.h>
void max(void){
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

void min(void){
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
double x=1; while(1+x!=1){x/=2;} x*=2;
}

int main(void){
//	max();
//	min();
	difference();
return 0;
}

