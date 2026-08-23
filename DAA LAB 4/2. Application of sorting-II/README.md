# Problem 2 — Pair Sum from Two Sets

## Problem Statement

Given two sets `S1` and `S2`, each containing `n` elements, and an integer `x`, determine whether there exists a pair of elements:

```text
a ∈ S1
b ∈ S2
```

such that:

```text
a + b = x
```

The required time complexity is **O(n log n)**.

---

## Approach

First, sort both sets.

After sorting, use the **two-pointer technique**:

* Start from the smallest element of `S1`.
* Start from the largest element of `S2`.

For every pair:

* If `a + b == x`, the required pair is found.
* If `a + b < x`, increase the pointer of `S1`.
* If `a + b > x`, decrease the pointer of `S2`.

This avoids checking every possible pair.

---

## Algorithm

```text
1. Read S1 and S2.
2. Sort both arrays.
3. Set i = 0 and j = n - 1.
4. While i < n and j >= 0:
      sum = S1[i] + S2[j]

      If sum == x:
          Pair found.
      Else if sum < x:
          i++
      Else:
          j--
5. If no pair is found, report that no such pair exists.
```

---

## Time Complexity

Sorting both arrays:

```text
O(n log n)
```

Two-pointer traversal:

```text
O(n)
```

Therefore:

```text
O(n log n) + O(n)
= O(n log n)
```

### Overall Complexity

**Time:** `O(n log n)`

**Space:** `O(n)`

---

## Example

### Input

```text
4
1 3 5 7
2 4 6 8
10
```

A valid pair is:

```text
2 + 8 = 10
```

### Output

```text
Pair found: 2 + 8 = 10
```

---

## Key Concepts

* Sorting
* Two-pointer technique
* Pair-sum problem
* Searching
* Complexity analysis
