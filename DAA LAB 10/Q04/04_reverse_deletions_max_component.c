// Offline vertex-deletion queries, solved by activating vertices in reverse.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    int *parent;
    int *size;
    long long *sum;
    int *generation;
    unsigned char *active;
} DSU;

typedef struct {
    long long sum;
    int root;
    int generation;
} HeapEntry;

typedef struct {
    HeapEntry *items;
    int count;
    int capacity;
} MaxHeap;

static int find_root(DSU *dsu, int x)
{
    if (dsu->parent[x] != x)
        dsu->parent[x] = find_root(dsu, dsu->parent[x]);
    return dsu->parent[x];
}

static int greater_entry(HeapEntry a, HeapEntry b)
{
    return a.sum > b.sum;
}

static void heap_push(MaxHeap *heap, HeapEntry entry)
{
    int child = heap->count++;
    while (child > 0) {
        int parent = (child - 1) / 2;
        if (!greater_entry(entry, heap->items[parent]))
            break;
        heap->items[child] = heap->items[parent];
        child = parent;
    }
    heap->items[child] = entry;
}

static HeapEntry heap_pop(MaxHeap *heap)
{
    HeapEntry result = heap->items[0];
    HeapEntry last = heap->items[--heap->count];
    if (heap->count == 0)
        return result;

    int parent = 0;
    while (parent * 2 + 1 < heap->count) {
        int child = parent * 2 + 1;
        if (child + 1 < heap->count &&
            greater_entry(heap->items[child + 1], heap->items[child]))
            child++;
        if (!greater_entry(heap->items[child], last))
            break;
        heap->items[parent] = heap->items[child];
        parent = child;
    }
    heap->items[parent] = last;
    return result;
}

static void push_component(DSU *dsu, MaxHeap *heap, int root)
{
    HeapEntry entry;
    entry.sum = dsu->sum[root];
    entry.root = root;
    entry.generation = dsu->generation[root];
    heap_push(heap, entry);
}

static void unite(DSU *dsu, MaxHeap *heap, int a, int b)
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
    dsu->generation[root_b]++;
    dsu->generation[root_a]++;
    dsu->size[root_a] += dsu->size[root_b];
    dsu->sum[root_a] += dsu->sum[root_b];
    push_component(dsu, heap, root_a);
}

static int current_maximum(DSU *dsu, MaxHeap *heap, long long *answer)
{
    while (heap->count > 0) {
        HeapEntry top = heap->items[0];
        if (dsu->active[top.root] &&
            dsu->parent[top.root] == top.root &&
            dsu->generation[top.root] == top.generation) {
            *answer = top.sum;
            return 1;
        }
        (void)heap_pop(heap);
    }
    return 0;
}

