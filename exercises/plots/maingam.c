#include <math.h>
#include <stdio.h>
#include <gsl/gsl_sf_gamma.h>
double Gam();

int main(){
	double xmin=1./8, xmax=3;
	while(xmin<=xmax){
	printf("%10g %10g %10g %10g\n",xmin,Gam(xmin),tgamma(xmin),gsl_sf_gamma(xmin));
	xmin=xmin+1./16;
	}

return 0;
}

