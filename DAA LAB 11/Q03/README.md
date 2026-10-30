# DAA Lab 11 - Problem 3
## Bidirectional BFS for Word Transformations

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Bidirectional%20BFS-orange)

---

## Problem Statement

Find the minimum number of one-character mutations from start word `A` to
target word `B`, where every word after `A` must belong to the dictionary.
Return `-1` if no valid sequence exists.

## Input and Algorithm

Input is `N L`, then `N` unique dictionary words, then `A B`. Words contain
only lowercase English letters; `1<=N<=100000` and `1<=L<=10`. `B` must be
present in the dictionary. `A` may be absent and is treated as an additional
starting vertex; if `A=B`, the answer is zero.

The graph is implicit. From each expanded word the program generates the at
most `25L` other one-character substitutions and looks them up in an open-
addressed hash table. Bidirectional BFS expands a complete layer from the
smaller frontier, maintaining distances from both ends and the best meeting
path. It therefore avoids explicitly storing all graph edges.

## Sample Input

```text
7 3
hot
dot
dog
lot
log
cog
hog
hit cog
```

## Sample Output

```text
Minimum mutations: 3
```

## Complexity

Each expanded word performs at most `25L` expected-constant-time hash lookups.
For `X` words actually expanded across both searches, expected time is
`O(X * 25L)` and auxiliary space is `O(NL)` for stored words and
`O(N)` for the hash table, distances, and frontiers. Worst-case adversarial
hash collisions can degrade lookup time.

## Compile and Run

```bash
gcc -std=c11 -Wall -Wextra -O2 03_bidirectional_word_transformation.c -o word_transform
./word_transform
```

Windows:

```powershell
gcc -std=c11 -Wall -Wextra -O2 03_bidirectional_word_transformation.c -o word_transform.exe
.\word_transform.exe
```
