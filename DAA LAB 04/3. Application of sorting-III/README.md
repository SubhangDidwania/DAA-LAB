# Problem 3 — K Numbers with Sum T

## Problem Statement

Given a set `S` containing `n` integers, an integer `T`, and an integer `k`, determine whether there are `k` elements in `S` whose sum is equal to `T`.

The required complexity is:

```text
O(n^(k-1) log n)
```

---

## Approach

The main idea is to select `k - 1` elements and calculate the value required from the final element.

If the selected elements have sum `sum`, then:

```text
required = T - sum
```

After sorting the input, binary search can be used to determine whether the required value exists.

---

## Algorithm

```text
1. Sort the input set.
2. Select k - 1 elements recursively.
3. Calculate their sum.
4. Calculate:

      required = T - sum

5. Use binary search to check whether required exists.
6. If it exists, k elements with sum T have been found.
7. Otherwise, continue with another combination.
8. If all combinations are exhausted, report failure.
```

---

## Example

Given:

```text
S = {2, 4, 6, 8, 10}
T = 18
k = 3
```

Choose:

```text
2 + 6 = 8
```

Required value:

```text
18 - 8 = 10
```

Since `10` exists:

```text
2 + 6 + 10 = 18
```

Therefore, the answer is **Yes**.

---

## Time Complexity

There are approximately:

```text
O(n^(k-1))
```

ways to select `k - 1` elements.

Binary search takes:

```text
O(log n)
```

Therefore:

```text
O(n^(k-1) log n)
```

### Overall Complexity

**Time:** `O(n^(k-1) log n)`

**Space:** `O(n)` plus recursion stack.

---

## Key Concepts

* K-sum problem
* Recursion
* Sorting
* Binary search
* Combinations
* Complexity analysis
