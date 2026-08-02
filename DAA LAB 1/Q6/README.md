# 🔢 Problem 6: Element Uniqueness Detection

## Design and Analysis of Algorithms (DAA)

### Lab-01

---

# 📌 Problem Statement

Given an array of elements, determine whether all elements are unique or if any duplicate elements exist.

The program should check the array and identify duplicate values using an appropriate searching technique.

Example:

Input:

```text
10 20 30 40 50
```

Output:

```text
All elements are unique
```

---

Input:

```text
10 20 30 20 50
```

Output:

```text
Duplicate element found: 20
```

---

# 🎯 Objective

The objectives of this experiment are:

* To understand the element uniqueness problem.
* To implement duplicate detection using comparisons.
* To analyse the efficiency of brute-force searching.
* To study the relationship between input size and number of comparisons.
* To understand the importance of algorithm optimization.

---

# 📚 Theory

## Element Uniqueness Problem

The element uniqueness problem determines whether all elements in a collection are different.

Given an array:

$[
A = [a_1,a_2,a_3,...,a_n]
]$

The task is to check whether:

$[
a_i \neq a_j
]$

for every pair:

$[
i \neq j
]$

If any two elements satisfy:

$[
a_i=a_j
]$

then the array contains duplicate elements.

---

# 🧠 Algorithm

## Brute Force Approach

The simplest method is to compare every element with all other elements.

Steps:

1. Start from the first element.
2. Compare it with all remaining elements.
3. If a matching element is found:

   * Duplicate exists.
4. Move to the next element.
5. Repeat until the array is completely checked.

---

## Algorithm Representation

```text
ELEMENT_UNIQUENESS(A,n)

For i = 0 to n-1:

    For j = i+1 to n-1:

        If A[i] == A[j]:

            Duplicate found
            Return false


Return true
```

---

# 🛠️ Implementation Details

The C program:

* Generates or accepts an array of elements.
* Compares all possible element pairs.
* Detects duplicate values.
* Displays whether the array contains unique elements.

---

# 📊 Example Execution

## Example 1

### Input

```text
Enter number of elements: 5

Generated Array:
10 20 30 40 50
```

### Output

```text
All elements are unique
```

---

## Example 2

### Input

```text
Enter number of elements: 6

Generated Array:
5 12 7 8 12 20
```

### Output

```text
Duplicate element found: 12
```

---

# 📈 Comparison Analysis

For an array of size `n`, the algorithm compares:

$[
(n-1)+(n-2)+(n-3)+...+1
]$

pairs.

This simplifies to:

$[
\frac{n(n-1)}{2}
]$

comparisons.

---

# ⏱️ Complexity Analysis

## Time Complexity

In the worst case, every pair of elements must be checked.

Number of comparisons:

$[
\frac{n(n-1)}{2}
]$

Therefore:

$[
O(n^2)
]$

---

## Best Case Complexity

If a duplicate is found immediately:

[
O(1)
]

Example:

```text
5 5 10 20 30
```

The program stops after the first comparison.

---

## Space Complexity

The algorithm only uses:

* Loop variables
* Temporary variables

Therefore:

[
O(1)
]

---

# 🔍 Algorithm Behaviour

## Unique Array

Example:

```text
1 2 3 4 5
```

The algorithm must compare all pairs.

Number of comparisons:

$[
\frac{5(4)}{2}=10
]$

---

## Array With Duplicate

Example:

```text
1 2 3 2 5
```

The algorithm stops when:

```text
2 == 2
```

is detected.

This reduces the number of comparisons.

---

# 🆚 Alternative Approaches

## Sorting Approach

Another method is:

1. Sort the array.
2. Compare adjacent elements.

Complexity:

$[
O(nlogn)
]$

---

## Hashing Approach

Using a hash table:

* Insert each element.
* Check if it already exists.

Average complexity:

$[
O(n)
]$

---

# ▶️ How to Run

## Compile

```bash
gcc Duplication.c -o Duplication
```

---

## Execute

### Windows

```bash
Duplication.exe
```

### Linux/Mac

```bash
./Duplication
```

---

# 📁 Files Included

```text
Problem-06-Element-Uniqueness/

│
├── Duplication.c
├── Duplication.exe
└── README.md
```

---

## 👨‍💻 Author

**Subhang Didwania**

Course:

**Design and Analysis of Algorithms (DAA)**
