#include <stdio.h>
#include <math.h>

double x_2(double);

double (*funcp)(double);
double trap_sinple(double, double, double (*funcp)(double));

int main(void)
{
    double a, b;
    double s;
    scanf("%lf %lf", &a, &b);
    s = trap_sinple(a, b, sin);
    printf("%lf\n", s);
    return 0;
}

double x_2(double x)
{
    return x*x;
}

double trap_sinple(double a, double b, double (*funcp)(double))
{
    double s;
    s = ((b-a)/2) * ((*funcp)(a) + (*funcp)(b));
    return s;
}
