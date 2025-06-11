#include <stdio.h>
#include <stdlib.h>

const int n=3;
double cycle()
{
    double S=1, F=1;
    for(int i=2; i<=n; i++)
    {
        F=log(F+3)+sqrt(i);
        S+=F;
    }
    return S;
}
double Down(double S, int i, double F)
{
    if(i<=n)
    {
        F=log(F+3)+sqrt(i);
        return Down(S+F, i+1, F);
    }
    return S;
}

double Up(int i, double *S)
{
    double F;
    if(i<=1)
        return 1;
    else
    {
        F=log(Up(i-1, S)+3)+sqrt(i);
        *S+=F;
        return F;
    }

}

double Down_Up(int i, double F)
{
    if(n==1)
        return 1;

    F=log(F+3)+sqrt(i);
    if(i<n)
    {
        return F+Down_Up(i+1, F);
    }
    else
        return F+1;
}


int main()
{
    double S=1;
    double down, cyc, down_up;
    if(n>0)
    {
        down=Down(1,2,1);
        Up(n, &S);
        down_up=Down_Up(2,1);
        cyc=cycle();

        printf("Down=%lf\n\n", down);
        printf("Up=%lf\n\n", S);
        printf("Down_Up=%lf\n", down_up);
        printf("\nCycle=%lf\n", cyc);
    }
    else
        printf("Error\n");

    return 0;
}


