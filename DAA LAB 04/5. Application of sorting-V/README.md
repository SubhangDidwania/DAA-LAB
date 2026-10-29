# Problem 5 — Merge Overlapping Intervals

## Problem Statement

Given a list of `n` intervals:

```text
(xi, yi)
```

merge all overlapping intervals.

For example:

```text
{(1,3), (2,6), (8,10), (7,18)}
```

should produce:

```text
{(1,6), (7,18)}
```

The algorithm must run in worst-case **O(n log n)** time.

---

## Approach

The intervals are first sorted according to their starting points.

After sorting, process the intervals from left to right.

For the current interval:

* If the next interval starts before or at the current ending point, they overlap.
* Extend the current ending point if necessary.
* Otherwise, store the current interval and begin processing the next one.

---

## Algorithm

```text
1. Sort intervals by their starting point.
2. Set the first interval as the current interval.
3. For every remaining interval:
      If its start <= current end:
          Merge it with the current interval.
      Else:
          Store the current interval.
          Make the new interval the current interval.
4. Store the final interval.
5. Print all merged intervals.
```

---

## Example

### Input

```text
4
1 3
2 6
8 10
7 18
```

After sorting:

```text
(1,3)
(2,6)
(7,18)
(8,10)
```

Merge:

```text
(1,3) + (2,6)
      ↓
(1,6)
```

Then:

```text
(7,18)
```

contains `(8,10)`, so the final result is:

```text
(1,6)
(7,18)
```

---

## Time Complexity

Sorting:

```text
O(n log n)
```

Merging:

```text
O(n)
```

Therefore:

```text
O(n log n)
```

### Overall Complexity

**Time:** `O(n log n)`

**Space:** `O(n)` including the input/output representation.

---

## Key Concepts

* Interval scheduling
* Sorting
* Greedy technique
* Interval merging
* Sweep-line processing
