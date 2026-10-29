/*
========================================================

DAA LAB

Problem 1:
Dictionary ADT Complexity Analysis

Structures:

1. Unsorted Array        UA
2. Sorted Array          SA
3. Unsorted Singly List  USL
4. Sorted Singly List    SSL
5. Unsorted Doubly List  UDL
6. Sorted Doubly List    SDL


Operations:

Search
Insert
Delete
Minimum
Maximum
Predecessor
Successor


========================================================
*/


#include <stdio.h>
#include <math.h>



/*
Structure IDs
*/

#define UA 0
#define SA 1
#define USL 2
#define SSL 3
#define UDL 4
#define SDL 5



/*
Operation IDs
*/

#define SEARCH 0
#define INSERT 1
#define DELETE 2
#define MIN 3
#define MAX 4
#define PRED 5
#define SUCC 6



/*
Calculate operation cost
*/


long long cost(int structure,
               int operation,
               int n)
{

    long long c;



    switch(operation)
    {


        /*
        SEARCH
        */

        case SEARCH:

            if(structure==SA)

                c=log2(n);

            else

                c=n;

            break;




        /*
        INSERT
        */

        case INSERT:

            if(structure==UA ||
               structure==USL ||
               structure==UDL)

                c=1;

            else

                c=n;

            break;




        /*
        DELETE
        */

        case DELETE:

            if(structure==UA ||
               structure==UDL ||
               structure==SDL)

                c=1;

            else

                c=n;

            break;




        /*
        MINIMUM
        */

        case MIN:

            if(structure==SA ||
               structure==SSL ||
               structure==SDL)

                c=1;

            else

                c=n;

            break;




        /*
        MAXIMUM
        */

        case MAX:


            if(structure==SA ||
               structure==SDL)

                c=1;

            else

                c=n;

            break;




        /*
        PREDECESSOR
        SUCCESSOR
        */


        case PRED:
        case SUCC:


            if(structure==SA ||
               structure==SDL)

                c=1;

            else

                c=n;


            break;



        default:

            c=0;

    }


    return c;

}





/*
Generate data for any operation
*/


void generate(char *filename,
              int operation)
{

    FILE *fp;



    fp=fopen(filename,"w");



    fprintf(fp,
    "# n UA SA USL SSL UDL SDL\n");



    for(int n=100;
        n<=10000;
        n+=100)
    {


        fprintf(fp,"%d ",n);



        for(int s=0;
            s<6;
            s++)
        {


            fprintf(fp,
            "%lld ",
            cost(s,operation,n));

        }


        fprintf(fp,"\n");


    }


    fclose(fp);

}





int main()
{


    printf("Generating Dictionary Analysis Data...\n");



    generate("search.dat",
             SEARCH);



    generate("insert.dat",
             INSERT);



    generate("delete.dat",
             DELETE);



    generate("minmax.dat",
             MIN);



    generate("predsucc.dat",
             PRED);



    printf("\nData generation completed!\n");



    return 0;

}