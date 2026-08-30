# DAA Lab 5 — Problem 3
## Quick Sort on Random Elements Stored in a File

![Language](https://img.shields.io/badge/Language-C-blue)
![Algorithm](https://img.shields.io/badge/Algorithm-Quick%20Sort-orange)
![Average](https://img.shields.io/badge/Average-O(N%20log%20N)-green)

---

## 📌 Problem Statement

Implement **Quick Sort** on `N` randomly generated elements stored in a file. Perform the complexity analysis of the algorithm.

---

## 🎯 Objective

The objective is to:

1. Generate `N` random elements.
2. Store the elements in a file.
3. Read the elements from the file.
4. Sort them using Quick Sort.
5. Display the original and sorted elements.
6. Store the sorted elements in another file.
7. Analyze the algorithm's complexity.

---

## 🧠 Concept Used — Quick Sort

Quick Sort is a **divide-and-conquer sorting algorithm**.

It works by selecting a pivot and partitioning the array into two parts:

```text
Elements <= Pivot | Pivot | Elements > Pivot
```

Quick Sort is then recursively applied to both partitions.

---

## 🔄 Algorithm

### Quick Sort

```text
QUICKSORT(A, low, high)

1. If low < high:
2.     Partition the array.
3.     Let p be the pivot position.
4.     Quick Sort the left partition.
5.     Quick Sort the right partition.
```

### Partition

```text
PARTITION(A, low, high)

1. Choose A[high] as pivot.
2. Compare every element with the pivot.
3. Move smaller/equal elements to the left.
4. Place the pivot in its correct position.
5. Return the pivot index.
```

---

## 📂 File Handling

The program uses two files:

```text
input.txt
sorted.txt
```

### `input.txt`

Contains the randomly generated elements.

Example:

```text
45 76 12 89 32 17 61 4
```

### `sorted.txt`

Contains the sorted elements.

Example:

```text
4 12 17 32 45 61 76 89
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
      Quick Sort
          ↓
 Display Sorted Array
          ↓
      sorted.txt
```

---

## 💻 Implementation

File:

```text
problem3_quicksort.c
```

Random values are generated using:

```c
rand()
```

and the random number generator is initialized using:

```c
srand(time(NULL));
```

The program uses standard C file operations:

```text
fopen()
fprintf()
fscanf()
fclose()
```

---

## 📥 Sample Input

```text
Enter number of elements: 8
```

The program automatically generates 8 random numbers.

Example generated data:

```text
45 76 12 89 32 17 61 4
```

## 📤 Sample Output

```text
Original elements:
45 76 12 89 32 17 61 4

Sorted elements:
4 12 17 32 45 61 76 89

Sorted elements saved in sorted.txt
```

---

## ⏱️ Complexity Analysis

| Case | Time Complexity |
|---|---:|
| Best | `O(N log N)` |
| Average | `O(N log N)` |
| Worst | `O(N²)` |

### Best/Average Case

When the pivot divides the array into reasonably balanced partitions:

```text
T(N) = 2T(N/2) + O(N)
```

Therefore:

```text
O(N log N)
```

### Worst Case

When the pivot is repeatedly the smallest or largest element:

```text
T(N) = T(N-1) + O(N)
```

Therefore:

```text
O(N²)
```

### Space Complexity

Average recursion stack:

```text
O(log N)
```

Worst case:

```text
O(N)
```

---

## 📊 Important Properties

| Property | Quick Sort |
|---|---|
| Technique | Divide and Conquer |
| In-place | Yes |
| Stable | No |
| Best Time | `O(N log N)` |
| Average Time | `O(N log N)` |
| Worst Time | `O(N²)` |

---

## 🧪 Important Test Cases

- Small value of `N`
- Large value of `N`
- Duplicate random values
- Already sorted input
- Reverse sorted input
- Randomly distributed input

---

## ▶️ Compilation and Execution

```bash
gcc problem3_quicksort.c -o problem3
./problem3
```

Windows:

```bash
gcc problem3_quicksort.c -o problem3.exe
problem3.exe
```

After execution, check:

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
│   ├── problem3_quicksort.c
│   ├── input.txt
│   ├── sorted.txt
│   └── README.md
│
└── Problem-4/
```

---

## 📚 Topics Covered

- Quick Sort
- Divide and Conquer
- Partitioning
- Recursion
- Random Number Generation
- File Handling
- Time Complexity
- Space Complexity

---

## ✅ Conclusion

Quick Sort efficiently sorts randomly generated elements using a divide-and-conquer strategy. Its average complexity is **O(N log N)**, although the worst case can reach **O(N²)** depending on pivot selection.
