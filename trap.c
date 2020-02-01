#include <stdio.h>
#include <math.h>

double x_2(double);
double trap_sinple(double, double, double (*funcp)(double));
double trap_com(double, double, int, double (*funcp)(double));

int main(void)
{
    printf("sin(x)を積分(範囲：%lf ~ %lf)(分割数：%d)すると%lf\n", 0.0, M_PI, 10, trap_com(0, M_PI, 10, sin));
    printf("cos(x)を積分(範囲：%f ~ %lf)(分割数：%d)すると%lf\n", 0.0, M_PI, 10, trap_com(0, M_PI, 10, cos));
    printf("x^2を積分(範囲：%lf ~ %lf)(分割数：%d)すると%lf\n", 0.0, 2.0, 10, trap_com(0, 2, 10, x_2));
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

double trap_com(double a, double b, int n, double (*funcp)(double))
{
    double s = 0;               //答え
    double h = (b-a) / (n-1);   //分割幅
    int i;

    s += (*funcp)(a);
    for(i=2; i<n; i++)
    {
        s += 2 * (*funcp)(a + h * (i-1));
    }
    s += (*funcp)(b);
    s = s * h / 2;
    return s;
}
