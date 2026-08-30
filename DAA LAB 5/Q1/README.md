# DAA Lab 5 — Problem 1
## Finding the Median Without Sorting

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Quickselect-orange)
![Complexity](https://img.shields.io/badge/Average-O(N)-green)

---

## 📌 Problem Statement

Find the **median of a list of N numbers without sorting the list** and perform the complexity analysis of the algorithm.

---

## 🎯 Objective

The objective is to find the median without using a complete sorting algorithm.

A normal approach would sort the array in `O(N log N)` time. Instead, this problem uses **Quickselect**, which is based on the partitioning technique of Quick Sort and can find a required order statistic in **average O(N)** time.

---

## 🧠 Concept Used — Quickselect

Quickselect is a selection algorithm used to find the element at a particular position in an unsorted array.

It works similarly to Quick Sort:

1. Select a pivot.
2. Partition the array around the pivot.
3. Find the final position of the pivot.
4. Continue searching only in the partition containing the required element.

Unlike Quick Sort, Quickselect **does not recursively process both sides**.

### Median Position

For `N` elements:

- If `N` is odd:

```text
Median = element at index N/2
```

- If `N` is even:

```text
Median = (element at index N/2 - 1 + element at index N/2) / 2
```

The program uses zero-based indexing.

---

## 🔄 Algorithm

### Quickselect

```text
QUICKSELECT(A, low, high, k)

1. If low == high, return A[low].
2. Partition A using a pivot.
3. Let p be the pivot's final position.
4. If p == k, return A[p].
5. If k < p, search the left partition.
6. Otherwise, search the right partition.
```

### Finding Median

```text
If N is odd:
    Find the element at index N/2.

If N is even:
    Find elements at indices N/2 - 1 and N/2.
    Take their average.
```

---

## 💻 Implementation

File:

```text
problem1_median.c
```

The implementation uses Quickselect and does not perform a complete sort.

---

## 📥 Input

```text
Enter number of elements: 7
Enter 7 elements:
12 3 5 7 4 19 26
```

## 📤 Output

```text
Median = 7.00
```

### Even Number Example

Input:

```text
4
1 8 3 6
```

Output:

```text
Median = 4.50
```

Because the two middle values are `3` and `6`.

---

## ⏱️ Complexity Analysis

| Case | Time Complexity |
|---|---:|
| Best | `O(N)` |
| Average | `O(N)` |
| Worst | `O(N²)` |

### Why?

If the pivot divides the array reasonably well, the amount of data considered decreases rapidly, giving an average complexity of:

```text
O(N)
```

In the worst case, the pivot can repeatedly be the smallest or largest element:

```text
T(N) = T(N-1) + O(N)
```

Therefore:

```text
O(N²)
```

### Space Complexity

Average recursive stack:

```text
O(log N)
```

Worst-case recursive stack:

```text
O(N)
```

---

## 🔍 Why Quickselect Instead of Sorting?

| Approach | Average Time |
|---|---:|
| Sorting + selecting | `O(N log N)` |
| Quickselect | `O(N)` |

Quickselect is preferable when we only need a particular order statistic instead of the complete sorted array.

---

## 🧪 Important Test Cases

| Input Type | Expected Result |
|---|---|
| Odd number of elements | Middle element |
| Even number of elements | Average of two middle elements |
| Duplicate values | Correct median |
| Already sorted input | Correct median |
| Reverse sorted input | Correct median |
| Negative values | Correct median |

---

## ▶️ Compilation and Execution

### GCC

```bash
gcc problem1_median.c -o problem1
./problem1
```

### Windows

```bash
gcc problem1_median.c -o problem1.exe
problem1.exe
```

---

## 📁 Suggested Folder Structure

```text
DAA-LAB-5/
│
├── Problem-1/
│   ├── problem1_median.c
│   └── README.md
│
├── Problem-2/
├── Problem-3/
└── Problem-4/
```

---

## 📚 Topics Covered

- Selection Algorithms
- Quickselect
- Partitioning
- Median
- Recursion
- Order Statistics
- Time Complexity
- Space Complexity

---

## ✅ Conclusion

The median can be found without sorting the entire array by using **Quickselect**. Its average time complexity is **O(N)**, making it more efficient than sorting when only the median is required.
