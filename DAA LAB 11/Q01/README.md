# DAA Lab 11 - Problem 1
## Shortest Paths with an Odd-Edge Penalty

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-0--1%20BFS-orange)

---

## Problem Statement

For each vertex, minimize the sum of edge weights (each is 0 or 1) plus a
penalty `C` if the path contains an odd number of weight-1 edges.

## Input and Algorithm

Input is `V E S C`, followed by `E` directed edges `u v w`. Vertices are
1-based and `w` is 0 or 1. The source is `S`; `C` is a nonnegative integer.

Represent each vertex as two states `(v, p)`, where `p` is the parity of the
number of weight-1 edges used. Traversing an edge of weight `w` changes the
state parity by XOR with `w`, and contributes `w` to the state distance.
0-1 BFS computes shortest distances on this expanded graph. The answer for a
vertex is `min(dist[v,0], dist[v,1] + C)`. A vertex with neither state
reachable is reported as `UNREACHABLE`. Effective costs are expected to fit
in a signed 64-bit integer.

## Sample Input

```text
4 5 1 5
1 2 1
2 4 0
1 3 0
3 4 0
2 3 0
```

## Sample Output

```text
Vertex MinimumCost
1 0
2 6
3 0
4 0
```

## Complexity

The expanded graph has `2V` states and `2E` transitions. 0-1 BFS takes
`O(V + E)` time and `O(V + E)` space.

## Compile and Run

```bash
gcc -std=c11 -Wall -Wextra -O2 01_parity_constrained_shortest_paths.c -o parity_paths
./parity_paths
```

Windows:

```powershell
gcc -std=c11 -Wall -Wextra -O2 01_parity_constrained_shortest_paths.c -o parity_paths.exe
.\parity_paths.exe
```
