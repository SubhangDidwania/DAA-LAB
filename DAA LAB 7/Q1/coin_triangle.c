#include <stdio.h>

static int formula_moves(int rows) {
    int quotient = rows / 3;
    switch (rows % 3) {
        case 0:
            return quotient * (3 * quotient + 1) / 2;
        case 1:
            return 3 * quotient * (quotient + 1) / 2;
        default:
            return (quotient + 1) * (3 * quotient + 2) / 2;
    }
}

static int in_target(int row, int column, int shift_row, int shift_column, int rows) {
    int target_row = row - shift_row;
    int target_column = column - shift_column;
    return target_row >= 0 && target_row < rows
        && target_column >= target_row && target_column < rows;
}

static int exact_moves(int rows) {
    int total_coins = rows * (rows + 1) / 2;
    int maximum_overlap = 0;

    for (int shift_row = -rows; shift_row <= rows; ++shift_row) {
        for (int shift_column = -rows; shift_column <= rows; ++shift_column) {
            int overlap = 0;
            for (int row = 0; row < rows; ++row) {
                for (int column = 0; column <= row; ++column) {
                    if (in_target(row, column, shift_row, shift_column, rows)) {
                        ++overlap;
                    }
                }
            }
            if (overlap > maximum_overlap) maximum_overlap = overlap;
        }
    }
    return total_coins - maximum_overlap;
}

int main(void) {
    int rows;
    printf("Enter the number of rows in the coin triangle: ");
    fflush(stdout);
    if (scanf("%d", &rows) != 1 || rows < 1) {
        fprintf(stderr, "Enter a positive number of rows.\n");
        return 1;
    }

    printf("Minimum moves: %d\n", formula_moves(rows));
    printf("Coins: %d\n", rows * (rows + 1) / 2);
    if (rows <= 60) {
        int checked = exact_moves(rows);
        printf("Exact lattice check: %s\n", checked == formula_moves(rows) ? "passed" : "failed");
    }
    return 0;
}