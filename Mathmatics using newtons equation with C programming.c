//this program approximates the square root of a number using newtons method for anyone to read 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// approximate square root of a number using Newton's method
// https://en.wikipedia.org/wiki/Newton%27s_method
// LOOKUP EXAMPLE for 612 on above URL
// try finding sqare root of 612 (as in above URL)
// first guess is always 10
// for 612, x0 is 10, x1 is 35.6, x2 is 26.3, x3 is 24.79, ...
// Do a minimum of 10 iterations
double squareRoot(double number)
{
    int i;
    double x2, x1;
    i = 0;
    x1 = number;
    x2 = number / 2;

    printf("Finding the square root of %f using Newton's method : \n", number);

    while(i < 11)
    {
        x1 = x2 - (x2 * x2 - number) / (2 * x2);
        {
            i++;
            x2 = x1;
        }
    }
    printf("%.6f \n", x1);
    printf("\n");

    return x1;
}
// Generate random numbers between 0 and 1000
// Call squareRoot to calculate using Newton's method
// Call sqrt from math.h
// print the square roots you got and their difference to 12 decimal places
void squareRootTester(int testTimes)
{
    int ranNum;
    double NewtRoot, Root;
    printf("Testing squareRoot %d times\n", testTimes);

    for (int i = 1; i < testTimes; i++)
    {
        ranNum = rand() % 1000+1;
        NewtRoot = squareRoot(ranNum);
        Root = sqrt(ranNum);
        float diff = NewtRoot - Root;

        printf("For %d, my squareRoot gives %.12f, builtin sqrt gives %.12f, difference is %.12f\n", ranNum, NewtRoot, Root, diff);
        printf("\n");
    }
}
double sumOfGeometricSeries(int sequenceLength)
{
    double sum, geo, ex;
    sum = 0;
    geo = 1.0/2.0;
    ex = 1.0/3.0;
    for (int i=1; i<=sequenceLength; i++)
    {
        sum = sum + geo;
        geo = geo*(-1.0/2.0);
        printf("For sequence length of %d,sumOfGeometricSeries gives %.12f, expectedResult is %.12f, difference is %.12f\n", i,sum,ex,sum-ex);
    }
    // TODO
    return sum;
}
// Calculates the infinite series using sumOfGeometricSeries
// Tries out sequenceLength from 1 to 10
// print the result returned from sumOfGeometricSeries and the difference to 1.0/3.0 to 12 decimal places
void sumOfGeometricSeriesTester()
{
    printf("Testing sumOfGeometricSeries\n");
    sumOfGeometricSeries(10);
}
// TODO -- Bonus points only
double calculateEulerNumber()

{
    double n = 100000000;
    double calculatedEuler = pow(1+1/n,n);
    printf("%.12f", calculatedEuler);

    return 0;
}

int main()
{
    squareRoot(612);
    squareRootTester(10);
    sumOfGeometricSeriesTester();
    calculateEulerNumber();

    return 0;
}