int main(void)
{
    int vertices, edge_count;
    if (scanf("%d %d", &vertices, &edge_count) != 2 ||
        vertices <= 0 || edge_count < 0 || vertices > (INT32_MAX - 1) / 2) {
        fprintf(stderr, "Expected a positive vertex count and nonnegative edge count.\n");
        return 1;
    }

    DSU dsu;
    dsu.parent = (int *)malloc((size_t)vertices * sizeof(int));
    dsu.size = (int *)malloc((size_t)vertices * sizeof(int));
    dsu.sum = (long long *)malloc((size_t)vertices * sizeof(long long));
    dsu.generation = (int *)calloc((size_t)vertices, sizeof(int));
    dsu.active = (unsigned char *)calloc((size_t)vertices, 1);
    int *head = (int *)malloc((size_t)vertices * sizeof(int));
    int *to = (int *)malloc((size_t)(2 * edge_count) * sizeof(int));
    int *next = (int *)malloc((size_t)(2 * edge_count) * sizeof(int));
    int *order = (int *)malloc((size_t)vertices * sizeof(int));
    long long *answer = (long long *)malloc((size_t)vertices * sizeof(long long));
    unsigned char *has_answer = (unsigned char *)calloc((size_t)vertices, 1);
    MaxHeap heap;
    heap.count = 0;
    heap.capacity = 2 * vertices;
    heap.items = (HeapEntry *)malloc((size_t)heap.capacity * sizeof(HeapEntry));

    if (!dsu.parent || !dsu.size || !dsu.sum || !dsu.generation ||
        !dsu.active || !head || (edge_count > 0 && (!to || !next)) ||
        !order || !answer || !has_answer || !heap.items) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(dsu.parent); free(dsu.size); free(dsu.sum); free(dsu.generation);
        free(dsu.active); free(head); free(to); free(next); free(order);
        free(answer); free(has_answer); free(heap.items);
        return 1;
    }

    for (int v = 0; v < vertices; v++) {
        if (scanf("%lld", &dsu.sum[v]) != 1) {
            fprintf(stderr, "Could not read weight for vertex %d.\n", v + 1);
            free(dsu.parent); free(dsu.size); free(dsu.sum); free(dsu.generation);
            free(dsu.active); free(head); free(to); free(next); free(order);
            free(answer); free(has_answer); free(heap.items);
            return 1;
        }
        dsu.parent[v] = v;
        dsu.size[v] = 1;
        head[v] = -1;
    }

    int edge_index = 0;
    for (int i = 0; i < edge_count; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v) != 2 || u < 1 || u > vertices ||
            v < 1 || v > vertices) {
            fprintf(stderr, "Invalid edge at position %d; vertices are 1-based.\n", i + 1);
            free(dsu.parent); free(dsu.size); free(dsu.sum); free(dsu.generation);
            free(dsu.active); free(head); free(to); free(next); free(order);
            free(answer); free(has_answer); free(heap.items);
            return 1;
        }
        --u;
        --v;
        to[edge_index] = v;
        next[edge_index] = head[u];
        head[u] = edge_index++;
        to[edge_index] = u;
        next[edge_index] = head[v];
        head[v] = edge_index++;
    }

    unsigned char *seen = (unsigned char *)calloc((size_t)vertices, 1);
    if (!seen) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(dsu.parent); free(dsu.size); free(dsu.sum); free(dsu.generation);
        free(dsu.active); free(head); free(to); free(next); free(order);
        free(answer); free(has_answer); free(heap.items);
        return 1;
    }
    for (int i = 0; i < vertices; i++) {
        int v;
        if (scanf("%d", &v) != 1 || v < 1 || v > vertices || seen[v - 1]) {
            fprintf(stderr, "Deletion order must be a permutation of 1..V.\n");
            free(seen);
            free(dsu.parent); free(dsu.size); free(dsu.sum); free(dsu.generation);
            free(dsu.active); free(head); free(to); free(next); free(order);
            free(answer); free(has_answer); free(heap.items);
            return 1;
        }
        order[i] = v - 1;
        seen[v - 1] = 1;
    }
    free(seen);

    /* Before activating p_i, the structure represents the state after
       deleting p_1,...,p_(i+1), exactly the requested answer for step i+1. */
    for (int i = vertices - 1; i >= 0; i--) {
        has_answer[i] = (unsigned char)current_maximum(&dsu, &heap, &answer[i]);

        int v = order[i];
        dsu.active[v] = 1;
        dsu.parent[v] = v;
        dsu.size[v] = 1;
        dsu.generation[v]++;
        push_component(&dsu, &heap, v);

        for (int e = head[v]; e != -1; e = next[e]) {
            int neighbor = to[e];
            if (dsu.active[neighbor])
                unite(&dsu, &heap, v, neighbor);
        }
    }

    for (int i = 0; i < vertices; i++) {
        printf("After deleting %d: ", order[i] + 1);
        if (has_answer[i])
            printf("%lld\n", answer[i]);
        else
            puts("NONE");
    }

    free(dsu.parent); free(dsu.size); free(dsu.sum); free(dsu.generation);
    free(dsu.active); free(head); free(to); free(next); free(order);
    free(answer); free(has_answer); free(heap.items);
    return 0;
}
