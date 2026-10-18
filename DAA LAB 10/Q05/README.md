# DAA Lab 10 - Problem 5
## Lexicographically Smallest Connected-Component Permutation

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-DSU%20%2B%20Sorting-orange)

---

## Problem Statement

Given a permutation and an undirected graph whose edges specify allowed
pairwise swaps, find the lexicographically smallest permutation reachable by
any number of those swaps.

## Input and Algorithm

Input format:

```text
n
A1 A2 ... An
m
u1 v1
...
um vm
```

Vertices/positions are numbered from 1. A DSU identifies connected
components. Values can be rearranged arbitrarily within each component:
sort that component's positions increasingly and assign its values in
increasing order. The program globally sorts `(component, position)` and
`(component, value)` records to perform those assignments.

## Sample Input

```text
5
5 4 3 2 1
2
1 2
3 4
```

## Sample Output

```text
4 5 2 3 1
```

## Complexity

Building components takes `O(m α(n))`; sorting takes `O(n log n)`.
Total: `O(m α(n) + n log n)` time and `O(n)` auxiliary space.

## Compile and Run

```bash
gcc -std=c11 -Wall -Wextra -O2 05_lexicographically_smallest_component_swaps.c -o component_swaps
./component_swaps
```

Windows:

```powershell
gcc -std=c11 -Wall -Wextra -O2 05_lexicographically_smallest_component_swaps.c -o component_swaps.exe
.\component_swaps.exe
```
