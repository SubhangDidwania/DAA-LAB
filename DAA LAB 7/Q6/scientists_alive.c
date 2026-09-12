#include <stdio.h>
#include <stdlib.h>

typedef struct { int year; int delta; } Event;

static int compare_events(const void *left, const void *right) {
    const Event *a = left;
    const Event *b = right;
    if (a->year != b->year) return a->year - b->year;
    return a->delta - b->delta;
}

int main(void) {
    int scientists;
    printf("Enter the number of scientists: ");
    fflush(stdout);
    if (scanf("%d", &scientists) != 1 || scientists < 1) return 1;
    Event *events = malloc((size_t)2 * scientists * sizeof(*events));
    if (!events) return 1;

    for (int i = 0; i < scientists; ++i) {
        int birth, death;
        printf("Enter birth and death years for scientist %d: ", i + 1);
        fflush(stdout);
        if (scanf("%d %d", &birth, &death) != 2 || birth > death) {
            free(events);
            return 1;
        }
        events[2 * i] = (Event){birth, 1};
        events[2 * i + 1] = (Event){death, -1};
    }

    qsort(events, (size_t)2 * scientists, sizeof(*events), compare_events);
    int alive = 0, maximum = 0, best_year = events[0].year;
    for (int i = 0; i < 2 * scientists; ++i) {
        alive += events[i].delta;
        if (alive > maximum) {
            maximum = alive;
            best_year = events[i].year;
        }
    }

    printf("Maximum alive: %d\nYear: %d\n", maximum, best_year);
    free(events);
    return 0;
}