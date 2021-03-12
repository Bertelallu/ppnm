#include<math.h>
#include<stdio.h>
#include<gsl/gsl_vector.h>
#include<assert.h>


double linterp(gsl_vector * x,gsl_vector * y, double Z);
double linterp_integ(gsl_vector *x,gsl_vector *y, double Z);
int binsearch(int n,gsl_vector *x,double Z);
typedef struct {gsl_vector *x, *y, *b, *c;} qspline;

qspline* qspline_alloc(gsl_vector *x, gsl_vector* y){
	qspline *s=(qspline*)malloc(sizeof(qspline));
	s->b=gsl_vector_alloc((x->size)-1);
	s->c=gsl_vector_alloc((x->size)-1);
	s->x=gsl_vector_alloc(x->size);
	s->y=gsl_vector_alloc(x->size);
	s->x=x; s->y=y;
	int i; gsl_vector * h=gsl_vector_alloc((x->size)-1); gsl_vector * p=gsl_vector_alloc((x->size)-1);

	for(i=0;i<(x->size)-1;i++){
	gsl_vector_set(h,i,gsl_vector_get(x,i+1)-gsl_vector_get(x,i));
	gsl_vector_set(p,i,(gsl_vector_get(y,i+1)-gsl_vector_get(y,i))/gsl_vector_get(h,i));
	}
	gsl_vector_set(s->c,0,0);

	for(i=0;i<(x->size)-2;i++){
	gsl_vector_set(s->c,i+1,(gsl_vector_get(p,i+1)-gsl_vector_get(p,i)-gsl_vector_get(s->c,i)*gsl_vector_get(h,i))/gsl_vector_get(h,i+1));
	}
	gsl_vector_set(s->c,x->size-2,gsl_vector_get(s->c,i-2)/2);

	for(i=x->size-3;i>=0;i--){gsl_vector_set(s->c,i,(gsl_vector_get(p,i+1)-gsl_vector_get(p,i)-gsl_vector_get(s->c,i+1)*gsl_vector_get(h,i+1))/gsl_vector_get(h,i));
	}
	for(i=0;i<x->size-1;i++){gsl_vector_set(s->b,i,gsl_vector_get(p,i)-gsl_vector_get(s->c,i)*gsl_vector_get(h,i));
	}
return s;
}

double qspline_eval(qspline *s, double z){
	int index=binsearch(s->x->size,s->x,z);
	double h=z-gsl_vector_get(s->x,index);
	return gsl_vector_get(s->y,index)+h*(gsl_vector_get(s->b,index)+h*gsl_vector_get(s->c,index));
}
//double spline_integ_quad();

void spline_free(qspline *s){
	free(s->x); free(s->y); free(s->b); free(s->x); free(s);}

int main(){
//	int N=10;

//finder længden af filen hvori vores punkter ligger og skriver det i heltallet N.
	int N=0;
	FILE* fp=fopen("input.dat","r");
	int ch;
	while(!feof(fp))
		{
  		ch = fgetc(fp);
  		if(ch == '\n')
  			{
    			N++;
  			}
		}
	fclose(fp);

//Memory is allocated to two vector x and y, which will contain the x and y values for each point.
	gsl_vector * x = gsl_vector_alloc (N);
	gsl_vector * y = gsl_vector_alloc (N);

/*	for(int i=0;i<=N;i++)
		{
		gsl_vector_set (x, i, i);
		gsl_vector_set (y, i, 1);
		}
*/

//loader punkter fra fil ind i vektorerner x og y.
	double i;
	double j;
	int items;
	int n=0;
	FILE* my_in_stream=fopen("input.dat","r");
	while((items=fscanf(my_in_stream,"%lg %lg",&i,&j))!=EOF){
		gsl_vector_set (x, n, i);
		gsl_vector_set (y, n, j);
		n++;
		}
	fclose(my_in_stream);
//	for(int n=0;n<N;n++) printf("%g %g\n",gsl_vector_get(x,n),gsl_vector_get(y,n));
//A linear interpolation is done on the points loaded in vectors x and y.
//The values are written into a file linterp.dat. Along with the integral top that point.
	FILE * f=fopen("linterp.dat","w");
	double z=gsl_vector_get(x,0);
	qspline *s=qspline_alloc(x,y);
	for((z=z);z<=N;z+=1./8){
		double yiz=linterp(x,y,z);
		double integraltilz=linterp_integ(x,y,z); 
		double quadterp=qspline_eval(s,z);
		fprintf(f,"%g %g %g %g\n",z,yiz,integraltilz,quadterp);
		}
	fclose(f);


gsl_vector_free (x);
gsl_vector_free (y);
return 0;
}
