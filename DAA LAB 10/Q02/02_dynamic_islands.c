// Number of 4-directionally connected islands after each land addition.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

static int unite(DSU *dsu, int a, int b)
{
    int root_a = find_root(dsu, a);
    int root_b = find_root(dsu, b);
    if (root_a == root_b)
        return 0;
    if (dsu->size[root_a] < dsu->size[root_b]) {
        int temp = root_a;
        root_a = root_b;
        root_b = temp;
    }
    dsu->parent[root_b] = root_a;
    dsu->size[root_a] += dsu->size[root_b];
    return 1;
}

int main(void)
{
    int rows, columns, operations;
    if (scanf("%d %d %d", &rows, &columns, &operations) != 3 ||
        rows <= 0 || columns <= 0 || operations < 0) {
        fprintf(stderr, "Expected positive grid dimensions and nonnegative operation count.\n");
        return 1;
    }
    if ((int64_t)rows * columns > INT32_MAX) {
        fprintf(stderr, "Grid is too large for this implementation.\n");
        return 1;
    }

    int cells = rows * columns;
    DSU dsu;
    dsu.parent = (int *)malloc((size_t)cells * sizeof(int));
    dsu.size = (int *)malloc((size_t)cells * sizeof(int));
    unsigned char *land = (unsigned char *)calloc((size_t)cells, 1);
    if (!dsu.parent || !dsu.size || !land) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(dsu.parent);
        free(dsu.size);
        free(land);
        return 1;
    }
    for (int i = 0; i < cells; i++) {
        dsu.parent[i] = i;
        dsu.size[i] = 1;
    }

    int components = 0;
    for (int step = 0; step < operations; step++) {
        int row, column;
        if (scanf("%d %d", &row, &column) != 2 ||
            row < 1 || row > rows || column < 1 || column > columns) {
            fprintf(stderr, "Invalid cell at operation %d; coordinates are 1-based.\n",
                    step + 1);
            free(dsu.parent);
            free(dsu.size);
            free(land);
            return 1;
        }
        --row;
        --column;
        int cell = row * columns + column;

        if (!land[cell]) {
            land[cell] = 1;
            components++;
            if (row > 0 && land[cell - columns])
                components -= unite(&dsu, cell, cell - columns);
            if (row + 1 < rows && land[cell + columns])
                components -= unite(&dsu, cell, cell + columns);
            if (column > 0 && land[cell - 1])
                components -= unite(&dsu, cell, cell - 1);
            if (column + 1 < columns && land[cell + 1])
                components -= unite(&dsu, cell, cell + 1);
        }
        printf("%s%d", step == 0 ? "" : " ", components);
    }
    putchar('\n');

    free(dsu.parent);
    free(dsu.size);
    free(land);
    return 0;
}
