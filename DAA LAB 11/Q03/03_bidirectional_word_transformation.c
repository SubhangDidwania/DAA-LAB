/* Bidirectional BFS on an implicit word graph (one-character mutations). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **words;
    int count;
    int length;
    int *slots;
    size_t slot_count;
} WordSet;

static unsigned long word_hash(const char *word, int length)
{
    unsigned long hash = 2166136261UL;
    for (int i = 0; i < length; i++) {
        hash ^= (unsigned char)word[i];
        hash *= 16777619UL;
    }
    return hash;
}

static int find_word(const WordSet *set, const char *word)
{
    size_t slot = word_hash(word, set->length) & (set->slot_count - 1);
    while (set->slots[slot] != -1) {
        int id = set->slots[slot];
        if (memcmp(set->words[id], word, (size_t)set->length) == 0)
            return id;
        slot = (slot + 1) & (set->slot_count - 1);
    }
    return -1;
}

static void insert_word(WordSet *set, int id)
{
    size_t slot = word_hash(set->words[id], set->length) & (set->slot_count - 1);
    while (set->slots[slot] != -1)
        slot = (slot + 1) & (set->slot_count - 1);
    set->slots[slot] = id;
}

static int valid_word(const char *word, int length)
{
    if ((int)strlen(word) != length)
        return 0;
    for (int i = 0; i < length; i++)
        if (word[i] < 'a' || word[i] > 'z')
            return 0;
    return 1;
}

static int expand_layer(const WordSet *set, int **frontier, int *frontier_count,
                        int **next_frontier, int *next_count, int *this_distance,
                        const int *other_distance, int *best)
{
    int length = set->length;
    *next_count = 0;

    for (int i = 0; i < *frontier_count; i++) {
        int current = (*frontier)[i];
        char candidate_word[11];
        memcpy(candidate_word, set->words[current], (size_t)length + 1);

        if (other_distance[current] >= 0) {
            int candidate = this_distance[current] + other_distance[current];
            if (*best < 0 || candidate < *best)
                *best = candidate;
        }

        for (int position = 0; position < length; position++) {
            char original = candidate_word[position];
            for (char letter = 'a'; letter <= 'z'; letter++) {
                int neighbor, candidate_distance;
                if (letter == original)
                    continue;
                candidate_word[position] = letter;
                neighbor = find_word(set, candidate_word);
                if (neighbor < 0)
                    continue;

                candidate_distance = this_distance[current] + 1;
                if (other_distance[neighbor] >= 0) {
                    int total = candidate_distance + other_distance[neighbor];
                    if (*best < 0 || total < *best)
                        *best = total;
                }
                if (this_distance[neighbor] < 0) {
                    this_distance[neighbor] = candidate_distance;
                    (*next_frontier)[(*next_count)++] = neighbor;
                }
            }
            candidate_word[position] = original;
        }
    }

    {
        int *temporary = *frontier;
        *frontier = *next_frontier;
        *next_frontier = temporary;
    }
    *frontier_count = *next_count;
    return 1;
}

int main(void)
{
    int dictionary_size, length;
    int answer = -1, start_id, target_id;
    WordSet set = {0};
    int *distance_a = NULL, *distance_b = NULL;
    int *frontier_a = NULL, *frontier_b = NULL;
    int *next_a = NULL, *next_b = NULL;
    int frontier_count_a = 0, frontier_count_b = 0;
    int depth_a = 0, depth_b = 0;
    int status = 1;
    char start[11], target[11], buffer[11];
    size_t slot_count = 1;

    if (scanf("%d %d", &dictionary_size, &length) != 2 ||
        dictionary_size <= 0 || dictionary_size > 100000 ||
        length <= 0 || length > 10) {
        fprintf(stderr, "Expected 1<=N<=100000 and 1<=L<=10.\n");
        return 1;
    }
    set.length = length;
    set.count = dictionary_size;
    while (slot_count < (size_t)(dictionary_size + 1) * 2)
        slot_count *= 2;
    set.slot_count = slot_count;
    set.words = (char **)calloc((size_t)dictionary_size + 1, sizeof(char *));
    set.slots = (int *)malloc(slot_count * sizeof(int));
    if (!set.words || !set.slots) {
        fprintf(stderr, "Memory allocation failed.\n");
        goto cleanup;
    }
    for (size_t i = 0; i < slot_count; i++)
        set.slots[i] = -1;

    for (int i = 0; i < dictionary_size; i++) {
        if (scanf("%10s", buffer) != 1 || !valid_word(buffer, length)) {
            fprintf(stderr, "Invalid dictionary word at position %d.\n", i + 1);
            goto cleanup;
        }
        if (find_word(&set, buffer) >= 0) {
            fprintf(stderr, "Dictionary words must be unique.\n");
            goto cleanup;
        }
        set.words[i] = (char *)malloc((size_t)length + 1);
        if (!set.words[i]) {
            fprintf(stderr, "Memory allocation failed.\n");
            goto cleanup;
        }
        memcpy(set.words[i], buffer, (size_t)length + 1);
        insert_word(&set, i);
    }

    if (scanf("%10s %10s", start, target) != 2 ||
        !valid_word(start, length) || !valid_word(target, length)) {
        fprintf(stderr, "Invalid start or target word.\n");
        goto cleanup;
    }
    target_id = find_word(&set, target);
    if (target_id < 0) {
        fprintf(stderr, "The target word must be in the dictionary.\n");
        goto cleanup;
    }
    start_id = find_word(&set, start);
    if (start_id < 0) {
        start_id = set.count++;
        set.words[start_id] = (char *)malloc((size_t)length + 1);
        if (!set.words[start_id]) {
            fprintf(stderr, "Memory allocation failed.\n");
            goto cleanup;
        }
        memcpy(set.words[start_id], start, (size_t)length + 1);
        insert_word(&set, start_id);
    }

    if (start_id == target_id) {
        puts("Minimum mutations: 0");
        status = 0;
        goto cleanup;
    }

    distance_a = (int *)malloc((size_t)set.count * sizeof(int));
    distance_b = (int *)malloc((size_t)set.count * sizeof(int));
    frontier_a = (int *)malloc((size_t)set.count * sizeof(int));
    frontier_b = (int *)malloc((size_t)set.count * sizeof(int));
    next_a = (int *)malloc((size_t)set.count * sizeof(int));
    next_b = (int *)malloc((size_t)set.count * sizeof(int));
    if (!distance_a || !distance_b || !frontier_a || !frontier_b || !next_a || !next_b) {
        fprintf(stderr, "Memory allocation failed.\n");
        goto cleanup;
    }
    for (int i = 0; i < set.count; i++)
        distance_a[i] = distance_b[i] = -1;
    distance_a[start_id] = 0;
    distance_b[target_id] = 0;
    frontier_a[frontier_count_a++] = start_id;
    frontier_b[frontier_count_b++] = target_id;

    while (frontier_count_a && frontier_count_b) {
        /* Any still-unseen shortest route must cross these explored layers. */
        if (answer >= 0 && depth_a + depth_b >= answer)
            break;
        if (frontier_count_a <= frontier_count_b) {
            int next_count;
            expand_layer(&set, &frontier_a, &frontier_count_a, &next_a, &next_count,
                         distance_a, distance_b, &answer);
            depth_a++;
        } else {
            int next_count;
            expand_layer(&set, &frontier_b, &frontier_count_b, &next_b, &next_count,
                         distance_b, distance_a, &answer);
            depth_b++;
        }
    }

    if (answer >= 0)
        printf("Minimum mutations: %d\n", answer);
    else
        puts("Minimum mutations: -1");
    status = 0;

cleanup:
    if (set.words) {
        for (int i = 0; i < set.count; i++)
            free(set.words[i]);
    }
    free(set.words);
    free(set.slots);
    free(distance_a);
    free(distance_b);
    free(frontier_a);
    free(frontier_b);
    free(next_a);
    free(next_b);
    return status;
}
