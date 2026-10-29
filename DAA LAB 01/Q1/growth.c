#include<stdio.h>
#include<math.h>

int main()
{
    FILE *fp;

    fp=fopen("growth.dat","w");


    for(double n=1;n<=100;n++)
    {
        double f1=1/n;

        double f2=12*sqrt(n);

        double f3=50*pow(n,0.5);

        double f4=pow(n,0.51);

        double f5=n;

        double f6=pow(2,32)*n;

        double f7=n*log2(n);

        double f8=100*n*n+6*n;

        double f9=n*n-324;

        double f10=2*pow(n,3);

        double f11=pow(n,log2(n));

        double f12=pow(3,n);


        fprintf(fp,
        "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",
        n,
        f1,
        f2,
        f3,
        f4,
        f5,
        f6,
        f7,
        f8,
        f9,
        f10,
        f11,
        f12);

    }


    fclose(fp);


    return 0;
}