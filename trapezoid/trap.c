#include <stdio.h>
#include <math.h>

double x_2(double);

int main(void)
{
    double a, b;
    double s;
    scanf("%lf %lf", &a, &b);
    s = ((b-a)/2) * (x_2(a) + x_2(b));
    printf("%lf\n", s);
    return 0;
}

double x_2(double x)
{
    return x*x;
}