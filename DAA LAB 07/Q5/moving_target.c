#include <stdio.h>

int main(void) {
    int spots;
    printf("Enter the number of hiding spots: ");
    fflush(stdout);
    if (scanf("%d", &spots) != 1 || spots < 2) {
        fprintf(stderr, "Enter at least two hiding spots.\n");
        return 1;
    }

    if (spots == 2) {
        printf("Guaranteed strategy in 2 shots: 1 1\n");
        return 0;
    }

    printf("Guaranteed strategy in %d shots:\n", 2 * spots - 4);
    for (int shot = 2; shot <= spots - 1; ++shot) printf("%d ", shot);
    for (int shot = spots - 1; shot >= 2; --shot) printf("%d ", shot);
    putchar('\n');
    return 0;
}