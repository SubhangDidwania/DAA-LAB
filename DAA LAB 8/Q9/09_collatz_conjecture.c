#include <stdio.h>
#include <stdbool.h>

void collatzSequence(long long n) {
    printf("Sequence: ");
    while (n != 1) {
        printf("%lld ", n);
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
    }
    printf("1\n");
}

void analyseInterval(long long a, long long b) {
    long long maxLen = 0, maxStart = a;
    for (long long i = a; i <= b; i++) {
        long long x = i;
        long long len = 0;
        while (x != 1) {
            if (x % 2 == 0) {
                x = x / 2;
            } else {
                x = 3 * x + 1;
            }
            len++;
        }
        len++; 
        if (len > maxLen) {
            maxLen = len;
            maxStart = i;
        }
    }
    printf("Starting value with longest trajectory in [%lld, %lld]: %lld\n", a, b, maxStart);
    printf("Length of trajectory: %lld\n", maxLen);
}

int main() {
    int choice;
    printf("1. Single starting value\n2. Interval analysis\nChoose option: ");
    scanf("%d", &choice);

    if (choice == 1) {
        long long n;
        printf("Enter starting value n: ");
        scanf("%lld", &n);
        collatzSequence(n);
    } else if (choice == 2) {
        long long a, b;
        printf("Enter interval [a, b]: ");
        scanf("%lld %lld", &a, &b);
        analyseInterval(a, b);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
