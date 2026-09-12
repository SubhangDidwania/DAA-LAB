#include <stdio.h>
#include <limits.h>

#define MAX_MATRICES 100

static int cost[MAX_MATRICES + 1][MAX_MATRICES + 1];
static int split[MAX_MATRICES + 1][MAX_MATRICES + 1];

static void print_order(int first, int last) {
    if (first == last) {
        printf("A%d", first);
        return;
    }
    putchar('(');
    print_order(first, split[first][last]);
    print_order(split[first][last] + 1, last);
    putchar(')');
}

int main(void) {
    int matrices;
    printf("Enter the number of matrices: ");
    fflush(stdout);
    if (scanf("%d", &matrices) != 1 || matrices < 1 || matrices > MAX_MATRICES) return 1;
    int dimensions[MAX_MATRICES + 1];
    printf("Enter %d matrix dimensions: ", matrices + 1);
    fflush(stdout);
    for (int i = 0; i <= matrices; ++i) {
        if (scanf("%d", &dimensions[i]) != 1 || dimensions[i] <= 0) return 1;
    }

    for (int length = 2; length <= matrices; ++length) {
        for (int first = 1; first + length - 1 <= matrices; ++first) {
            int last = first + length - 1;
            cost[first][last] = INT_MAX;
            for (int middle = first; middle < last; ++middle) {
                int candidate = cost[first][middle] + cost[middle + 1][last]
                    + dimensions[first - 1] * dimensions[middle] * dimensions[last];
                if (candidate < cost[first][last]) {
                    cost[first][last] = candidate;
                    split[first][last] = middle;
                }
            }
        }
    }

    printf("Minimum scalar multiplications: %d\nOrder: ", cost[1][matrices]);
    print_order(1, matrices);
    putchar('\n');
    return 0;
}