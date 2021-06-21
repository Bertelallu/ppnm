#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<gsl/gsl_vector.h>

void plainmcA(double f(gsl_vector* x),gsl_vector* a,gsl_vector* b,int N,gsl_vector* results);
void plainmcB(double f(gsl_vector* x),gsl_vector* a,gsl_vector* b,int N,gsl_vector* results);

double f1(gsl_vector * x){
	return pow(sin(gsl_vector_get(x,0)),2);
	}

double f2(gsl_vector *x){
	if (1-cos(gsl_vector_get(x,0))*cos(gsl_vector_get(x,1))*cos(gsl_vector_get(x,2))==0) return 10;
	return 1/pow(M_PI,3)*pow(1-cos(gsl_vector_get(x,0))*cos(gsl_vector_get(x,1))*cos(gsl_vector_get(x,2)),-1);
	}

int main(){
	//A and B.
	//first, comparison of Plain Monte carlo(A) and quasi-random Monte carlo(B) integrators
	//results found in Error.gnuplot.png
	printf("for the function f(x)=sin(x)^2\n");
	int dim1=1;
	gsl_vector*a1=gsl_vector_alloc(dim1);
	gsl_vector*b1=gsl_vector_alloc(dim1);
	gsl_vector_set(a1,0,0);
	gsl_vector_set(b1,0,M_PI);
	int N1=100000;
	gsl_vector* results1=gsl_vector_alloc(2);
	plainmcA(f1,a1,b1,N1,results1);
	printf("Plain MC gives integral=%.25g, error=%.25g\n",gsl_vector_get(results1,0),gsl_vector_get(results1,1));
	plainmcB(f1,a1,b1,N1,results1);
	printf("Quasi-random MC gives integral=%.25g, error=%.25g\n",gsl_vector_get(results1,0),gsl_vector_get(results1,1));
	printf("actual results=%.25g\n\n",M_PI/2);
	
	FILE * file1=fopen("A.txt","w");
	FILE * file2=fopen("B.txt","w");
	for(int N=10000; N<100000; N+=5000){
		plainmcA(f1,a1,b1,N,results1);
		fprintf(file1,"%d %.25g %.25g\n",N,gsl_vector_get(results1,0),gsl_vector_get(results1,1));
		
		plainmcB(f1,a1,b1,N,results1);
		fprintf(file2,"%d %.25g %.25g\n",N,gsl_vector_get(results1,0),gsl_vector_get(results1,1));
		}
	fclose(file1);
	fclose(file2);
	
	// Integral asked to be calculated in A.
	//comparison is also found in ErrorError.gnuplot.png
	printf("The proposed integral is calculated;\n");
	int dim2=3;
	gsl_vector*a2=gsl_vector_alloc(dim2);
	gsl_vector*b2=gsl_vector_alloc(dim2);
	gsl_vector_set(a2,0,0);
	gsl_vector_set(b2,0,M_PI);
	gsl_vector_set(a2,1,0);
	gsl_vector_set(b2,1,M_PI);
	gsl_vector_set(a2,2,0);
	gsl_vector_set(b2,2,M_PI);
	int N2=100000;
	gsl_vector* results2=gsl_vector_alloc(2);
	plainmcA(f2,a2,b2,N2,results2);
	printf("Plain MC gives integral=%.25g, error=%.25g\n",gsl_vector_get(results2,0),gsl_vector_get(results2,1));
	plainmcB(f2,a2,b2,N2,results2);
	printf("Quasi-random MC gives integral=%.25g, error=%.25g\n",gsl_vector_get(results2,0),gsl_vector_get(results2,1));
	printf("actual results=1.3932039296856768591842462603255\n"); 
	FILE * file3=fopen("AA.txt","w");
	FILE * file4=fopen("BB.txt","w");
	for(int N=10000; N<100000; N+=2500){
		plainmcA(f2,a2,b2,N,results2);
		fprintf(file3,"%d %.25g %.25g\n",N,gsl_vector_get(results2,0),gsl_vector_get(results2,1));
		
		plainmcB(f2,a2,b2,N,results2);
		fprintf(file4,"%d %.25g %.25g\n",N,gsl_vector_get(results2,0),gsl_vector_get(results2,1));
		}
	fclose(file3);
	fclose(file4);
	printf("Regarding comparison; From both figures it is clear that quasi-random provides lower estimated errors.\n");
	
	
return 0;
}
