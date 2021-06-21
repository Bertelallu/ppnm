#include <math.h>
#include <stdio.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include "ann.h"

void qnewton(
	double f(gsl_vector* x), /* objective function */
	gsl_vector* x, /* on input: starting point, on exit: approximation to root */
	double eps /* accuracy goal, on exit |gradient| should be <eps */
	);


void vector_print(char s[], gsl_vector* v){
	printf("%s",s);
	for(int i=0;i<v->size;i++)printf("%10g \n",gsl_vector_get(v,i));
	printf("\n");
}
	
double activationfunction(double x){
	return x*exp(-(x*x));
}

double fittingfunction(double x){
	return cos(5*x-1)*exp(-fabs(x));
}

gsl_vector * xfunc;
gsl_vector * yexact;
ann * network;

double cost_function(gsl_vector* p){
		gsl_vector_memcpy(network->params,p);
		double sum=0;
		for(int i=0;i<xfunc->size;i++){
			double xi=gsl_vector_get(xfunc,i);
			double yi=gsl_vector_get(yexact,i);
			double fi=ann_response(network,xi);
			sum+=fabs(fi-yi);
		}
		return sum/xfunc->size;
}


int main(){
	printf("A and B\n");
	printf("interpolation using neural network\n");
	printf("the result of a interpolation on cos(5*x-1)*exp(-abs(x)) using activation function x*exp(-(x*x)) are shown in figure data.pyxplot.png\n");
	printf("implementation of gradient and antiderivative of integration are shown in figure dataB.pyxplot.png");
	
	int n=5; //number of neurons
	network=ann_alloc(n,*activationfunction);

	double a=-3;
	double b=3;
	
	for(int i=0;i<n;i++){
		gsl_vector_set(network->params,i*3,a+(b-a)*i/(network->n-1));
		gsl_vector_set(network->params,i*3+1,1);
		gsl_vector_set(network->params,i*3+2,1);
	}
	//vector_print("network->params\n",network->params);
	int np=100;
	xfunc=gsl_vector_alloc(np);
	yexact=gsl_vector_alloc(np);
	for (int i=0;i<np;i++){
		double x=a+(b-a)*i/(np-1);
		double f=fittingfunction(x);
		gsl_vector_set(xfunc,i,x);
		gsl_vector_set(yexact,i,f);
	}

	ann_train(network,xfunc,yexact);
	
	//vector_print("network->params\n",network->params);
	//vector_print("x\n",xfunc);
	//vector_print("cos(x)\n",yexact);
	gsl_vector * ygaet=gsl_vector_alloc(np);
	
	for(int i=0;i<xfunc->size;i++){
		gsl_vector_set(ygaet,i,ann_response(network,gsl_vector_get(xfunc,i)));
	}
	//vector_print("guess of y\n",ygaet);
	FILE* f=fopen("data.txt","w");
	for(int i=0;i<np;i++){
		fprintf(f,"%g %g %g\n",gsl_vector_get(xfunc,i),gsl_vector_get(yexact,i),gsl_vector_get(ygaet,i));
	}
	double deltax=1.0/16; //"looping over doubles is dangerous if you don't know what you are doing"
	FILE* f2=fopen("dataB.txt","w");
	for(double step=a;step<=b;step+=deltax){
		double gradient=ann_gradient(network,step);
		double value=ann_response(network,step);
		double integral=ann_integral(network,step);
		double exactvalue=fittingfunction(step);
		fprintf(f2,"%g %g %g %g %g\n",step,gradient,value,integral,exactvalue);
	}
	
return 0;
}