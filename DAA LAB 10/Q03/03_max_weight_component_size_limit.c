// Maximum vertex-weight sum among components whose size is at most K.
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *parent;
    int *size;
    long long *weight_sum;
} DSU;

static int find_root(DSU *dsu, int x)
{
    if (dsu->parent[x] != x)
        dsu->parent[x] = find_root(dsu, dsu->parent[x]);
    return dsu->parent[x];
}

static void unite(DSU *dsu, int a, int b)
{
    int root_a = find_root(dsu, a);
    int root_b = find_root(dsu, b);
    if (root_a == root_b)
        return;
    if (dsu->size[root_a] < dsu->size[root_b]) {
        int temp = root_a;
        root_a = root_b;
        root_b = temp;
    }
    dsu->parent[root_b] = root_a;
    dsu->size[root_a] += dsu->size[root_b];
    dsu->weight_sum[root_a] += dsu->weight_sum[root_b];
}

static int read_maximum_eligible(DSU *dsu, int vertices, int limit,
                                 long long *maximum)
{
    int found = 0;
    for (int v = 0; v < vertices; v++) {
        if (dsu->parent[v] == v && dsu->size[v] <= limit) {
            if (!found || dsu->weight_sum[v] > *maximum) {
                *maximum = dsu->weight_sum[v];
                found = 1;
            }
        }
    }
    return found;
}

int main(void)
{
    int vertices, edge_count, limit;
    if (scanf("%d %d %d", &vertices, &edge_count, &limit) != 3 ||
        vertices <= 0 || edge_count < 0 || limit < 0) {
        fprintf(stderr, "Expected: V E K, with V positive and E, K nonnegative.\n");
        return 1;
    }

    DSU dsu;
    dsu.parent = (int *)malloc((size_t)vertices * sizeof(int));
    dsu.size = (int *)malloc((size_t)vertices * sizeof(int));
    dsu.weight_sum = (long long *)malloc((size_t)vertices * sizeof(long long));
    if (!dsu.parent || !dsu.size || !dsu.weight_sum) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(dsu.parent);
        free(dsu.size);
        free(dsu.weight_sum);
        return 1;
    }

    for (int v = 0; v < vertices; v++) {
        if (scanf("%lld", &dsu.weight_sum[v]) != 1) {
            fprintf(stderr, "Could not read weight for vertex %d.\n", v + 1);
            free(dsu.parent);
            free(dsu.size);
            free(dsu.weight_sum);
            return 1;
        }
        dsu.parent[v] = v;
        dsu.size[v] = 1;
    }

    for (int i = 0; i < edge_count; i++) {
        int u, v;
        long long edge_weight;
        if (scanf("%d %d %lld", &u, &v, &edge_weight) != 3 ||
            u < 1 || u > vertices ||
            v < 1 || v > vertices) {
            fprintf(stderr, "Invalid edge at position %d; vertices are 1-based.\n", i + 1);
            free(dsu.parent);
            free(dsu.size);
            free(dsu.weight_sum);
            return 1;
        }
        /* Edge weights do not affect connectedness or the vertex-weight sum. */
        (void)edge_weight;
        unite(&dsu, u - 1, v - 1);

        long long maximum = 0;
        printf("After edge %d: ", i + 1);
        if (read_maximum_eligible(&dsu, vertices, limit, &maximum))
            printf("%lld\n", maximum);
        else
            puts("NONE");
    }

    free(dsu.parent);
    free(dsu.size);
    free(dsu.weight_sum);
    return 0;
}
