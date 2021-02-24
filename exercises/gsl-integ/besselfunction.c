#include<math.h>
#include <gsl/gsl_integration.h>
#include<stdio.h>

typedef struct {double n; double x;} nogx;

double expression(double t, void * p){
		nogx parameters=*(nogx*)p;
		int n=parameters.n;
		double x=parameters.x;
		double result=1/M_PI*cos(n*x-x*sin(t));
        return result;
	}

double integral(nogx params){
	gsl_function F;
	F.function=&expression;
	F.params=(void*)&params;
	double a=0,b=M_PI,acc=1e-4,eps=1e-4,result,error;
	int limit=200;
	gsl_integration_workspace* elbowspace=gsl_integration_workspace_alloc(limit);
	gsl_integration_qags(&F, a, b, acc, eps, limit, elbowspace, &result, &error);
	gsl_integration_workspace_free(elbowspace);
	return result;
	}

int main(){
		nogx parameters;
		for(double x=0.0;x<=10;x+=1.0/8){
			parameters.x=x;
			printf("%g ",x);
			for(int n=0;n<=5;n++){
				parameters.n=n;
				if (n+1<=5){
					printf("%g ",integral(parameters));}
				else {printf("%g\n",integral(parameters));}
			}
		}
return 0;
}
