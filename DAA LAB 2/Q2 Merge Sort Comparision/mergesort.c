#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long normal_comparisons = 0;
long long three_way_comparisons = 0;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid-left+1;
    int n2 = right-mid;

    int *L = malloc(n1*sizeof(int));
    int *R = malloc(n2*sizeof(int));

    for(int i=0;i<n1;i++)
        L[i]=arr[left+i];

    for(int i=0;i<n2;i++)
        R[i]=arr[mid+1+i];

    int i=0;
    int j=0;
    int k=left;

    while(i<n1 && j<n2)
    {
        normal_comparisons++;

        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }

        else
        {
            arr[k]=R[j];
            j++;
        }

        k++;

    }

    while(i<n1)
    {
        arr[k++]=L[i++];
    }

    while(j<n2)
    {
        arr[k++]=R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right)
{

    if(left<right)
    {
        int mid=(left+right)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }

}

void threeWayMerge(int arr[],int left,int mid1,int mid2,int right)
{
    int size = right-left+1;

    int *temp = malloc(size*sizeof(int));

    int i=left;
    int j=mid1+1;
    int k=mid2+1;

    int index=0;

    while(i<=mid1 &&
          j<=mid2 &&
          k<=right)
    {
        three_way_comparisons++;

        if(arr[i]<=arr[j] &&
           arr[i]<=arr[k])
        {
            temp[index++]=arr[i++];
        }

        else if(arr[j]<=arr[i] &&
                arr[j]<=arr[k])
        {
            temp[index++]=arr[j++];
        }

        else
        {
            temp[index++]=arr[k++];
        }

    }

    while(i<=mid1)
        temp[index++]=arr[i++];

    while(j<=mid2)
        temp[index++]=arr[j++];

    while(k<=right)
        temp[index++]=arr[k++];

    for(i=0;i<index;i++)
        arr[left+i]=temp[i];

    free(temp);
}

void threeWayMergeSort(int arr[],int left,int right)
{
    if(left>=right)
        return;

    if(right-left==1)
    {

        if(arr[left]>arr[right])
        {
            int temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;

        }

        three_way_comparisons++;

        return;
    }

    int third=(right-left+1)/3;
    int mid1 = left+third-1;
    int mid2 = left+2*third-1;

    threeWayMergeSort(arr,left,mid1);
    threeWayMergeSort(arr,mid1+1,mid2);
    threeWayMergeSort(arr,mid2+1,right);

    threeWayMerge(arr,left,mid1,mid2,right);

}

int main()
{
    FILE *fp=fopen("merge.dat","w");

    if(fp==NULL)
    {
        printf("Unable to create file\n");

        return 1;
    }

    srand(time(NULL));

    fprintf(fp,
    "# Input_Size Normal_Merge_Sort Three_Way_Merge_Sort\n");

    printf("Generating data...\n\n");

    for(int n=100;n<=10000;n+=100)
    {
        int *arr1 =
        malloc(n*sizeof(int));

        int *arr2 =
        malloc(n*sizeof(int));

        for(int i=0;i<n;i++)
        {
            arr1[i]=rand()%100000;
            arr2[i]=arr1[i];
        }

        normal_comparisons=0;
        three_way_comparisons=0;

        mergeSort(arr1,0,n-1);

        threeWayMergeSort(arr2,0,n-1);

        fprintf(fp,"%d %lld %lld\n",n,normal_comparisons,three_way_comparisons);

        free(arr1);
        free(arr2);
    }
    fclose(fp);

    printf("merge.dat generated successfully\n");

    return 0;
}