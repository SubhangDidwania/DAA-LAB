# Q3 — Merging k Sorted Arrays: Sequential vs. Pairwise

**Course:** Design and Analysis of Algorithms (DAA) — Lab 02
**Semester:** 3rd Sem, BTech (CS-B / CE)
**Instructor:** Dr. Ajaya Kumar Dash

## The setup

k sorted arrays, n elements each, total kn elements. Two ways to combine them into one sorted array of size kn.

## Method 1 — Sequential merging

Merge array 1 with array 2, merge that result with array 3, then with array 4, and so on until array k is folded in.

**Analysis:**
The i-th merge combines a running result of size (i-1)n with the next array of size n, costing O(in). Summing over all k-1 merges:

```
O(n) + O(2n) + O(3n) + ... + O((k-1)n)
= O(n · (1 + 2 + ... + (k-1)))
= O(n · k(k-1)/2)
= O(nk²)
```

**Worst-case running time: O(nk²)**

This is the "naive" approach — every merge after the first has to redo work over an ever-growing left-hand side, which is where the quadratic-in-k blowup comes from.

## Method 2 — Pairwise (tournament-style) merging

Pair up the k arrays and merge each pair, giving k/2 arrays of size 2n. Repeat: pair those up, merge, giving k/4 arrays of size 4n. Keep going until one array of size kn remains.

**Analysis:**
Each full round merges kn elements total, regardless of how many arrays are in play that round (this is the same "O(n) per level" idea as merge sort). The number of rounds is log₂(k), since k halves each time.

```
O(n) per element × k elements-worth of arrays × log₂(k) rounds
= O(nk log k)
```

**Worst-case running time: O(nk log k)**

## Comparing the two

| Method | Running time | 
|--------|---------------|
| Sequential (Method 1) | O(nk²) |
| Pairwise (Method 2) | O(nk log k) |

For any k > 2, nk log k grows much slower than nk². Method 2 is essentially the same idea as merge sort's recursion tree — you avoid re-merging the same elements over and over by keeping the intermediate arrays roughly equal in size at every step, instead of letting one array snowball while the rest stay tiny.

## Files

```
q3_kway_merge/
├── merge_k.c             
├── merge_k.exe      
├── merge_k.dat                        
├── merge_k.gnu
└── results/
    └── merge_k_comparision.png
```

## How to Run
## Compile
```gcc growth.c -o growth -lm```

The ```-lm``` flag links the mathematical library.

## Execute

Windows:
---

```merge_k.exe```

Linux:
---

```./merge_k```

Plot Graph
---
```gnuplot -persist growth.gnu```

---

**Two experiments are run: n fixed while k grows (to expose the k² vs k log k gap), and k fixed while n grows (both should look linear in n, confirming the n factor is common to both methods).**

## Takeaway

Same lesson as Q2: how you structure the merges — not just what you merge — determines the running time. Balancing work evenly across "rounds" (pairwise) beats a linear chain of ever-larger merges (sequential), and the gap widens fast as k grows.
