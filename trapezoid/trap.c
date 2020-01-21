#include <stdio.h>
#include <math.h>

double x_2(double);
double (*funcp)(double);
double trap_sinple(double, double, double (*funcp)(double));

int main(void)
{
    double a, b;    //積分範囲
    double s = 0;   //答え
    double h;       //一分割の幅
    int n;          //分割数
    int i;

    scanf("%lf %lf %d", &a, &b, &n);

    h = (b-a) / (n-1);

    s += x_2(a);
    for(i=2; i<n; i++)
    {
        s += 2 * x_2(a + h * (i-1));
    }
    s += x_2(b);
    s = s * h / 2;
    
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
