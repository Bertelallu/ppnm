As my number is 201705728 i have project number 6.
Integrate a complex function of a complex variable along a straight line between 2 points in
the complex plane.

To implement this, i used the adaptive algorithm previously coded in homework 6, and modified it.
The headerfile complex.h was a great help, as the tedious work of performing simple mathematical
operations with complex numbers was removed by using "double complex" when declaring complex variables.
Getting a linear path from a to b was easy using this approach as well, in fact no special modification
was needed other than changing to complex variables.

The code uses two different rules to estimate the error in each recursion, and thus evaluate if more
recursive calls are needed. The higher order rule is trapezium and the lower order rule is rectangle.

The code was tested on some analytical examples(first 3 integrals) and gave the right results.
The analytical answer to the last provided example is unknown, but the result of the numerical method
seems resonable.

The results are given in the out.txt file and 4 colormaps shows the integration path in the complex plane.
In the colormaps the color shows the modulus of f(z) in any given point, z. The first 4 points are shown
as well to verify that the integration is happening along a straigth line between 2 points. 

