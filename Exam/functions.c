#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <complex.h>
int nrec;
int finaldepth;
double complex integrate(double complex f(double complex z), double complex a, double complex b, double acc, double eps, double complex f2, double complex f3,int recdepth,char * points)
{	
	assert(recdepth<1e5);
	double complex f1=f(a+(b-a)/6.0), f4=f(a+5.0*(b-a)/6.0);
	
	if(nrec==0){
		FILE *fil = fopen(points, "w");
		fprintf(fil,"%f %f\n",creal(a+(b-a)/6.0),cimag(a+(b-a)/6.0));
		fprintf(fil,"%f %f\n",creal(a+2.0*(b-a)/6.0),cimag(a+2.0*(b-a)/6.0));
		fprintf(fil,"%f %f\n",creal(a+4.0*(b-a)/6.0),cimag(a+4.0*(b-a)/6.0));
		fprintf(fil,"%f %f\n",creal(a+5.0*(b-a)/6.0),cimag(a+5.0*(b-a)/6.0));
		fclose(fil);
		}
		
	double complex Q=(2.0*f1+f2+f3+2.0*f4)/6.0*(b-a), q=(f1+f4+f2+f3)/4.0*(b-a);
	
	double tolerance=acc+eps*fabs(Q), error=fabs(Q-q);
	if (error < tolerance) {
		return Q;
	}
	else
	{
		nrec++;
		if(recdepth>finaldepth){finaldepth=recdepth;}
		return integrate(f, a,(a+b)/2.0,acc/sqrt(2.),eps, f1, f2,recdepth+1,points)+integrate(f,(a+b)/2.0,b,acc/sqrt(2.),eps, f3, f4,recdepth+1,points);
	}
}

double complex adapt(double complex f(double complex z), double complex a, double complex b, double acc, double eps, char * points)
{
	double complex f2=f(a+2.0*(b-a)/6.0), f3=f(a+4.0*(b-a)/6.0);
	nrec=0;
	finaldepth=0;
	int recdepth=0;
	double complex retur=integrate(f, a, b, acc, eps, f2, f3,recdepth,points);
	printf("number of recursive calls=%d\n",nrec);
	printf("deepest depth of recursion=%d\n",finaldepth);
	return retur;
}
