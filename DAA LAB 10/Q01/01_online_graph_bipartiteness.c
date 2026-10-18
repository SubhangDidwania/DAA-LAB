// Online bipartiteness testing using a parity (XOR) disjoint-set union.
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *parent;
    int *rank;
    int *parity; /* XOR-color difference from this vertex to its parent. */
} DSU;

static int find_root(DSU *dsu, int x)
{
    if (dsu->parent[x] != x) {
        int old_parent = dsu->parent[x];
        dsu->parent[x] = find_root(dsu, old_parent);
        dsu->parity[x] ^= dsu->parity[old_parent];
    }
    return dsu->parent[x];
}

/* Enforce that u and v have opposite colors. */
static int add_opposite_constraint(DSU *dsu, int u, int v)
{
    int root_u = find_root(dsu, u);
    int parity_u = dsu->parity[u];
    int root_v = find_root(dsu, v);
    int parity_v = dsu->parity[v];

    if (root_u == root_v)
        return (parity_u ^ parity_v) == 1;

    if (dsu->rank[root_u] < dsu->rank[root_v]) {
        dsu->parent[root_u] = root_v;
        dsu->parity[root_u] = parity_u ^ parity_v ^ 1;
    } else {
        dsu->parent[root_v] = root_u;
        dsu->parity[root_v] = parity_u ^ parity_v ^ 1;
        if (dsu->rank[root_u] == dsu->rank[root_v])
            dsu->rank[root_u]++;
    }
    return 1;
}

int main(void)
{
    int vertices, edge_count;
    if (scanf("%d %d", &vertices, &edge_count) != 2 ||
        vertices <= 0 || edge_count < 0) {
        fprintf(stderr, "Expected: positive vertex count and nonnegative edge count.\n");
        return 1;
    }

    DSU dsu;
    dsu.parent = (int *)malloc((size_t)vertices * sizeof(int));
    dsu.rank = (int *)calloc((size_t)vertices, sizeof(int));
    dsu.parity = (int *)calloc((size_t)vertices, sizeof(int));
    if (!dsu.parent || !dsu.rank || !dsu.parity) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(dsu.parent);
        free(dsu.rank);
        free(dsu.parity);
        return 1;
    }
    for (int i = 0; i < vertices; i++)
        dsu.parent[i] = i;

    for (int i = 0; i < edge_count; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v) != 2 || u < 1 || u > vertices ||
            v < 1 || v > vertices) {
            fprintf(stderr, "Invalid edge at position %d; vertices are 1-based.\n", i + 1);
            free(dsu.parent);
            free(dsu.rank);
            free(dsu.parity);
            return 1;
        }
        --u;
        --v;

        if (add_opposite_constraint(&dsu, u, v))
            printf("Edge (%d, %d): accepted\n", u + 1, v + 1);
        else
            printf("Edge (%d, %d): rejected (would violate bipartiteness)\n",
                   u + 1, v + 1);
    }
    puts("The retained graph is bipartite.");

    free(dsu.parent);
    free(dsu.rank);
    free(dsu.parity);
    return 0;
}
