# DAA Lab 10 - Problem 1
## Online Graph-Bipartiteness Testing

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Disjoint%20Set%20Union-orange)

---

## Problem Statement

Undirected edges arrive one at a time. Accept an edge only when the retained
graph remains bipartite; otherwise report and skip the edge.

## Representation and Algorithm

The program reads `V E`, followed by `E` endpoint pairs (vertices numbered
from 1). A parity DSU stores, for each vertex, its XOR color difference from
its parent. Each edge `(u,v)` imposes `color(u) XOR color(v) = 1`.
If the endpoints are already in one DSU set, their parity is checked; if they
are in different sets, the sets are joined with the required parity relation.
A self-loop is correctly rejected.

## Sample Input

```text
3 4
1 2
2 3
3 1
1 3
```

## Sample Output

```text
Edge (1, 2): accepted
Edge (2, 3): accepted
Edge (3, 1): rejected (would violate bipartiteness)
Edge (1, 3): rejected (would violate bipartiteness)
The retained graph is bipartite.
```

## Complexity

Each edge takes amortized `O(α(V))` time with path compression and union by
rank. Total: `O(E α(V))` time and `O(V)` auxiliary space.

## Compile and Run

```bash
gcc -std=c11 -Wall -Wextra -O2 01_online_graph_bipartiteness.c -o bipartite
./bipartite
```

Windows:

```powershell
gcc -std=c11 -Wall -Wextra -O2 01_online_graph_bipartiteness.c -o bipartite.exe
.\bipartite.exe
```
