#include<stdio.h>
#include<gsl/gsl_vector.h>
#include<gsl/gsl_matrix.h>
#include<gsl/gsl_blas.h>
#include<gsl/gsl_linalg.h>
#include<gsl/gsl_eigen.h>


//print function for vector
void vector_print(char s[], gsl_vector* v){
	printf("%s\n",s);
	for(int i=0;i<v->size;i++)printf("%10g\n",gsl_vector_get(v,i));
	printf("\n");
}
//print function for matrix
void matrix_print(char s[], gsl_matrix* A){
	printf("%s\n",s);
	for(int i=0;i<A->size1;i++){
		for(int j=0;j<A->size2;j++){
			printf("%10g ",gsl_matrix_get(A,i,j));
			}
		printf("\n");
	}
	printf("\n");
}


int main(){
	int n=3;
	gsl_matrix* A    =gsl_matrix_alloc(n,n);
	gsl_matrix* Acopy=gsl_matrix_alloc(n,n);
	gsl_vector* x    =gsl_vector_alloc(n);
	gsl_vector* y    =gsl_vector_calloc(n);
	gsl_vector* b    =gsl_vector_alloc(n);

	{
	FILE* f=fopen("input_matrix.txt","r");
	gsl_matrix_fscanf(f,A);
	fclose(f);
	}
	matrix_print("matrix A=",A);

	{
	FILE* f=fopen("input_vector.txt","r");
	gsl_vector_fscanf(f,b);
	fclose(f);
	}
	gsl_matrix_memcpy(Acopy,A);

	gsl_linalg_HH_solve(Acopy,b,x);
	gsl_blas_dgemv(CblasNoTrans,1,A,x,0,y);
	vector_print("vector",b);
	vector_print("solution x=",x);
	vector_print("check: A*x should be equal b:",y);

gsl_matrix_free(A);
gsl_vector_free(x);
gsl_vector_free(y);
gsl_matrix_free(Acopy);
gsl_vector_free (b);

	printf("hilbert matrix 4th order");
	int order=4;
	gsl_matrix*  H=gsl_matrix_alloc(order,order);
	gsl_matrix*  Hcopy=gsl_matrix_alloc(order,order);
	for(int i=0;i<order;i++){
		for(int j=0;j<order;j++){
			double h=1./(i+j+1);
			gsl_matrix_set(H,i,j,h);
			}
	}
	matrix_print("matrix H",H);
	gsl_matrix_memcpy(Hcopy,H);
	gsl_matrix* evec=gsl_matrix_alloc(order,order);
	gsl_vector *eval = gsl_vector_alloc (4);
	gsl_eigen_symmv_workspace* w=gsl_eigen_symmv_alloc(order);
	gsl_eigen_symmv(Hcopy,eval,evec,w);
	vector_print("eigenvalues",eval);
	matrix_print("eigenvectors",evec);
gsl_eigen_symmv_free(w);
gsl_matrix_free(H);
gsl_matrix_free(Hcopy);
return 0;
}

