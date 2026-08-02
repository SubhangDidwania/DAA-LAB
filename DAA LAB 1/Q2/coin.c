#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{

    int tosses;

    printf("Enter number of tosses: ");
    scanf("%d",&tosses);


    srand(time(NULL));


    FILE *fp;

    fp=fopen("coin.dat","w");


    int fair_heads=0;
    int biased_heads=0;


    double bias=0.7;


    fprintf(fp,"Toss Fair Biased\n");


    for(int i=1;i<=tosses;i++)
    {

        // Fair coin

        int fair=rand()%2;


        if(fair==1)
        {
            fair_heads++;
        }



        // Biased coin

        double r=(double)rand()/RAND_MAX;


        if(r < bias)
        {
            biased_heads++;
        }



        double fair_probability=
        (double)fair_heads/i;


        double biased_probability=
        (double)biased_heads/i;



        fprintf(fp,"%d %lf %lf\n",
        i,
        fair_probability,
        biased_probability);

    }


    fclose(fp);



    printf("\nFair Coin\n");

    printf("Heads = %d\n",fair_heads);

    printf("Probability of Head = %lf\n",
    (double)fair_heads/tosses);



    printf("\nBiased Coin\n");

    printf("Heads = %d\n",biased_heads);


    printf("Probability of Head = %lf\n",
    (double)biased_heads/tosses);



    return 0;

}