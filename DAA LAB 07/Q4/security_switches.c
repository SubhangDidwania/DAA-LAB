#include <stdio.h>

static int state[63];
static int sequence[2048];
static int sequence_length;
static int generated_moves;
static int sequence_is_legal = 1;

static int minimum_moves(int switches) {
    int power = 1 << (switches + 1);
    return (power - (switches % 2 ? 1 : 2)) / 3;
}

static void toggle(int switch_number, int switches) {
    if (switch_number != switches) {
        if (!state[switch_number + 1]) sequence_is_legal = 0;
        for (int i = switch_number + 2; i <= switches; ++i) {
            if (state[i]) sequence_is_legal = 0;
        }
    }
    state[switch_number] = !state[switch_number];
    ++generated_moves;
}

static void build_sequence(int switches) {
    if (switches % 2) sequence[sequence_length++] = switches;
    if (switches > 1) {
        int start = sequence_length;
        build_sequence(switches - 1);
        int lower_length = sequence_length - start;
        for (int i = lower_length - 1; i >= 0; --i) {
            sequence[start + 2 * i] = sequence[start + i];
            sequence[start + 2 * i + 1] = switches;
        }
        sequence_length += lower_length;
    }
}

static void validate_sequence(int switches) {
    for (int i = 1; i <= switches; ++i) state[i] = 1;
    for (int i = 0; i < sequence_length; ++i) {
        int switch_number = sequence[i];
        toggle(switch_number, switches);
        printf("%d ", switch_number);
    }
}

int main(void) {
    int switches;
    printf("Enter the number of switches: ");
    fflush(stdout);
    if (scanf("%d", &switches) != 1 || switches < 1 || switches > 29) {
        fprintf(stderr, "Enter a number of switches from 1 to 29.\n");
        return 1;
    }

    printf("Minimum moves: %d\n", minimum_moves(switches));
    printf("Formula: (2^(n+1) - %d) / 3\n", switches % 2 ? 1 : 2);
    printf("Sequence validation: ");
    if (switches <= 10) {
        sequence_length = 0;
        build_sequence(switches);
        validate_sequence(switches);
        putchar('\n');
        printf("%s, %s\n", sequence_is_legal ? "legal" : "illegal",
            generated_moves == minimum_moves(switches) ? "minimum length confirmed" : "length mismatch");
    } else {
        printf("not printed for more than 10 switches\n");
    }
    return 0;
}