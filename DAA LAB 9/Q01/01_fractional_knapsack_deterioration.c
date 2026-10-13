// Problem 1: Fractional Knapsack with Deterioration Rate
// This program greedily picks the item with the best effective density at each step and fills the knapsack fractionally.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Each item stores its value, weight, deterioration rate, and remaining weight.

typedef struct {
    double value;
    double weight;
    double rate;
    double remaining;
} Item;

// Main routine: read inputs, run the greedy selection process, and print the maximum value.

int main() {
    int n;
    double capacity;
    scanf("%d %lf", &n, &capacity);

    Item items[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf", &items[i].value, &items[i].weight, &items[i].rate);
        items[i].remaining = items[i].weight;
    }

    double elapsedTime = 0.0;
    double totalValue = 0.0;

    while (capacity > 1e-9) {
        int best = -1;
        double bestDensity = -1e18;

        for (int i = 0; i < n; i++) {
            if (items[i].remaining <= 1e-9) continue;
            double density = (items[i].value / items[i].weight) - (items[i].rate * elapsedTime);
            if (density > bestDensity) {
                bestDensity = density;
                best = i;
            }
        }

        if (best == -1 || bestDensity <= 0.0) {
            break;
        }

        double take = items[best].remaining;
        if (take > capacity) take = capacity;

        totalValue += take * ((items[best].value / items[best].weight) - (items[best].rate * elapsedTime));
        items[best].remaining -= take;
        capacity -= take;
        elapsedTime += take;
    }

    printf("Maximum total value: %.2f\n", totalValue);
    return 0;
}
