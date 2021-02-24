#include<stdio.h>
#include<math.h>
#include <gsl/gsl_integration.h>

double expression(double x, void * params){
	double result=2/sqrt(M_PI)*exp(-pow(x,2));
	return result;
}

double errorfunction(double z){
	gsl_function F;
	F.function=&expression;
	double b=z;
	double a=0,acc=1e-4,eps=1e-4,result,error;
	int limit=200;
	gsl_integration_workspace* elbowspace=gsl_integration_workspace_alloc(limit);
	gsl_integration_qags(&F, a, b, acc, eps, limit, elbowspace, &result, &error);
	gsl_integration_workspace_free(elbowspace);
	return result;
	}

int main(){
	for(double z=-3.0;z<=3.0;z+=1.0/8){
		printf("%10g %10g\n",z,errorfunction(z));
	}
return 0;
}
