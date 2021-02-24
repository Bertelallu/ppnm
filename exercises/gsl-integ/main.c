#include<math.h>
#include<stdio.h>
#include <gsl/gsl_integration.h>

double expression(double x, void * parameters){
	double result=log(x)/sqrt(x);
	return result;
	}
double integral(){
	gsl_function F;
	F.function=&expression;
	double a=0,b=1,acc=1e-4,eps=1e-4,result,error;
	int limit=200;
	gsl_integration_workspace* elbowspace=gsl_integration_workspace_alloc(limit);
	gsl_integration_qags(&F, a, b, acc, eps, limit, elbowspace, &result, &error);
	gsl_integration_workspace_free(elbowspace);
	return result;
	}

int main(){
	printf("integral is equal to %g\n",integral());
return 0;}
