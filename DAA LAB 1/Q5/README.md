# 🔍 Problem 5: Partition Point Detection

## Design and Analysis of Algorithms (DAA)

### Lab-01

---

# 📌 Problem Statement

Given a sorted binary array containing only `0`s and `1`s, find the **partition point** where the sequence changes from `0` to `1`.

The array follows the structure:

```text
0 0 0 0 0 1 1 1 1
          ↑
    Partition Point
```

The program should efficiently determine the first occurrence of `1`.

---

# 🎯 Objective

The objectives of this experiment are:

* To understand searching techniques on sorted data.
* To implement partition point detection using Binary Search.
* To reduce the search time compared to linear scanning.
* To analyse the efficiency of divide-and-conquer searching.

---

# 📚 Theory

## Partition Point

The partition point is the index where the array changes from:

```text
0 → 1
```

For example:

```text
Array:

0 0 0 0 1 1 1

Index:

0 1 2 3 4 5 6
```

The partition point is:

```text
Index = 4
```

because the first `1` appears at index 4.

---

# 🔎 Linear Search Approach

A simple approach is to scan every element:

1. Start from the beginning.
2. Check each element.
3. Return the first index containing `1`.

### Complexity:

[
O(n)
]

For large arrays, this becomes inefficient.

---

# ⚡ Binary Search Approach

Since the array is sorted, Binary Search can be applied.

Instead of checking every element:

* Divide the search space into two halves.
* Eliminate the half that cannot contain the answer.

This reduces the number of operations significantly.

---

# 🧠 Algorithm

## Binary Search Partition Detection

1. Initialize:

```text
low = 0
high = n - 1
```

2. Repeat while:

```text
low <= high
```

3. Find middle index:

$$[
mid=\frac{low+high}{2}
]$$

4. Check:

### Case 1:

If:

```text
arr[mid] == 1
```

then the partition point may exist on the left side.

Search:

```text
high = mid - 1
```

---

### Case 2:

If:

```text
arr[mid] == 0
```

then all elements before `mid` are also `0`.

Search:

```text
low = mid + 1
```

---

5. Continue until the first occurrence of `1` is found.

---

# 🛠️ Implementation Details

The C program:

* Takes a sorted binary array as input.
* Applies Binary Search.
* Finds the first occurrence of `1`.
* Returns the partition index.

Example:

Input:

```text
0000111
```

Output:

```text
Partition Point = 4
```

---

# 📊 Example Execution

## Input

```text
Enter Array: 0000001111
```

---

## Output

```text
Transition point is at index 6
```

---

# 📈 Algorithm Analysis

The search space is reduced by half after every comparison.

Example:

For an array of size:

```text
n = 16
```

Binary Search requires approximately:

```text
4 comparisons
```

because:

$[
log_2(16)=4
]$

---

# ⏱️ Complexity Analysis

## Time Complexity

Each iteration reduces the search space by half.

Therefore:

[
$O(log_2 n)$
]

or:

```text
O(log n)
```

---

## Space Complexity

The algorithm uses only a few variables:

```text
low
high
mid
```

Therefore:

[
O(1)
]

---

# 🆚 Comparison With Linear Search

| Method        | Time Complexity | Approach             |
| ------------- | --------------- | -------------------- |
| Linear Search | O(n)            | Checks every element |
| Binary Search | O(log n)        | Divides search space |

Binary Search is more efficient for large sorted arrays.

---

# ▶️ How to Run

## Compile

```bash
gcc partition.c -o partition
```

---

## Execute

### Windows

```bash
partition.exe
```

### Linux/Mac

```bash
./partition
```

---

# 📁 Files Included

```text
Problem-05-Partition-Point/

│
├── partition.c
├── partition.exe
└── README.md
```

---

# ✅ Conclusion

This experiment demonstrates the application of Binary Search beyond simple searching problems.

Observations:

* The sorted structure of data allows efficient searching.
* Binary Search significantly reduces comparisons.
* Partition point detection can be performed in logarithmic time instead of linear time.

The experiment highlights the importance of selecting appropriate algorithms based on data properties to improve efficiency.

---

## 👨‍💻 Author

**Subhang Didwania**

Course:

**Design and Analysis of Algorithms (DAA)**
