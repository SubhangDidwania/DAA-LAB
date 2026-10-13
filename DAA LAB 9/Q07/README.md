# DAA Lab 9 - Problem 7
## Minimise Deviation in Array

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Two-way%20Greedy-orange)
![Complexity](https://img.shields.io/badge/Time-O(n%20log%20n)-green)

---

## Problem Statement

Given an array of positive integers, you may perform one of two operations on any element:

- multiply an odd element by 2, or
- divide an even element by 2.

The objective is to minimise the deviation `(max(A) - min(A))` after any number of operations.

## Objective

The objective is to shrink the spread between the largest and smallest values as much as possible.

## Concept Used - Max-Heap Greedy

Repeatedly operate on the largest value when it is even, dividing it to make it smaller, while ensuring the set of reachable values stays valid.

## Algorithm

```text
1. Convert all odd numbers into even numbers by doubling them repeatedly.
2. Put the numbers into a max-heap.
3. Repeatedly pop the maximum value and, if it is even, divide it by 2 and push it back.
4. Track the current minimum value in the heap.
5. Update the minimum deviation.
6. Stop when further division is impossible.
```

## Implementation

File:

```text
07_minimize_deviation.c
```

## Sample Input

```text
4
1 5 6 10
```

## Sample Output

```text
Minimum deviation: 2
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| Heap-based transformations | `O(n log n)` typical | `O(n)` |
| Total | `O(n log n)` | `O(n)` |

## Important Test Cases

| Array | Output |
|---|---|
| `1 5 6 10` | `2` |
| `1 2 3` | `1` |
| `4 7 9` | `2` |

## Compilation and Execution

```bash
gcc 07_minimize_deviation.c -o deviation
./deviation
```

Windows:

```powershell
gcc 07_minimize_deviation.c -o deviation.exe
.\deviation.exe
```
