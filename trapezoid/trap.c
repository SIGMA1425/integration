#include <stdio.h>
#include <math.h>

double x_2(double);
double trap_sinple(double, double);

int main(void)
{
    double a, b;
    double s;
    scanf("%lf %lf", &a, &b);
    s = trap_sinple(a, b);
    printf("%lf\n", s);
    return 0;
}

double x_2(double x)
{
    return x*x;
}

double trap_sinple(double a, double b)
{
    double s;
    s = ((b-a)/2) * (x_2(a) + x_2(b));
    return s;
}
