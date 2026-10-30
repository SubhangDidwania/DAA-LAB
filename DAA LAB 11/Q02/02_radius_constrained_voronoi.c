/* Multi-source BFS with deterministic (smallest hub index) tie-breaking. */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *to;
    int *next;
    int *head;
} Graph;

int main(void)
{
    int vertices, edge_count, hub_count, radius;
    Graph graph = {0};
    int *distance = NULL, *owner = NULL, *queue = NULL, *seen_hub = NULL;
    int status = 1;

    if (scanf("%d %d %d %d", &vertices, &edge_count, &hub_count, &radius) != 4 ||
        vertices <= 0 || edge_count < 0 || hub_count < 0 ||
        hub_count > vertices || radius < 0) {
        fprintf(stderr, "Expected V>0, E>=0, 0<=K<=V, and R>=0.\n");
        return 1;
    }

    graph.head = (int *)malloc((size_t)vertices * sizeof(int));
    graph.to = edge_count ? (int *)malloc((size_t)edge_count * 2 * sizeof(int)) : NULL;
    graph.next = edge_count ? (int *)malloc((size_t)edge_count * 2 * sizeof(int)) : NULL;
    distance = (int *)malloc((size_t)vertices * sizeof(int));
    owner = (int *)malloc((size_t)vertices * sizeof(int));
    queue = (int *)malloc((size_t)vertices * sizeof(int));
    seen_hub = (int *)calloc((size_t)vertices, sizeof(int));
    if (!graph.head || (edge_count && (!graph.to || !graph.next)) ||
        !distance || !owner || !queue || !seen_hub) {
        fprintf(stderr, "Memory allocation failed.\n");
        goto cleanup;
    }
    for (int i = 0; i < vertices; i++) {
        graph.head[i] = -1;
        distance[i] = -1;
        owner[i] = -1;
    }

    /* Hubs are read and queued by increasing label, which resolves ties. */
    int tail = 0;
    for (int index = 1; index <= hub_count; index++) {
        int hub;
        if (scanf("%d", &hub) != 1 || hub < 1 || hub > vertices ||
            seen_hub[hub - 1]) {
            fprintf(stderr, "Invalid or duplicate hub at index %d.\n", index);
            goto cleanup;
        }
        seen_hub[hub - 1] = 1;
        distance[hub - 1] = 0;
        owner[hub - 1] = index;
        queue[tail++] = hub - 1;
    }

    for (int i = 0; i < edge_count; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v) != 2 || u < 1 || u > vertices ||
            v < 1 || v > vertices) {
            fprintf(stderr, "Invalid undirected edge %d; vertices are 1-based.\n", i + 1);
            goto cleanup;
        }
        graph.to[2 * i] = v - 1;
        graph.next[2 * i] = graph.head[u - 1];
        graph.head[u - 1] = 2 * i;
        graph.to[2 * i + 1] = u - 1;
        graph.next[2 * i + 1] = graph.head[v - 1];
        graph.head[v - 1] = 2 * i + 1;
    }

    int front = 0;
    while (front < tail) {
        int vertex = queue[front++];
        for (int edge = graph.head[vertex]; edge != -1; edge = graph.next[edge]) {
            int neighbor = graph.to[edge];
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[vertex] + 1;
                owner[neighbor] = owner[vertex];
                queue[tail++] = neighbor;
            }
        }
    }

    puts("Vertex Owner Distance");
    for (int vertex = 0; vertex < vertices; vertex++) {
        int assigned_owner = (distance[vertex] >= 0 && distance[vertex] <= radius)
                                 ? owner[vertex]
                                 : -1;
        printf("%d %d %d\n", vertex + 1, assigned_owner, distance[vertex]);
    }
    status = 0;

cleanup:
    free(graph.head);
    free(graph.to);
    free(graph.next);
    free(distance);
    free(owner);
    free(queue);
    free(seen_hub);
    return status;
}
