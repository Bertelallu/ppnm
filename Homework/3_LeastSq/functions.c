#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<gsl/gsl_vector.h>
#include<gsl/gsl_matrix.h>
#include<gsl/gsl_blas.h>


void matrix_print(char s[], gsl_matrix* M){
    printf("%s\n",s);
	for(int i=0;i< M->size1;i++){
        for(int j = 0; j< M->size2; j++){
            //printf("i, j = %10d %10d \n", i,j);
        printf("%10g ", gsl_matrix_get(M,i,j));}
    printf("\n");}
    
}

void vector_print(char s[], gsl_vector* v){
	printf("%s\n",s);
	for(int i=0;i<v->size;i++)printf("%10g \n",gsl_vector_get(v,i));
}

void GenerateMatrix(gsl_matrix* A, int N, int M) {
    
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++) {
            gsl_matrix_set(A, i, j, (double)rand()/RAND_MAX);}   
    }
    
}

double Rsum(gsl_matrix *R, gsl_vector *x, int i){
	if(i==x->size-1) return 0;
    
	double sum=0;
	int j=x->size-1; //-1 to ensure proper indexing
	for(j=j;j>i;j--)
		{
		sum+=gsl_matrix_get(R,i,j)*gsl_vector_get(x,j);
		}
return sum;
}

void GS_solve(gsl_matrix* Q, gsl_matrix* R, gsl_vector* b, gsl_vector* x){

	gsl_matrix* QT = gsl_matrix_alloc(Q->size2,Q->size1);
	gsl_matrix_transpose_memcpy(QT, Q);
	gsl_blas_dgemv(CblasNoTrans, 1.0, QT, b, 0.0, x);
	
	int i=x->size-1; //size-1 to ensure proper indexing. i is the rows in R.
	for(i=i;i>=0;i--)
		{
		gsl_vector_set(x,i,(gsl_vector_get(x,i)-Rsum(R,x,i))/gsl_matrix_get(R,i,i));
		}
    gsl_matrix_free(QT);

}

void GS_decomp(gsl_matrix* A, gsl_matrix* R) {
   int N = A->size1; //Size1 er antal rækker
   int M = A->size2;   //Size1 er antal søjler
   for (int i =0; i<M; i++){
       
       //Sets Rii=sqrt(ai^T*ai)
       gsl_vector* ai = gsl_vector_alloc(N); 
       gsl_matrix_get_col(ai, A, i);
       double dot; 
       gsl_blas_ddot(ai, ai, &dot); 
       gsl_matrix_set(R, i, i, sqrt(dot));
       
       //Sets qi = ai/Rii
       gsl_vector_scale(ai, (double)1/sqrt(dot)); 
       gsl_matrix_set_col(A, i, ai);
       
       
       for (int j = i+1; j < M; j++){ 
            
            //Sets Rij = qi^T*aj
            double dot2; 
            gsl_vector* aj = gsl_vector_alloc(N); 
            gsl_matrix_get_col(aj, A, j);
            //gsl_matrix_get_col(ai, A, i);
            gsl_blas_ddot(ai, aj, &dot2); 
            gsl_matrix_set(R, i, j, dot2);
            
            //Sets aj = aj-qi*Rij
            gsl_vector_scale(ai,dot2);
            gsl_vector_sub(aj, ai); 
            gsl_matrix_set_col(A, j, aj); //aj = aj-qi*Rij
            gsl_vector_scale(ai,(double)1/dot2);
            gsl_vector_free(aj);
            
            }
    gsl_vector_free(ai);    
   }
}

void GS_inverse(gsl_matrix* Q, gsl_matrix* R, gsl_matrix* B){
	gsl_matrix_set_identity(B); 
	for(int i=0; i<Q->size2; i++){
		gsl_vector_view v = gsl_matrix_column(B,i);
        gsl_vector* v_save = gsl_vector_alloc(B->size1);
        gsl_vector_memcpy(v_save,&v.vector);
		GS_solve(Q, R, v_save, &v.vector);
        gsl_vector_free(v_save);
	}	
    
}

double f(int k, double z){
	if (k == 0) {return 1.0;}
	if (k == 1) {return -z;}

return 0;
}

void leastsq(gsl_vector* x, gsl_vector* y, gsl_vector* dy, gsl_vector* c,gsl_vector* dc, double f(int k, double z)){
	
	gsl_matrix* A = gsl_matrix_alloc(x->size,c->size);
	gsl_matrix* R = gsl_matrix_alloc(c->size,c->size);
	
	for (int i=0; i<A->size1; i++){
		for (int k=0; k<A->size2; k++){
			gsl_matrix_set(A, i, k, f(k, gsl_vector_get(x,i))/gsl_vector_get(dy,i));
		}
	}
	
	//matrix_print("A=",A); 
	
	gsl_vector* b = gsl_vector_alloc(dy->size);
	gsl_vector_memcpy(b,y);
	gsl_vector_div(b, dy);
	
	GS_decomp(A, R);
	GS_solve(A, R, b, c);
	
	gsl_matrix* Sigma = gsl_matrix_alloc(c->size,c->size);
	gsl_matrix* Rsigma = gsl_matrix_alloc(c->size,c->size);
	gsl_matrix* Sigma_inverse = gsl_matrix_alloc(c->size,c->size);
	
	//matrix_print("R = ", R);
	
	gsl_blas_dgemm(CblasTrans,CblasNoTrans, 1.0, R, R, 0.0, Sigma);
	//matrix_print("Sigma =", Sigma);
	
	GS_decomp(Sigma, Rsigma);
	//matrix_print("Sigma_decomp =", Sigma);
	GS_inverse(Sigma,Rsigma,Sigma_inverse);
	matrix_print("Calculated Covariance marix =", Sigma_inverse);
	for (int i=0;i<c->size;i++){ //bestemmer usikkerhederne på a og b
		gsl_vector_set(dc,i,sqrt(gsl_matrix_get(Sigma_inverse,i,i)));
	}
	
	
	
	
}