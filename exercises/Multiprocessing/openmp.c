#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>

typedef struct {double x; double y;} point;
typedef struct {int N; int Nin; unsigned int seed;} counts;

int inorout(point p)
	{
	if(pow(p.x*p.x+p.y*p.y,0.5)<1) {
	return 1;}
	else {
	return 0;
	}
	}

void* counter(void* arg){
	counts * param = (counts*) arg;
	int npoints=(*param).N;
	int seed=(*param).seed;
	double count=0;
	for(int i=1;i<=npoints;i++){
	point p={.x=((double)rand_r(&seed))/RAND_MAX,.y=((double)rand_r(&seed))/RAND_MAX};
	if (inorout(p)==1) count++;
	else continue;
	}
	param->Nin=count;
return NULL;
}


int main(){
	int n=10000000;
	counts nt1={.N=n/2,.Nin=0,.seed=1};
	counts nt2={.N=n/2,.Nin=0,.seed=2};

#pragma omp parallel sections
	{
	#pragma omp section
		{
		counter((void*)&nt1);
		}
	#pragma omp section
		{
		counter((void*)&nt2);
		}
	}
	double Nin=nt1.Nin+nt2.Nin;
	printf("π=%10.10g\n",4*Nin/(n/2+n/2));

return 0;
}
