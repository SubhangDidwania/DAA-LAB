# Q1 — Dictionary ADT: Comparing Underlying Data Structures

**Course:** Design and Analysis of Algorithms (DAA) — Lab 02
**Semester:** 3rd Sem, BTech (CSE-B)
**Instructor:** Dr. Ajaya Kumar Dash

## What this is about

A dictionary supports seven core operations — `Search`, `Insert`, `Delete`, `Max`, `Min`, `Predecessor`, and `Successor`. How fast these run depends entirely on what data structure you use underneath. This lab compares six implementations:

- Unsorted array
- Sorted array
- Singly linked unsorted list
- Singly linked sorted list
- Doubly linked unsorted list
- Doubly linked sorted list

## Worst-case time complexities

| Structure                     | Search | Insert | Delete | Max  | Min  | Predecessor | Successor |
|--------------------------------|:------:|:------:|:------:|:----:|:----:|:-----------:|:---------:|
| Unsorted array                 | O(n)   | O(1)   | O(n)   | O(n) | O(n) | O(n)        | O(n)      |
| Sorted array                   | O(log n) | O(n) | O(n)   | O(1) | O(1) | O(1)        | O(1)      |
| Singly linked, unsorted        | O(n)   | O(1)   | O(n)   | O(n) | O(n) | O(n)        | O(n)      |
| Singly linked, sorted          | O(n)   | O(n)   | O(n)   | O(1) | O(1) | O(n)        | O(n)      |
| Doubly linked, unsorted        | O(n)   | O(1)   | O(1)*  | O(n) | O(n) | O(n)        | O(n)      |
| Doubly linked, sorted          | O(n)   | O(n)   | O(1)*  | O(1) | O(1) | O(1)        | O(1)      |

\* Delete is O(1) *once you already have a pointer to the node* — that's the whole point of the doubly linked list here, since you don't need to walk the list to fix up the neighboring links. If you had to search for the node first, it'd still be O(n) overall.

A couple of things worth noting:
- Insert is cheap (O(1)) whenever you're allowed to just dump the new element wherever — front of a list, end of an array — which is only possible when the structure doesn't need to stay sorted.
- Sorted structures pay more on insert/delete but get Max/Min/Predecessor/Successor essentially for free, since sorted order already tells you where everything is.
- Arrays give O(1) random access, which is why sorted arrays get binary search (O(log n)) for search — linked lists can never binary search, even sorted ones, since you can't jump to the middle in O(1).

## File Structure

```
q1_dictionary/
├── dictionary.c
├── dictionary.exe
├── dictionary.dat
├── search.gnu
├── insert.gnu
├── delete.gnu
├── minmax.gnu        # times each op over increasing n, dumps CSV
├── predsucc.gnu      # reads the CSV, plots order-of-growth curves
└── results/
    ├── delete_comparision.png
    ├── insert_comparision.png
    ├── search_comparision.png
    ├── minmax_comparision.png
    └── predsucc_comparision.png
```

# How to Run
## Compile

```gcc dictionary.c -o dictionary -lm```

The ```-lm``` flag links the mathematical library.

## Execute

Windows:
---

```dictionary.exe```

Linux:
---
```./dictionary```

---

## Plot Graph
```
gnuplot -persist search.gnu
gnuplot -persist insert.gnu
gnuplot -persist delete.gnu
gnuplot -persist minmax.gnu
gnuplot -persist predsucc.gnu
```

The benchmark runs each operation across increasing input sizes (e.g. n = 100 to 10,000, doubling each step) and logs execution time. The plot script then overlays all six structures per operation so the asymptotic gaps (O(1) vs O(log n) vs O(n)) are visible as curve shape, not just numbers in a table.

## Takeaway

There's no single "best" structure — it's a trade-off dictated by which operations your workload actually leans on. If you mostly search and rarely modify, sorted array wins. If you insert/delete constantly and only occasionally query, unsorted structures (or a hash table, outside this lab's scope) win instead.
