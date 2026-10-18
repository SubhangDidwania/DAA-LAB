# DAA Lab 10 - Problem 2
## Dynamic Connected Components in a Grid

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Grid%20%2B%20DSU-orange)

---

## Problem Statement

Starting with an all-water `R x C` grid, add land cells one at a time and
report the number of 4-directionally connected islands after each operation.

## Representation and Algorithm

Input is `R C K`, followed by `K` 1-based row/column coordinates. Each cell is
flattened to `row * C + column`. A DSU represents connected land cells. When a
new cell becomes land, it starts one component and is unioned with each
already-land orthogonal neighbor. Repeated additions are no-ops and leave the
count unchanged.

## Sample Input

```text
3 3 6
1 1
1 2
2 2
3 3
2 1
1 1
```

## Sample Output

```text
1 1 1 2 2 2
```

## Complexity

Each operation checks at most four neighbors and performs amortized
`O(α(RC))` DSU operations. Including DSU initialization, total time is
`O(RC + K α(RC))` and space is `O(RC)`.

## Compile and Run

```bash
gcc -std=c11 -Wall -Wextra -O2 02_dynamic_islands.c -o islands
./islands
```

Windows:

```powershell
gcc -std=c11 -Wall -Wextra -O2 02_dynamic_islands.c -o islands.exe
.\islands.exe
```
