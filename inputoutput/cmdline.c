#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	if(argc<2)fprintf(stderr,"there were no arguments\n");
	else{
		for(int i=1;i<argc;i++){
			double x = atof(argv[i]);
			printf("x=%g sin(x)=%g cos(x)=%g\n",x,sin(x),cos(x));
		}
	}
return 0;
}
