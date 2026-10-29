#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(NULL));

    // Generate random numbers
    printf("\nGenerated Array:\n");
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand() % 20;   // Numbers between 0 and 19
        printf("%d ", arr[i]);
    }

    printf("\n");

    // Check for duplicates
    int duplicate = 0;
    // Use a small seen array to avoid printing the same duplicate value more than once
    int seen[20] = {0}; // values are between 0 and 19

    printf("\nDuplicate elements found: ");

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j] && !seen[arr[i]])
            {
                duplicate++;
                seen[arr[i]] = 1;
                printf("%d ", arr[i]);
            }
        }
    }
    printf("\n");

    if(!duplicate)
    {
        printf("\nAll elements are unique.\n");
    }

    return 0;
}