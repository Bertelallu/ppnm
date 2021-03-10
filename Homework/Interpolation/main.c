#include<math.h>
#include<stdio.h>
#include<gsl/gsl_vector.h>

double linterp(gsl_vector * x,gsl_vector * y, double Z);
double linterp_integ(gsl_vector *x,gsl_vector *y, double Z);



int main(){
	int N=10;
	gsl_vector * x = gsl_vector_alloc (N+1);
	gsl_vector * y = gsl_vector_alloc (N+1);
	for(int i=0;i<=N;i++)
		{
		gsl_vector_set (x, i, i);
		gsl_vector_set (y, i, 1);
		}

	double z;
	FILE * f=fopen("spline.dat","w");
	for(z=1./8;z<10;z+=1./8){
	double yiz=linterp(x,y,z);
	fprintf(f,"%g %g\n",z,yiz);
	}
	fclose(f);
//	double integraltilz=linterp_integ(x,y,z);
//	printf("%g\n",integraltilz);

gsl_vector_free (x);
gsl_vector_free (y);
return 0;
}
