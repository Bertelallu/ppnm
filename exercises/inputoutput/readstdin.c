#include<stdio.h>
#include<math.h>
int main(){
	double x;
	int items;
	while(items=fscanf(stdin,"%lg",&x)!=EOF){
		printf("x=%g sin(x)=%g cos(x)=%g\n",x,sin(x),cos(x));
	}
return 0;
}
