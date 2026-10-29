# Q2 — Merge Sort vs. Three-Way Merge Sort

**Course:** Design and Analysis of Algorithms (DAA) — Lab 02
**Semester:** 3rd Sem, BTech (CSE-B)
**Instructor:** Dr. Ajaya Kumar Dash

## The question

Standard merge sort splits the array into halves. What if instead you split it into **thirds**, recursively sort each third, then merge all three back together with a three-way merge? Does that change the asymptotic running time?

## Short answer

No — it's still **O(n log n)**, just with a smaller base in the logarithm and a different constant factor.

## Why

**Standard merge sort:** T(n) = 2T(n/2) + O(n) → by the Master Theorem, this gives O(n log₂ n).

**Three-way merge sort:** T(n) = 3T(n/3) + O(n)

The recursion tree now has 3 children per node instead of 2, so the tree has depth log₃(n) instead of log₂(n). But at every level, the total work across all nodes is still O(n) — you're merging *n* elements total per level regardless of how many pieces you split them into. So total work is:

```
O(n) per level × log₃(n) levels = O(n log₃ n)
```

Since log₃(n) = log₂(n) / log₂(3), and log₂(3) is just a constant (~1.585), this is:

```
O(n log₃ n) = O(n · log₂n / log₂3) = O(n log₂ n)
```

Same asymptotic class. The three-way merge does slightly less recursion depth but pays for it with a costlier merge step (merging 3 sorted lists instead of 2 takes more comparisons per element), so in practice the constants roughly cancel out — you won't see a meaningful speedup, and depending on implementation you might even see a slight slowdown from the more complex merge logic.

## Files

```
q2_mergesort/
├── mergesort.c            
├── mergesort.exe        
├── merge.dat                
├── merge.gnu
└── results/
    └── merge_comparision.png
```

## How to Run
## Compile
```gcc mergesort.c -o mergesort -lm```

The ```-lm``` flag links the mathematical library.

## Execute

Windows:
---

```mergesort.exe```

Linux:
---

```./mergesort```

## Plot Graph
---
```gnuplot -persist merge.gnu```

---

The plot overlays both algorithms' runtimes against n, alongside a reference n·log(n) curve, to visually confirm both follow the same growth shape.

## Takeaway

Changing the branching factor of a divide-and-conquer algorithm changes the *base* of the logarithm, not its presence. Since all logarithms are related by a constant factor (change of base), this never changes the big-O class — it only tweaks constants, which don't show up in asymptotic analysis but can matter a little in real wall-clock time.
