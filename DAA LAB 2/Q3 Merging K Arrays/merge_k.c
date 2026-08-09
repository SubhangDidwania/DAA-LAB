#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long method1_count;
long long method2_count;

//Merge two sorted arrays

int* merge(int *A, int n1, int *B, int n2, long long *count)
{
    int *C = malloc((n1+n2)*sizeof(int));

    int i=0,j=0,k=0;

    while(i<n1 && j<n2)
    {
        (*count)++;

        if(A[i]<=B[j])
            C[k++]=A[i++];

        else
            C[k++]=B[j++];
    }

    while(i<n1)
        C[k++]=A[i++];


    while(j<n2)
        C[k++]=B[j++];

    return C;
}

/*
METHOD 1
Merge one by one
*/

int* sequentialMerge(int **arr, int k, int n)
{
    int *result = NULL;

    int size=0;

    for(int i=0;i<k;i++)
    {
        result =
        merge(result,
              size,
              arr[i],
              n,
              &method1_count);

        size+=n;
    }

    return result;
}

/*
METHOD 2
Pairwise merge
*/

int* pairwiseMerge(int **arr, int k, int n)
{
    int current=k;

    int size=n;

    while(current>1)
    {
        int newCount=0;

        for(int i=0;i<current;i+=2)
        {

            if(i+1<current)
            {
                arr[newCount++]=
                merge(arr[i],
                      size,
                      arr[i+1],
                      size,
                      &method2_count);
            }

            else
            {
                arr[newCount++]=arr[i];
            }
        }

        current=newCount;

        size*=2;
    }

    return arr[0];
}

//Generate sorted arrays

int** generateArrays(int k,int n)
{
    int **arr = malloc(k*sizeof(int*));

    for(int i=0;i<k;i++)
    {
        arr[i]=malloc(n*sizeof(int));

        for(int j=0;j<n;j++)
        {
            arr[i][j]=
            i*100000+j;
        }
    }

    return arr;
}


int main()
{
    FILE *fp=
    fopen("merge_k.dat","w");

    fprintf(fp,"# k method1 method2\n");

    for(int k=2;k<=64;k*=2)
    {
        int n=1000;

        int **arr=
        generateArrays(k,n);

        method1_count=0;

        method2_count=0;

        sequentialMerge(arr,k,n);

        int **arr2 = generateArrays(k,n);

        pairwiseMerge(arr2,k,n);

        fprintf(fp,"%d %lld %lld\n",k ,method1_count ,method2_count);

        printf("Completed k=%d\n",k);
    }

    fclose(fp);

    printf("\nmerge_k.dat generated\n");

    return 0;
}