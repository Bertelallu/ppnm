#include<gsl/gsl_matrix.h>
#include<gsl/gsl_blas.h>
#include<math.h>

void jacobi_diag(gsl_matrix* A, gsl_matrix * V);
void jacobi_diag_op(gsl_matrix* A, gsl_matrix * V);
void GenerateMatrix(gsl_matrix* A, int N);
void matrix_print(char s[], gsl_matrix* M);
void builtH(gsl_matrix* H);
double exact(double x, int n);

void MeasureTime(int Nmin,int Nmax);

int main(){
	printf("A\n");
	int N=3;
	
	gsl_matrix *A=gsl_matrix_alloc(N,N);
	gsl_matrix *Acopy=gsl_matrix_alloc(N,N);
	gsl_matrix *V=gsl_matrix_alloc(N,N);
	gsl_matrix *VDVT=gsl_matrix_alloc(N,N);
	gsl_matrix *DVT=gsl_matrix_alloc(N,N);
	gsl_matrix *VTV=gsl_matrix_alloc(N,N);
	

	
	gsl_matrix_set_identity(V); 
	GenerateMatrix(A,N);
	gsl_matrix_memcpy(Acopy,A);
	matrix_print("A=",A);
	jacobi_diag(A,V);
	matrix_print("V=",V);
	matrix_print("VtAV= , should be diagonal",A);
	
	gsl_blas_dgemm(CblasNoTrans, CblasTrans, 1.0, A, V, 0.0, DVT);
	
	gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, V, DVT, 0.0, VDVT); 
	matrix_print("VDVT= , should be equal to A",VDVT);
	
	gsl_blas_dgemm(CblasTrans, CblasNoTrans, 1.0, V, V, 0.0, VTV); 
	matrix_print("VTV= , should be indentity matrix",VTV);
	

// B
	printf("\n\nComparison with exact values of eigenvalues below.\nFigure of the eigenfunctions are found in partyinabox.pyxplot.png\n");
	int n=50;
	gsl_matrix* H = gsl_matrix_alloc(n,n);
	builtH(H);
	gsl_matrix *EV = gsl_matrix_alloc(n,n);
	gsl_matrix_set_identity(EV); 
	jacobi_diag(H,EV);

	
for (int k=0; k < n/3; k++){
    double exact = M_PI*M_PI*(k+1)*(k+1);
    double calculated = gsl_matrix_get(H,k,k);
    printf("%i %g %g\n",k,calculated,exact);
}

FILE * f1=fopen("eigenfunctions.txt","w");

fprintf(f1,"0 0 0 0\n");
for(int i=0;i<n;i++){ 
	fprintf(f1,"%g %g %g %g\n",(i+1.0)/(n+1), gsl_matrix_get(EV,i,0), -gsl_matrix_get(EV,i,1),gsl_matrix_get(EV,i,2));}
fprintf(f1,"1 0 0 0\n");

fclose(f1);

FILE * f2=fopen("exacteigenfunctions.txt","w");

fprintf(f2,"0 0 0 0\n");
for(int i=0;i<n;i++){ 
	double x=(i+1.0)/(n+1);
	fprintf(f2,"%g %g %g %g\n",x, exact(x,1),exact(x,2),exact(x,3));
	}
fprintf(f2,"1 0 0 0\n");
fclose(f2);

gsl_matrix_free(H);
gsl_matrix_free(EV);

printf("\n\ntesting the optimized jacobi diagonalization algorithm and testing the time afterwards with MeasrureTime. See results in figure timediagonalization.pyxplot.png\n");
	gsl_matrix_set_identity(V); 
	matrix_print("A=",Acopy);
	jacobi_diag_op(Acopy,V);
	matrix_print("V=",V);
	matrix_print("VtAV=",Acopy);
	
	gsl_blas_dgemm(CblasNoTrans, CblasTrans, 1.0, A, V, 0.0, DVT);
	gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, V, DVT, 0.0, VDVT); 
//	matrix_print("VDVT= , should be A, but with wrong lower triagonal matrix",VDVT);
	
	gsl_blas_dgemm(CblasTrans, CblasNoTrans, 1.0, V, V, 0.0, VTV); 
	matrix_print("VTV= , should be indentity matrix",VTV);
	

	gsl_matrix_free(A);
	gsl_matrix_free(V);
	gsl_matrix_free(VDVT);
	gsl_matrix_free(DVT);
	gsl_matrix_free(VTV);

int Nmin=50;
int Nmax=100;
MeasureTime(Nmin,Nmax);

return 0;
}