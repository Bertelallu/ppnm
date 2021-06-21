#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <complex.h>

double complex adapt(double complex f(double complex x), double complex a, double complex b, double acc, double eps, char * points);

//functions used to test the functionallity of the code.
int calls=0;
double complex function1(double complex z){calls++; return z;}
double complex function2(double complex z){calls++; return pow(creal(z),2)+I*cimag(z);}
double complex function3(double complex z){calls++; return creal(z)*2+I*cimag(z)+1;}
double complex function4(double complex z){calls++; return cos(creal(z))+I*sin(cimag(z));}
	
	
//function to make datafile for a colormap. Real value, imaginary value and length of complex function in each point printed to a variable filename.
void printcomplexfunction(double complex f(double complex x), double Rmin,double Rmax,double Imin,double Imax,char * name)
{
	FILE *fil = fopen(name, "w");
	for(double R=Rmin;R<Rmax;R+=1.0/16)
		{
		for(double Imag=Imin;Imag<Imax;Imag+=1.0/16)
			{
			fprintf(fil,"%g %g %g\n",R,Imag,pow(pow(creal((f(CMPLX(R,Imag)))),2)+pow(cimag((f(CMPLX(R,Imag)))),2),0.5)); 
			}
		}
	fclose(fil);
}


int main()
	{
	// setting up colormap for plotting the first function
	double Rmin=-5, Rmax=5, Imin=-5, Imax=5;
	char map1[]="function1.txt";
	printcomplexfunction(function1,Rmin,Rmax,Imin,Imax,map1);
	
	//setting accuracy of calculation
	double acc=1e-6, eps=1e-6;
	
	//setting up calculation of first integral from z=1+i to z=3+3i.
	printf("calculation of first integral from z=1+i to z=3+3i\n");
	double complex a=CMPLX(1,1);
	double complex b=CMPLX(3,3); 
	FILE *fil1 = fopen("line1.txt", "w");
	fprintf(fil1,"%g %g\n",creal(a),cimag(a));
	fprintf(fil1,"%g %g\n",creal(b),cimag(b));
	fclose(fil1);
	char points1[]="points1.txt";
	calls=0;
	double complex Q1 = adapt(function1,a,b,acc,eps,points1); 
	printf("integral of f(z)=z from z=1+i to z=3+3i is %f+i%f\nnumber of calls to function=%d\n\n\n", creal(Q1), cimag(Q1), calls);

	// setting up colormap for plotting the second function
	Rmin=-2, Rmax=2, Imin=-2, Imax=2;
	char map2[]="function2.txt";
	printcomplexfunction(function2,Rmin,Rmax,Imin,Imax,map2);
	
	//setting up calculation of second integral from z=0+0i to z=1+i
	printf("calculation of second integral from z=0+0i to z=1+i\n");
	a=CMPLX(0,0);
	b=CMPLX(1,1); 
	FILE *fil2 = fopen("line2.txt", "w");
	fprintf(fil2,"%g %g\n",creal(a),cimag(a));
	fprintf(fil2,"%g %g\n",creal(b),cimag(b));
	fclose(fil2);
	char points2[]="points2.txt";
	calls=0;
	double complex Q2 = adapt(function2,a,b,acc,eps,points2); 
	printf("integral of f(z)=Re(z)^2+i*Im(z) from z=0+0i to z=1+i is %f+i%f\nnumber of calls to function=%d\n\n\n", creal(Q2), cimag(Q2), calls);
	
	// setting up colormap for plotting the third function
	Rmin=-2, Rmax=2, Imin=-2, Imax=2;
	char map3[]="function3.txt";
	printcomplexfunction(function3,Rmin,Rmax,Imin,Imax,map3);

	//setting up calculation of third integral from z=1-i to z=2+i
	printf("calculation of third integral from z=1-i to z=2+i\n");
	a=CMPLX(1,-1);
	b=CMPLX(2,1); 
	FILE *fil3 = fopen("line3.txt", "w");
	fprintf(fil3,"%g %g\n",creal(a),cimag(a));
	fprintf(fil3,"%g %g\n",creal(b),cimag(b));
	fclose(fil3);
	char points3[]="points3.txt";
	calls=0;
	double complex Q3 = adapt(function3,a,b,acc,eps,points3); 
	printf("integral of f(z)=Re(z)*2+i*Im(z)+1 from z=1-i to z=2+i is %f+i%f\nnumber of calls to function=%d\n\n\n", creal(Q3), cimag(Q3), calls);
	
	// setting up colormap for plotting the fourth function
	Rmin=-4, Rmax=4, Imin=-4, Imax=4;
	char map4[]="function4.txt";
	printcomplexfunction(function4,Rmin,Rmax,Imin,Imax,map4);

	//setting up calculation of fourth integral from z=0+2i to z=2+2i
	printf("calculation of fourth integral from z=0+2i to z=2+2i\n");
	a=CMPLX(0,2);
	b=CMPLX(2,2); 
	FILE *fil4 = fopen("line4.txt", "w");
	fprintf(fil4,"%g %g\n",creal(a),cimag(a));
	fprintf(fil4,"%g %g\n",creal(b),cimag(b));
	fclose(fil4);
	char points4[]="points4.txt";
	calls=0;
	double complex Q4 = adapt(function4,a,b,acc,eps,points4); 
	printf("integral of f(z)=cos(Re(z))+isin(Im(z)) from z=0+2i to z=2+2i is %f+i%f\nnumber of calls to function=%d\n\n\n", creal(Q4), cimag(Q4), calls);
return 0;
}