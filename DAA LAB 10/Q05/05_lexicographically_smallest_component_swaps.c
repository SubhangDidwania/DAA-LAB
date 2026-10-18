// Lexicographically smallest permutation reachable by swaps along graph edges.
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int root;
    int key;
} Record;

typedef struct {
    int *parent;
    int *size;
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
}

static int compare_records(const void *left, const void *right)
{
    const Record *a = (const Record *)left;
    const Record *b = (const Record *)right;
    if (a->root < b->root) return -1;
    if (a->root > b->root) return 1;
    if (a->key < b->key) return -1;
    if (a->key > b->key) return 1;
    return 0;
}

int main(void)
{
    int n, edge_count;
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Expected a positive permutation size.\n");
        return 1;
    }

    int *permutation = (int *)malloc((size_t)n * sizeof(int));
    int *result = (int *)malloc((size_t)n * sizeof(int));
    unsigned char *seen = (unsigned char *)calloc((size_t)n, 1);
    DSU dsu;
    dsu.parent = (int *)malloc((size_t)n * sizeof(int));
    dsu.size = (int *)malloc((size_t)n * sizeof(int));
    Record *positions = (Record *)malloc((size_t)n * sizeof(Record));
    Record *values = (Record *)malloc((size_t)n * sizeof(Record));
    if (!permutation || !result || !seen || !dsu.parent || !dsu.size ||
        !positions || !values) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(permutation); free(result); free(seen); free(dsu.parent);
        free(dsu.size); free(positions); free(values);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int value;
        if (scanf("%d", &value) != 1 || value < 1 || value > n || seen[value - 1]) {
            fprintf(stderr, "Input must be a permutation of 1..n.\n");
            free(permutation); free(result); free(seen); free(dsu.parent);
            free(dsu.size); free(positions); free(values);
            return 1;
        }
        permutation[i] = value;
        seen[value - 1] = 1;
        dsu.parent[i] = i;
        dsu.size[i] = 1;
    }
    free(seen);

    if (scanf("%d", &edge_count) != 1 || edge_count < 0) {
        fprintf(stderr, "Expected a nonnegative edge count.\n");
        free(permutation); free(result); free(dsu.parent);
        free(dsu.size); free(positions); free(values);
        return 1;
    }
    for (int i = 0; i < edge_count; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v) != 2 || u < 1 || u > n || v < 1 || v > n) {
            fprintf(stderr, "Invalid edge at position %d; vertices are 1-based.\n", i + 1);
            free(permutation); free(result); free(dsu.parent);
            free(dsu.size); free(positions); free(values);
            return 1;
        }
        unite(&dsu, u - 1, v - 1);
    }

    for (int i = 0; i < n; i++) {
        int root = find_root(&dsu, i);
        positions[i].root = root;
        positions[i].key = i;
        values[i].root = root;
        values[i].key = permutation[i];
    }
    qsort(positions, (size_t)n, sizeof(Record), compare_records);
    qsort(values, (size_t)n, sizeof(Record), compare_records);

    for (int i = 0; i < n; i++)
        result[positions[i].key] = values[i].key;

    for (int i = 0; i < n; i++)
        printf("%s%d", i == 0 ? "" : " ", result[i]);
    putchar('\n');

    free(permutation);
    free(result);
    free(dsu.parent);
    free(dsu.size);
    free(positions);
    free(values);
    return 0;
}
