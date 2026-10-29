# DAA Lab-06 — Question 1

## 1D Array Operations and Complexity Analysis

### Problem Statement

Given an unsorted array containing `n` integer elements, determine the worst-case time complexity of the following operations:

1. Finding the maximum element
2. Finding the first and second largest elements
3. Finding the mean
4. Finding the median
5. Finding the standard deviation
6. Finding the mode
7. Removing all duplicates
8. Reversing the array
9. Partitioning the array with respect to a pivot

A C program is implemented to validate the operations.

---

## Concepts Used

* Arrays
* Linear traversal
* Searching
* Sorting
* Nested loops
* Array reversal
* Partitioning
* Statistical operations
* Time complexity analysis

---

## Algorithms

### 1. Maximum Element

Traverse the entire array while maintaining the largest value found so far.

**Complexity:** `O(n)`

### 2. First and Second Largest

Maintain two variables for the largest and second-largest elements and update them during a single traversal.

**Complexity:** `O(n)`

### 3. Mean

Calculate the sum of all elements and divide it by `n`.

$$
Mean = \frac{\sum A[i]}{n}
$$

**Complexity:** `O(n)`

### 4. Median

Copy the array, sort it, and select the middle element.

For an even-sized array, the average of the two middle elements is taken.

**Complexity:** `O(n log n)`

### 5. Standard Deviation

First calculate the mean, then calculate the squared difference of every element from the mean.

$$
\sigma = \sqrt{\frac{1}{n}\sum(A[i]-Mean)^2}
$$

**Complexity:** `O(n)`

### 6. Mode

For every element, count how many times it occurs using a nested loop.

**Complexity:** `O(n²)`

### 7. Remove Duplicates

Each element is checked against the elements already present in the resulting array.

**Complexity:** `O(n²)`

### 8. Reverse Array

Swap elements from opposite ends until the middle of the array is reached.

**Complexity:** `O(n)`

### 9. Partition

Rearrange the array around a pivot so that elements smaller than the pivot are placed on one side and elements greater than or equal to the pivot on the other.

**Complexity:** `O(n)`

---

## Complexity Summary

| Operation              | Worst-Case Complexity |
| ---------------------- | --------------------: |
| Maximum                |                `O(n)` |
| First & Second Largest |                `O(n)` |
| Mean                   |                `O(n)` |
| Median                 |          `O(n log n)` |
| Standard Deviation     |                `O(n)` |
| Mode                   |               `O(n²)` |
| Remove Duplicates      |               `O(n²)` |
| Reverse                |                `O(n)` |
| Partition              |                `O(n)` |

---

## Input

The program takes:

* Number of elements `n`
* `n` integer array elements

---

## Output

The program displays the results of the implemented array operations.

---

## Compilation

```bash
gcc Array1D.c -o Array1D -lm
```

## Execution

```bash
./Array1D
```

---

## Key Takeaway

Most array operations requiring only a single traversal have `O(n)` complexity. Operations involving pairwise comparisons or nested searches can require `O(n²)`, while finding the median through sorting requires `O(n log n)`.
