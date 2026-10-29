#include <stdio.h>

int moves = 0;

// Recursive function
void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        moves++;
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);

    printf("Move disk %d from %c to %c\n", n, source, destination);
    moves++;

    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'B', 'C');

    printf("\nTotal Moves = %d\n", moves);

    FILE *fp = fopen("toh.dat", "w");

    fprintf(fp, "Disks Moves\n");

    for(int n = 1; n <= 20; n++)
    {
        long long moves = (1LL << n) - 1;   // 2^n - 1
        fprintf(fp, "%d %lld\n", n, moves);
    }

    fclose(fp);

    printf("Data generated successfully.\n");


    return 0;
}
