#include <stdio.h>
#include <string.h>

int findTransition(char arr[], int n)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == '1')
        {
            if (mid == 0 || arr[mid - 1] == '0')
                return mid;

            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{   
    char arr[100];

    printf("Enter array: ");
    scanf("%s", arr);

    int n = strlen(arr);

    int index = findTransition(arr, n);

    if (index == -1)
        printf("No transition point found.\n");
    else
        printf("Transition point is at index %d\n", index);

    return 0;
}