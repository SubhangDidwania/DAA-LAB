# Problem 1 — Sort Items by Colour

## Problem Statement

Given `n` pairs of items where each pair contains:

* A number
* One of three colours: `Red`, `Blue`, or `Yellow`

The items are already sorted by number.

The task is to sort the items by colour in the order:

```text
Red → Blue → Yellow
```

The relative order of numbers having the same colour must remain unchanged.

The algorithm must run in **O(n)** time.

---

## Approach

Since there are only three possible colours, a comparison-based sorting algorithm is unnecessary.

We divide the elements into three separate groups:

```text
Red[]
Blue[]
Yellow[]
```

While traversing the input:

1. If the colour is `R`, add the item to `Red`.
2. If the colour is `B`, add it to `Blue`.
3. Otherwise, add it to `Yellow`.
4. Print the three groups in the required order.

Because the original input is already sorted by number, each individual colour group automatically remains sorted.

---

## Algorithm

```text
1. Create three arrays: Red, Blue and Yellow.
2. Traverse all n input elements.
3. Place each element into its corresponding colour array.
4. Print all Red elements.
5. Print all Blue elements.
6. Print all Yellow elements.
```

---

## Time Complexity

* Traversing input: `O(n)`
* Printing output: `O(n)`

Therefore:

```text
O(n) + O(n) = O(n)
```

### Overall Complexity

**Time:** `O(n)`

**Space:** `O(n)`

---

## Example

### Input

```text
6
1 R
2 Y
3 B
4 R
5 Y
6 B
```

### Output

```text
Sorted by colour:
1 R
4 R
3 B
6 B
2 Y
5 Y
```

---

## Key Concepts

* Stable partitioning
* Linear-time sorting
* Arrays
* Categorization
* Maintaining relative order
