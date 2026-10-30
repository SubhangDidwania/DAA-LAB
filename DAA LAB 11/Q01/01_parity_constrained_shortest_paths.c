/* Minimum path cost with a terminal penalty for an odd number of 1-edges. */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *to;
    int *weight;
    int *next;
    int *head;
    int edge_count;
} Graph;

typedef struct {
    int state;
    long long distance;
} QueueItem;

typedef struct {
    QueueItem *items;
    size_t capacity;
    size_t head;
    size_t size;
} Deque;

static int deque_grow(Deque *deque)
{
    size_t new_capacity = deque->capacity ? deque->capacity * 2 : 16;
    QueueItem *new_items;

    if (new_capacity < deque->capacity ||
        new_capacity > (size_t)-1 / sizeof(QueueItem))
        return 0;
    new_items = (QueueItem *)malloc(new_capacity * sizeof(QueueItem));
    if (!new_items)
        return 0;

    for (size_t i = 0; i < deque->size; i++)
        new_items[i] = deque->items[(deque->head + i) % deque->capacity];
    free(deque->items);
    deque->items = new_items;
    deque->capacity = new_capacity;
    deque->head = 0;
    return 1;
}

static int deque_push_front(Deque *deque, QueueItem item)
{
    if (deque->size == deque->capacity && !deque_grow(deque))
        return 0;
    deque->head = (deque->head + deque->capacity - 1) % deque->capacity;
    deque->items[deque->head] = item;
    deque->size++;
    return 1;
}

static int deque_push_back(Deque *deque, QueueItem item)
{
    size_t index;
    if (deque->size == deque->capacity && !deque_grow(deque))
        return 0;
    index = (deque->head + deque->size) % deque->capacity;
    deque->items[index] = item;
    deque->size++;
    return 1;
}

static QueueItem deque_pop_front(Deque *deque)
{
    QueueItem item = deque->items[deque->head];
    deque->head = (deque->head + 1) % deque->capacity;
    deque->size--;
    return item;
}

int main(void)
{
    int vertices, edge_count, source;
    long long penalty;
    Graph graph = {0};
    long long *distance = NULL;
    Deque deque = {0};
    int status = 1;
    const long long infinity = LLONG_MAX;

    if (scanf("%d %d %d %lld", &vertices, &edge_count, &source, &penalty) != 4 ||
        vertices <= 0 || edge_count < 0 || source < 1 || source > vertices ||
        penalty < 0) {
        fprintf(stderr, "Expected: V>0, E>=0, source in [1,V], and C>=0.\n");
        return 1;
    }

    graph.head = (int *)malloc((size_t)vertices * sizeof(int));
    graph.to = edge_count ? (int *)malloc((size_t)edge_count * sizeof(int)) : NULL;
    graph.weight = edge_count ? (int *)malloc((size_t)edge_count * sizeof(int)) : NULL;
    graph.next = edge_count ? (int *)malloc((size_t)edge_count * sizeof(int)) : NULL;
    distance = (long long *)malloc((size_t)vertices * 2 * sizeof(long long));
    if (!graph.head || (edge_count && (!graph.to || !graph.weight || !graph.next)) ||
        !distance) {
        fprintf(stderr, "Memory allocation failed.\n");
        goto cleanup;
    }
    for (int i = 0; i < vertices; i++)
        graph.head[i] = -1;

    for (int i = 0; i < edge_count; i++) {
        int u, v, weight;
        if (scanf("%d %d %d", &u, &v, &weight) != 3 ||
            u < 1 || u > vertices || v < 1 || v > vertices ||
            (weight != 0 && weight != 1)) {
            fprintf(stderr, "Invalid directed edge %d; expected u v w with w in {0,1}.\n",
                    i + 1);
            goto cleanup;
        }
        graph.to[i] = v - 1;
        graph.weight[i] = weight;
        graph.next[i] = graph.head[u - 1];
        graph.head[u - 1] = i;
    }
    graph.edge_count = edge_count;

    for (int i = 0; i < vertices * 2; i++)
        distance[i] = infinity;
    distance[(source - 1) * 2] = 0;
    if (!deque_push_front(&deque, (QueueItem){(source - 1) * 2, 0})) {
        fprintf(stderr, "Memory allocation failed for the 0-1 BFS deque.\n");
        goto cleanup;
    }

    while (deque.size) {
        QueueItem current = deque_pop_front(&deque);
        int vertex = current.state / 2;
        int parity = current.state % 2;

        if (current.distance != distance[current.state])
            continue;

        for (int edge = graph.head[vertex]; edge != -1; edge = graph.next[edge]) {
            int next_parity = parity ^ graph.weight[edge];
            int next_state = graph.to[edge] * 2 + next_parity;
            long long candidate = current.distance + graph.weight[edge];
            if (candidate < distance[next_state]) {
                QueueItem item = {next_state, candidate};
                distance[next_state] = candidate;
                if (graph.weight[edge] == 0) {
                    if (!deque_push_front(&deque, item)) {
                        fprintf(stderr, "Memory allocation failed for the 0-1 BFS deque.\n");
                        goto cleanup;
                    }
                } else if (!deque_push_back(&deque, item)) {
                    fprintf(stderr, "Memory allocation failed for the 0-1 BFS deque.\n");
                    goto cleanup;
                }
            }
        }
    }

    puts("Vertex MinimumCost");
    for (int vertex = 0; vertex < vertices; vertex++) {
        long long even_cost = distance[vertex * 2];
        long long odd_cost = distance[vertex * 2 + 1];
        if (odd_cost != infinity) {
            if (penalty <= LLONG_MAX - odd_cost)
                odd_cost += penalty;
            else
                odd_cost = infinity;
        }
        if (even_cost == infinity && odd_cost == infinity)
            printf("%d UNREACHABLE\n", vertex + 1);
        else
            printf("%d %lld\n", vertex + 1,
                   even_cost < odd_cost ? even_cost : odd_cost);
    }
    status = 0;

cleanup:
    free(graph.head);
    free(graph.to);
    free(graph.weight);
    free(graph.next);
    free(distance);
    free(deque.items);
    return status;
}
