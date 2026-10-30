# DAA Lab 11 - Problem 2
## Radius-Constrained Multi-Source Voronoi Assignment

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Multi--Source%20BFS-orange)

---

## Problem Statement

Assign each vertex to its closest hub, using the smallest hub index to break
equal-distance ties. Vertices farther than radius `R` receive owner `-1`.

## Input and Algorithm

Input is `V E K R`, then the `K` distinct hub vertices in index order, followed
by `E` undirected endpoint pairs. Vertices are numbered from 1. For `K=0`,
all vertices are unassigned.

Initialize a single FIFO queue with all hubs in increasing index order, at
distance zero. Standard multi-source BFS discovers each vertex at its minimum
distance. FIFO layer order and the increasing source order ensure that among
equal-distance hubs the first discovery has the smallest hub index. Output
includes the nearest-hub distance even when the vertex is beyond `R`; it is
`-1` if no hub can reach that vertex. The owner is `-1` when the distance
exceeds `R`.

## Sample Input

```text
7 6 2 2
1 7
1 2
2 3
3 4
4 5
5 6
6 7
```

## Sample Output

```text
Vertex Owner Distance
1 1 0
2 1 1
3 1 2
4 -1 3
5 2 2
6 2 1
7 2 0
```

## Complexity

Every vertex and undirected edge is processed a constant number of times.
Time: `O(V + E)`; auxiliary space: `O(V + E)`.

## Compile and Run

```bash
gcc -std=c11 -Wall -Wextra -O2 02_radius_constrained_voronoi.c -o voronoi
./voronoi
```

Windows:

```powershell
gcc -std=c11 -Wall -Wextra -O2 02_radius_constrained_voronoi.c -o voronoi.exe
.\voronoi.exe
```
