# Problem 1 — Binary vs Ternary Search

## Problem Statement

In binary search, a sorted list is divided into nearly two equal halves,
while in ternary search, it is divided into nearly three equal intervals.

Design and implement a C program to search for an element `x` in a sorted
list using both Binary Search and Ternary Search.

The implementation should compare their performance and validate whether
Binary Search is better than Ternary Search.

## Approach

### Binary Search

Binary Search divides the search interval into two parts.

At every step:

1. Find the middle element.
2. If it is equal to `x`, return its position.
3. If `x` is smaller, search the left half.
4. Otherwise, search the right half.

### Ternary Search

Ternary Search divides the search interval into three parts.

At every step:

1. Calculate two middle positions.
2. Compare `x` with both middle elements.
3. Continue searching in the appropriate third.

## Complexity

| Algorithm | Best Case | Average Case | Worst Case |
|-----------|-----------|--------------|------------|
| Binary Search | O(1) | O(log n) | O(log n) |
| Ternary Search | O(1) | O(log n) | O(log n) |

Although both have logarithmic complexity, Binary Search generally performs
fewer comparisons per iteration.

## Experimental Validation

The program can be used to:

- Generate or enter sorted arrays.
- Search for the same element using both algorithms.
- Count the number of comparisons.
- Compare the number of comparisons for different values of `n`.
- Generate a graph using Gnuplot.

## Gnuplot

The graph compares the number of comparisons performed by Binary Search
and Ternary Search.

The Gnuplot script is maintained separately and is not generated
automatically by the C program.

## Topics Covered

- Binary Search
- Ternary Search
- Divide and Conquer
- Comparison counting
- Experimental analysis
- Gnuplot visualization

## Files

- `search_comparision.c` — C implementation
- `search_comparision.gnu` — Gnuplot script
- `search_comparision.dat` — Experimental data

## Conclusion

Binary Search and Ternary Search both have logarithmic time complexity.
However, Binary Search generally requires fewer comparisons because it
uses one comparison point to divide the search space into two parts,
while Ternary Search requires two comparison points.
