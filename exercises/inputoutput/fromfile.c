#include<stdio.h>
#include<math.h>
int main(int argc, char** argv){
	double x;
	int items;
	if(argc<2)fprintf(stderr,"there were no arguments\n");
	if(argc>3)fprintf(stderr,"there were too many arguments\n");
	else{
	FILE* my_in_stream=fopen(argv[1],"r");
	FILE* my_out_stream=fopen(argv[2],"w");
	while(items=fscanf(my_in_stream,"%lg",&x)!=EOF){
		fprintf(my_out_stream,"x=%g sin(x)=%g cos(x)=%g\n",x,sin(x),cos(x));
	}
	fclose(my_out_stream);
	}
return 0;
}
