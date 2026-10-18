# DAA Lab 10 - Problem 4
## Reverse Time-Step DSU for Vertex Deletions

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Reverse%20DSU-orange)

---

## Problem Statement

Given a vertex-weighted undirected graph and a deletion permutation, report
after each deletion the maximum total vertex weight of any remaining connected
component. If no vertices remain, report `NONE`.

## Input and Algorithm

Input format:

```text
V E
w1 w2 ... wV
u1 v1
...
uE vE
p1 p2 ... pV
```

Vertices are 1-based. Since DSU does not support deletion directly, process
the deletion permutation in reverse: activate one vertex at a time and union
it with its active neighbors. A max-heap stores component sums; root/version
checks lazily discard heap entries made obsolete by a union. Output is then
reported in the original deletion order. Negative weights are supported.

## Sample Input

```text
4 3
5 -2 8 4
1 2
2 3
3 4
2 3 1 4
```

## Sample Output

```text
After deleting 2: 12
After deleting 3: 5
After deleting 1: 4
After deleting 4: NONE
```

## Complexity

There are at most `V` activations and `V-1` successful unions. DSU operations
take `O((V+E) α(V))`; heap insertion/removal is `O(log V)` amortized per
entry. Total: `O((V+E) α(V) + V log V)` time and `O(V+E)` space.

## Compile and Run

```bash
gcc -std=c11 -Wall -Wextra -O2 04_reverse_deletions_max_component.c -o reverse_dsu
./reverse_dsu
```

Windows:

```powershell
gcc -std=c11 -Wall -Wextra -O2 04_reverse_deletions_max_component.c -o reverse_dsu.exe
.\reverse_dsu.exe
```
