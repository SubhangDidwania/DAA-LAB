# DAA Lab 5 — Problem 4
## Heap Sort on Random Elements Stored in a File

![Language](https://img.shields.io/badge/Language-C-blue)
![Algorithm](https://img.shields.io/badge/Algorithm-Heap%20Sort-orange)
![Complexity](https://img.shields.io/badge/All%20Cases-O(N%20log%20N)-green)

---

## 📌 Problem Statement

Implement **Heap Sort** on `N` randomly generated elements stored in a file. Perform the complexity analysis of the algorithm.

---

## 🎯 Objective

The objective is to:

1. Generate `N` random elements.
2. Store them in a file.
3. Read the elements from the file.
4. Construct a Max Heap.
5. Sort the elements using Heap Sort.
6. Display the original and sorted elements.
7. Store the sorted elements in another file.
8. Analyze the algorithm's complexity.

---

## 🧠 Concept Used — Heap Sort

Heap Sort is a comparison-based sorting algorithm that uses a **Binary Heap**.

For ascending order, we use a **Max Heap**.

A Max Heap follows:

```text
Parent >= Children
```

Therefore, the largest element is always present at the root.

---

## 🌳 Binary Heap Representation

For an element at index `i`:

```text
Left Child  = 2*i + 1
Right Child = 2*i + 2
Parent      = (i - 1) / 2
```

Example:

```text
        90
       /       70    80
    /     30   50
```

The root contains the largest element.

---

## 🔄 Algorithm

### Build Max Heap

```text
BUILD-MAX-HEAP(A)

1. Start from the last non-leaf node.
2. Apply heapify to every non-leaf node.
3. Continue until the root is heapified.
```

### Heapify

```text
HEAPIFY(A, n, i)

1. Assume i is the largest.
2. Find left and right children.
3. Compare both children with A[i].
4. If a child is larger, make it the largest.
5. Swap if necessary.
6. Recursively heapify the affected subtree.
```

### Heap Sort

```text
HEAPSORT(A)

1. Build a Max Heap.
2. Swap the root with the last element.
3. Reduce heap size by one.
4. Heapify the root.
5. Repeat until the array is sorted.
```

---

## 📂 File Handling

The program uses:

```text
input.txt
sorted.txt
```

### `input.txt`

Example:

```text
4 10 3 5 1
```

### `sorted.txt`

After Heap Sort:

```text
1 3 4 5 10
```

---

## 🔁 Program Workflow

```text
Generate Random Numbers
          ↓
      input.txt
          ↓
    Read Elements
          ↓
   Build Max Heap
          ↓
     Heap Sort
          ↓
 Display Sorted Array
          ↓
      sorted.txt
```

---

## 💻 Implementation

File:

```text
problem4_heapsort.c
```

The program uses:

```c
rand()
```

for random number generation and:

```c
srand(time(NULL))
```

to initialize the random number generator.

File operations use:

```text
fopen()
fprintf()
fscanf()
fclose()
```

---

## 📥 Sample Input

```text
Enter number of elements: 5
```

Example generated elements:

```text
4 10 3 5 1
```

## 📤 Sample Output

```text
Original elements:
4 10 3 5 1

Sorted elements:
1 3 4 5 10

Sorted elements saved in sorted.txt
```

---

## ⏱️ Complexity Analysis

| Operation | Complexity |
|---|---:|
| Build Max Heap | `O(N)` |
| Heapify | `O(log N)` |
| N extractions | `O(N log N)` |
| Overall | `O(N log N)` |

### Overall Complexity

Heap Sort has:

```text
Best Case    = O(N log N)
Average Case = O(N log N)
Worst Case   = O(N log N)
```

Unlike the basic Quick Sort implementation, Heap Sort does not degrade to `O(N²)` in the worst case.

### Space Complexity

The implementation uses recursive `heapify()`, so the auxiliary recursion stack is:

```text
O(log N)
```

---

## 📊 Important Properties

| Property | Heap Sort |
|---|---|
| Technique | Heap-based |
| Data Structure | Binary Heap |
| In-place | Yes |
| Stable | No |
| Best Time | `O(N log N)` |
| Average Time | `O(N log N)` |
| Worst Time | `O(N log N)` |

---

## 🧪 Important Test Cases

- Small value of `N`
- Large value of `N`
- Duplicate values
- Already sorted data
- Reverse sorted data
- Randomly distributed data

---

## ▶️ Compilation and Execution

```bash
gcc problem4_heapsort.c -o problem4
./problem4
```

Windows:

```bash
gcc problem4_heapsort.c -o problem4.exe
problem4.exe
```

After execution, verify:

```text
input.txt
sorted.txt
```

---

## 📁 Suggested Folder Structure

```text
DAA-LAB-5/
│
├── Problem-1/
├── Problem-2/
├── Problem-3/
│
└── Problem-4/
    ├── problem4_heapsort.c
    ├── input.txt
    ├── sorted.txt
    └── README.md
```

---

## 📚 Topics Covered

- Heap Sort
- Binary Heap
- Max Heap
- Heapify
- Array Representation of Heap
- Random Number Generation
- File Handling
- Recursion
- Time Complexity
- Space Complexity

---

## 🔍 Quick Sort vs Heap Sort

| Feature | Quick Sort | Heap Sort |
|---|---:|---:|
| Best | `O(N log N)` | `O(N log N)` |
| Average | `O(N log N)` | `O(N log N)` |
| Worst | `O(N²)` | `O(N log N)` |
| Stable | No | No |
| Main Technique | Partitioning | Heap |

---

## ✅ Conclusion

Heap Sort uses a Max Heap to repeatedly place the largest remaining element at the end of the array. It guarantees **O(N log N)** time complexity in the best, average, and worst cases, making its performance predictable.
