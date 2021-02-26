#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<pthread.h>

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
	unsigned int seed=(*param).seed;
	double count=0;
	for(int i=1;i<=npoints;i++){
	point p={.x=((double)rand_r(&seed))/RAND_MAX,.y=((double)rand_r(&seed))/RAND_MAX};
	if (inorout(p)==1) count++;
	else continue;
	}
	param->Nin=count;
return NULL;
}

int main()
	{
	int n=100000;
	counts nt1={.N=n/2,.Nin=0,.seed=1};
	counts nt2={.N=n/2,.Nin=0,.seed=2};
	pthread_t t1,t2;
	pthread_attr_t* attributes = NULL;
	pthread_create( &t1, attributes, counter,(void*)&nt1);
	pthread_create( &t2, attributes, counter,(void*)&nt2);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	double Nin=nt1.Nin+nt2.Nin;
	printf("π=%10.10g\n",4*Nin/(n/2+n/2));

return 0;
}
