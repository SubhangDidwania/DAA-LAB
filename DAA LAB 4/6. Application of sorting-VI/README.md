# Problem 6 — Point Covered by Maximum Intervals

## Problem Statement

Given `n` intervals on a number line, where each interval is represented as:

```text
(li, ri)
```

find a point `p` that belongs to the largest possible number of intervals.

An endpoint is considered part of its interval.

The required complexity is **O(n log n)**.

---

## Approach

Convert each interval into two events:

```text
Left endpoint  → +1
Right endpoint → -1
```

Sort all events by their position.

When two events have the same position, the starting event must be processed before the ending event because endpoints are included in the intervals.

Then scan the events while maintaining the number of active intervals.

Whenever the current count exceeds the maximum, store that point.

---

## Algorithm

```text
1. For every interval (l, r):
      Create event (l, +1).
      Create event (r, -1).

2. Sort events by position.
3. If positions are equal, process +1 before -1.

4. Set current = 0 and maximum = 0.

5. Traverse the events:
      current += event.type

      If current > maximum:
          maximum = current
          bestPoint = event.position

6. Print bestPoint and maximum.
```

---

## Example

Given:

```text
(10,40)
(20,60)
(50,90)
(15,70)
```

At point `20`, the following intervals overlap:

```text
(10,40)
(20,60)
(15,70)
```

Therefore:

```text
Point = 20
Maximum overlap = 3
```

Point `50` also lies in three intervals, as stated in the lab problem.

---

## Handling Endpoints

The problem specifies that an endpoint counts as being inside an interval.

Therefore, at the same coordinate:

```text
Start (+1)
```

must be processed before:

```text
End (-1)
```

This is handled in the sorting comparator.

---

## Time Complexity

There are `2n` events.

Sorting:

```text
O(n log n)
```

Scanning:

```text
O(n)
```

Therefore:

```text
O(n log n)
```

### Overall Complexity

**Time:** `O(n log n)`

**Space:** `O(n)`

---

## Key Concepts

* Interval overlap
* Event sorting
* Sweep-line algorithm
* Sorting with tie-breaking
* Maximum overlap
* Endpoint handling
