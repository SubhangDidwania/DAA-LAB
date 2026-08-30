# DAA Lab 5 — Problem 2
## Finding the K-th Smallest Element Without Sorting

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Quickselect-orange)
![Average](https://img.shields.io/badge/Average-O(N)-green)

---

## 📌 Problem Statement

Find the **K-th smallest element** in a given list of `N` numbers without sorting the list. Perform the complexity analysis of the algorithm.

---

## 🎯 Objective

The objective is to find an order statistic directly from an unsorted array without sorting all its elements.

The algorithm used is **Quickselect**.

---

## 🧠 Concept Used — Quickselect

If an array contains:

```text
8 4 7 1 9 3
```

then the elements in sorted order would be:

```text
1 3 4 7 8 9
```

Therefore, the 3rd smallest element is:

```text
4
```

However, the program does **not** sort the array.

Because C uses zero-based indexing, the K-th smallest element is located at index:

```text
K - 1
```

---

## 🔄 Algorithm

```text
QUICKSELECT(A, low, high, k)

1. Select a pivot.
2. Partition the array around the pivot.
3. Find the pivot's final position p.
4. If p == k, return A[p].
5. If k < p, recursively search the left side.
6. Otherwise, recursively search the right side.
```

Only one side is searched after partitioning.

---

## 💻 Implementation

File:

```text
problem2_kth_smallest.c
```

The program validates that:

```text
1 <= K <= N
```

and then searches for index:

```text
K - 1
```

using Quickselect.

---

## 📥 Input

```text
Enter number of elements: 6
Enter 6 elements:
8 4 7 1 9 3
Enter K: 3
```

## 📤 Output

```text
3-th smallest element = 4
```

---

## 🔎 Example Walkthrough

Consider:

```text
8 4 7 1 9 3
```

For:

```text
K = 3
```

we need index:

```text
K - 1 = 2
```

Quickselect partitions the array around a pivot and determines which partition contains index `2`.

It ignores the partition that cannot contain the answer.

This is the main difference from Quick Sort.

---

## ⏱️ Complexity Analysis

| Case | Time Complexity |
|---|---:|
| Best | `O(N)` |
| Average | `O(N)` |
| Worst | `O(N²)` |

### Average Case

Quickselect processes only one partition after each partitioning operation.

Therefore, its expected complexity is:

```text
O(N)
```

### Worst Case

If every pivot produces a highly unbalanced partition:

```text
T(N) = T(N-1) + O(N)
```

Hence:

```text
O(N²)
```

### Space Complexity

Average recursive stack:

```text
O(log N)
```

Worst case:

```text
O(N)
```

---

## 🔍 Quickselect vs Sorting

| Method | Average Time | Purpose |
|---|---:|---|
| Sorting | `O(N log N)` | Find complete ordering |
| Quickselect | `O(N)` | Find one order statistic |

Quickselect is more suitable when only the K-th smallest element is required.

---

## 🧪 Important Test Cases

| Test Case | Expected Behavior |
|---|---|
| `K = 1` | Smallest element |
| `K = N` | Largest element |
| Duplicate values | Correct K-th element |
| Negative numbers | Correct result |
| Invalid `K` | Error message |
| Already sorted array | Correct result |

---

## ▶️ Compilation and Execution

```bash
gcc problem2_kth_smallest.c -o problem2
./problem2
```

Windows:

```bash
gcc problem2_kth_smallest.c -o problem2.exe
problem2.exe
```

---

## 📁 Suggested Folder Structure

```text
DAA-LAB-5/
│
├── Problem-1/
├── Problem-2/
│   ├── problem2_kth_smallest.c
│   └── README.md
│
├── Problem-3/
└── Problem-4/
```

---

## 📚 Topics Covered

- Quickselect
- Selection Algorithms
- Order Statistics
- Partitioning
- Recursion
- K-th Smallest Element
- Time Complexity
- Space Complexity

---

## ✅ Conclusion

Quickselect provides an efficient way to find the K-th smallest element without sorting the complete array. Its average time complexity is **O(N)**, while its worst case is **O(N²)**.
