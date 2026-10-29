# DAA Lab-06 — Question 4

## Sorting a Permutation Using Reversal Operations

### Problem Statement

Given a permutation `p` containing the integers:

```text
1, 2, ..., n
```

the objective is to sort the permutation into increasing order.

The only allowed operation is:

```text
reverse(p, i, j)
```

which reverses the subsequence from position `i` to `j`.

The problem has two parts:

1. Prove that every permutation can be sorted using `O(n)` reversals.
2. If the cost of a reversal equals its length, design an algorithm with total cost `O(n log² n)`.

---

# Part 1 — O(n) Reversals

A simple approach similar to selection sort can be used.

### Algorithm

For each position:

1. Find the required smallest element.
2. Find its current position.
3. Reverse the segment from the current position to the required position.
4. Continue with the remaining elements.

At most one reversal is needed to place each element into its final position.

Therefore, at most:

$$
n-1
$$

reversals are required.

Hence:

$$
\boxed{O(n)\text{ reversals}}
$$

---

# Part 2 — O(n log² n) Reversal Cost

The number of reversals alone is not enough because every reversal has a cost equal to its length.

A simple `O(n)`-reversal algorithm may have:

$$
O(n^2)
$$

total cost.

To improve this, a **divide-and-conquer** strategy is used.

---

## Divide-and-Conquer Approach

Divide the range of values into two halves.

For example:

```text
1 2 3 4 5 6 7 8
```

can be divided into:

```text
1 2 3 4 | 5 6 7 8
```

The array is partitioned so that smaller values occur before larger values.

Then recursively sort both halves.

```text
                 Sort
                  |
          -----------------
          |               |
      Smaller           Larger
       values            values
          |               |
       Sort              Sort
```

---

## Rotation Using Reversals

To move two adjacent blocks:

```text
A B
```

into:

```text
B A
```

three reversals can be used:

```text
reverse(A)
reverse(B)
reverse(A+B)
```

This allows the divide-and-conquer partitioning to be performed using only the permitted operation.

---

## Complexity Analysis

At each level of recursion, the partitioning/rotation process costs:

$$
O(n\log n)
$$

There are:

$$
O(\log n)
$$

levels.

Therefore the total reversal cost is:

$$
O(n\log n)\times O(\log n)
$$

which gives:

$$
\boxed{O(n\log^2 n)}
$$

---

## Correctness

At every recursive step:

1. The value range is divided into two parts.
2. Reversal-based partitioning places smaller values in the first section.
3. Larger values are placed in the second section.
4. The algorithm recursively sorts both sections.
5. Eventually each section contains a single value and is therefore sorted.

Since every partition correctly separates the two value ranges and both resulting sections are recursively sorted, the entire permutation becomes sorted.

---

## Input

The program takes:

* Integer `n`
* A permutation containing the integers `1` through `n`

Example:

```text
5
4 2 5 1 3
```

---

## Output

The program displays:

* The sorted permutation
* Total reversal cost

---

## Compilation

```bash
gcc sorting.c -o sorting
```

## Execution

```bash
./sorting
```

---

## Complexity Summary

| Property                            |    Complexity |
| ----------------------------------- | ------------: |
| Number of reversals — simple method |        `O(n)` |
| Cost of simple method               |       `O(n²)` |
| Divide-and-conquer reversal cost    | `O(n log² n)` |
| Recursion depth                     |    `O(log n)` |

---

## Key Takeaway

The major distinction in this problem is between:

**Number of reversals**

and

**Cost of reversals**

A permutation can be sorted in `O(n)` reversals, but those reversals may collectively cost `O(n²)`.

Using divide and conquer reduces the total reversal cost to:

$$
\boxed{O(n\log^2 n)}
$$

while still using only the permitted reversal operation.
