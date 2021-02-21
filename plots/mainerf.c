#include <math.h>
#include <stdio.h>
#include <gsl/gsl_sf_erf.h>
double Erf();

int main(){
	double xmin=-3, xmax=3;
	while(xmin<=xmax){
	printf("%10g %10g %10g %10g\n",xmin,Erf(xmin),erf(xmin),gsl_sf_erf(xmin));
	xmin=xmin+1./8;
	}

return 0;
}

