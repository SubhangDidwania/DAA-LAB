# Max and Min using Divide and Conquer

**Course:** Design and Analysis of Algorithm (DAA) — Lab-03
**Program:** BTech (CSE-B), 3rd Semester
**Instructor:** Dr. Ajaya Kumar Dash

## Problem Statement

Given an array of `n` elements, find both the maximum and minimum elements
using a divide-and-conquer strategy such that the total number of element
comparisons is bounded by `3n/2`.

## Approach (Divide and Conquer)

1. **Divide** the array into two halves.
2. **Conquer** recursively to find the (max, min) pair of each half.
3. **Combine** the two pairs with **2 comparisons**:
   - Compare the two maxima → overall max.
   - Compare the two minima → overall min.
4. **Base cases:**
   - 1 element: it is both the max and the min (0 comparisons).
   - 2 elements: 1 comparison determines which is max and which is min.

By pairing up elements before comparing against the running max/min
(instead of comparing every element separately against both), this
approach avoids the naive `2n` comparisons of a linear scan and achieves
close to `3n/2` comparisons overall.

## Complexity

- **Comparisons:** at most `⌈3n/2⌉ − 2`
- **Recurrence:** T(n) = 2T(n/2) + 2 → O(n) time, with a comparison count
  bounded by `3n/2` as required.

## File Structure

```
Q3/
├── minmax.c   # Source code
├── minmax.exe # Compiled executable (Windows)
└── README.md
```

## How to Build

```bash
gcc -o minmax minmax.c
```

On Windows:

```bash
gcc -o minmax.exe minmax.c
```

## How to Run

```bash
./minmax
```

The program prompts for the array size `n` and its elements, then prints
the maximum, the minimum, and the total number of comparisons used —
verifying the count stays within the `3n/2` bound.

## Sample Output

```
Enter number of elements: 8
Enter elements: 4 17 2 9 33 1 20 8

Maximum = 33
Minimum = 1
Comparisons used = 10   (3n/2 = 12)
```
