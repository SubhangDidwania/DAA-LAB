# Use of Loop Invariants in Sorting (Selection Sort)

**Course:** Design and Analysis of Algorithm (DAA) — Lab-03
**Program:** BTech (CSE-B), 3rd Semester
**Instructor:** Dr. Ajaya Kumar Dash

## Problem Statement

Sort `n` numbers stored in array `A[1..n]` by repeatedly finding the
smallest element of the unsorted remainder and exchanging it into place:
first find the smallest of `A[1..n]` and swap it with `A[1]`, then find
the smallest of `A[2..n]` and swap it with `A[2]`, and so on, continuing
for the first `(n − 1)` elements of `A`. This is the **Selection Sort**
algorithm. The task includes writing pseudocode, stating and proving the
loop invariant, explaining why the loop only needs to run for the first
`(n − 1)` elements, and giving the algorithm's running time in
Θ-notation, then implementing and validating it in C.

## Pseudocode

```
SELECTION-SORT(A, n)
  for i = 1 to n - 1
      min_index = i
      for j = i + 1 to n
          if A[j] < A[min_index]
              min_index = j
      exchange A[i] with A[min_index]
```

## Loop Invariant

**Invariant:** At the start of each iteration of the outer `for` loop
(indexed by `i`), the subarray `A[1..i-1]` consists of the `i-1` smallest
elements of the original array, in sorted (non-decreasing) order.

- **Initialization:** Before the first iteration, `i = 1`, so `A[1..0]` is
  empty — trivially sorted and trivially "the smallest 0 elements."
- **Maintenance:** During iteration `i`, the inner loop finds the minimum
  element of `A[i..n]` and swaps it into position `A[i]`. Since
  `A[1..i-1]` was already sorted and contained the smallest `i-1`
  elements (and none of them are touched by this iteration), after the
  swap `A[1..i]` is sorted and contains the smallest `i` elements —
  restoring the invariant for `i+1`.
- **Termination:** The outer loop ends when `i = n`. At that point the
  invariant states `A[1..n-1]` contains the smallest `n-1` elements in
  sorted order — which forces the single remaining element `A[n]` to be
  the largest, so the entire array `A[1..n]` is sorted.

## Why Only the First `(n − 1)` Elements?

Once the first `n-1` elements are placed correctly (each being the
minimum of the remaining unsorted suffix at the time it was fixed), only
one element — the largest — remains for position `n`. There is nothing
left to compare it against, so running an `n`-th outer iteration would be
redundant; it can't change the array.

## Running Time

- **Comparisons:** Regardless of the input, the inner loop always
  performs `(n-i)` comparisons for each `i`, giving a total of
  `(n-1) + (n-2) + ... + 1 = n(n-1)/2` comparisons.
- **Worst-case running time:** Θ(n²)
- **Best-case running time:** Also **Θ(n²)** — unlike algorithms such as
  insertion sort, selection sort always scans the entire unsorted
  remainder to find the minimum, regardless of whether the array is
  already sorted. So the best case is **not** any better than the worst
  case; only the number of swaps (not comparisons) can be reduced (e.g.,
  zero swaps if already sorted), but comparisons remain Θ(n²) in every
  case.

## File Structure

```
Q6/
├── sorting.c   # Source code
├── sorting.exe # Compiled executable (Windows)
└── README.md
```

## How to Build

```bash
gcc -o sorting sorting.c
```

On Windows:

```bash
gcc -o sorting.exe sortting.c
```

## How to Run

```bash
./sorting
```

The program prompts for the array size `n` and its elements, sorts the
array using selection sort, and prints the sorted array along with the
total number of comparisons and swaps performed — validating the Θ(n²)
comparison bound.

## Sample Output

```
Enter number of elements: 6
Enter elements: 29 10 14 37 13 4

Sorted array: 4 10 13 14 29 37
Comparisons = 15   (n(n-1)/2 = 15)
Swaps = 4
```
