# Binary vs Ternary Search

**Course:** Design and Analysis of Algorithm (DAA) — Lab-03
**Program:** BTech (CS-B and CE), 3rd Semester
**Instructor:** Dr. Ajaya Kumar Dash

## Problem Statement

In binary search, an `n`-element sorted list is divided into nearly two equal
halves at each step. In ternary search, the list is instead divided into
nearly three equal intervals, and the search continues in whichever interval
can contain the target.

This program implements **both** search strategies for locating an element
`x` in a sorted array of size `n`, counts the number of comparisons each
makes, and empirically validates that binary search performs fewer
comparisons (and is therefore more efficient) than ternary search.

## Approach

- **Binary Search:** At each step, compare the target with the middle
  element and recurse/iterate into the left or right half.
- **Ternary Search:** At each step, compute two midpoints that split the
  current range into three parts, compare the target against both, and
  recurse/iterate into the appropriate third.
- Both implementations track the number of key comparisons performed, so
  the two approaches can be benchmarked directly on the same input array
  and target value(s).

## Complexity

| Algorithm       | Recurrence           | Time Complexity |
|-----------------|-----------------------|------------------|
| Binary Search   | T(n) = T(n/2) + O(1)  | O(log₂ n)        |
| Ternary Search  | T(n) = T(n/3) + O(2)  | O(log₃ n) with a larger constant |

Although ternary search reduces the search space by a factor of 3 each
step (vs. 2 for binary search), it performs **two** comparisons per step
instead of one. Working out the comparison counts shows binary search
uses fewer total comparisons in the worst case, which the program
verifies experimentally.

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

## How to Build

```bash
gcc -o search_comparision search_comparision.c
```

On Windows:

```bash
gcc -o search_comparision.exe search_comparision.c
```

## How to Run

```bash
./search_comparision

gnuplot -persist search_comparision.gnu
```

The program prompts for:
1. The size `n` of the sorted array (or generates one).
2. The element `x` to search for.

It then prints the index found (or "not found"), along with the number
of comparisons taken by each method, so results can be compared directly.

## Sample Output

```
Enter size of sorted array: 20
Enter element to search: 47

Binary Search:  found at index 12, comparisons = 4
Ternary Search: found at index 12, comparisons = 5

=> Binary search used fewer comparisons.
```

## Conclusion

Binary Search and Ternary Search both have logarithmic time complexity.
However, Binary Search generally requires fewer comparisons because it
uses one comparison point to divide the search space into two parts,
while Ternary Search requires two comparison points.
