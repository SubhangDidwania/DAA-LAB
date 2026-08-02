#include<stdio.h>
#include<stdlib.h>
#include<time.h>


// Normal Bubble Sort

int bubbleNormal(int a[], int n)
{
    int comparisons=0;


    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {

            comparisons++;


            if(a[j]>a[j+1])
            {
                int temp=a[j];

                a[j]=a[j+1];

                a[j+1]=temp;
            }

        }
    }


    return comparisons;
}




// Optimized Bubble Sort

int bubbleOptimized(int a[], int n)
{
    int comparisons=0;


    for(int i=0;i<n-1;i++)
    {

        int swapped=0;


        for(int j=0;j<n-i-1;j++)
        {

            comparisons++;


            if(a[j]>a[j+1])
            {

                int temp=a[j];

                a[j]=a[j+1];

                a[j+1]=temp;


                swapped=1;

            }

        }


        if(swapped==0)
            break;

    }


    return comparisons;

}




int main()
{

    FILE *fp;

    fp=fopen("bubble.dat","w");


    srand(time(NULL));


    fprintf(fp,"n Optimized Normal\n");


    for(int n=10;n<=1000;n+=10)
    {

        int a[n];
        int b[n];


        // Generate random array

        for(int i=0;i<n;i++)
        {
            a[i]=rand()%10000;

            b[i]=a[i];
        }



        int opt=bubbleOptimized(a,n);

        int normal=bubbleNormal(b,n);



        fprintf(fp,"%d %d %d\n",
        n,opt,normal);

    }


    fclose(fp);


    return 0;

}