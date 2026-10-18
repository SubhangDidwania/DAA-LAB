# DAA Lab 10 - Problem 3
## Maximum Weight Component with Size Constraints

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-DSU%20%2B%20Components-orange)

---

## Problem Statement

Vertex weights are given and undirected edges are inserted sequentially. After
each insertion, report the greatest total vertex weight of any connected
component whose vertex count is at most `K`.

## Input and Algorithm

Input format:

```text
V E K
w1 w2 ... wV
u1 v1 edge_weight1
...
uE vE edge_weightE
```

Vertices are numbered from 1. The edge weight is read but intentionally ignored:
connectivity and the requested objective depend on the vertex weights, not the
edge weights. A DSU stores each component's size and sum of vertex weights.
Following each edge union, the program scans DSU roots for the best eligible
component. If no component has size at most `K`, it prints `NONE`. Vertex
weights may be negative; the largest eligible sum is still reported.

## Sample Input

```text
4 3 2
5 -2 8 4
1 2 10
2 3 20
3 4 30
```

## Sample Output

```text
After edge 1: 8
After edge 2: 4
After edge 3: NONE
```

## Complexity

Each union is amortized `O(α(V))`; the scan after each insertion costs `O(V)`.
Total: `O((E+V) α(V) + EV)` time and `O(V)` auxiliary space.

## Compile and Run

```bash
gcc -std=c11 -Wall -Wextra -O2 03_max_weight_component_size_limit.c -o max_component
./max_component
```

Windows:

```powershell
gcc -std=c11 -Wall -Wextra -O2 03_max_weight_component_size_limit.c -o max_component.exe
.\max_component.exe
```
