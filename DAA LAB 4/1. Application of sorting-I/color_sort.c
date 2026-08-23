#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int number;
    char colour;
} Item;

void sortByColour(Item input[], Item output[], int n)
{
    Item *red = malloc(n * sizeof(Item));
    Item *blue = malloc(n * sizeof(Item));
    Item *yellow = malloc(n * sizeof(Item));

    int nr = 0, nb = 0, ny = 0;
    int k = 0;

    // Divide the input into three colour arrays
    for (int i = 0; i < n; i++) {
        if (input[i].colour == 'R' || input[i].colour == 'r')
            red[nr++] = input[i];

        else if (input[i].colour == 'B' || input[i].colour == 'b')
            blue[nb++] = input[i];

        else if (input[i].colour == 'Y' || input[i].colour == 'y')
            yellow[ny++] = input[i];

        else {
            printf("Invalid colour: %c\n", input[i].colour);
            exit(1);
        }
    }

    // Combine: Red -> Blue -> Yellow
    for (int i = 0; i < nr; i++)
        output[k++] = red[i];

    for (int i = 0; i < nb; i++)
        output[k++] = blue[i];

    for (int i = 0; i < ny; i++)
        output[k++] = yellow[i];

    free(red);
    free(blue);
    free(yellow);
}

// Validation function to check if numbers are sorted
int isSortedByNumber(Item input[], int n)
{
    for (int i = 1; i < n; i++) {
        if (input[i].number < input[i - 1].number)
            return 0;
    }

    return 1;
}

int main()
{
    int n;

    printf("Enter number of pairs: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of pairs must be positive.\n");
        return 1;
    }

    Item *input = malloc(n * sizeof(Item));
    Item *output = malloc(n * sizeof(Item));

    printf("\nEnter %d pairs (number colour):\n", n);
    printf("Use R for Red, B for Blue, Y for Yellow.\n\n");

    for (int i = 0; i < n; i++) {
        printf("Pair %d: ", i + 1);
        scanf("%d %c", &input[i].number, &input[i].colour);
    }

    // Check whether numbers are sorted
    if (!isSortedByNumber(input, n)) {
        printf("\nValidation FAILED!\n");
        printf("The numbers are not sorted in ascending order.\n");
        printf("Please enter the numbers in sorted order.\n");

        free(input);
        free(output);
        return 1;
    }

    printf("\nValidation PASSED!\n");
    printf("The numbers are sorted in ascending order.\n");

    // Sort by colour
    sortByColour(input, output, n);

    printf("\nSorted by colour:\n");

    for (int i = 0; i < n; i++) {
        printf("(%d, %c) ", output[i].number, output[i].colour);
    }

    printf("\n");

    free(input);
    free(output);

    return 0;
}