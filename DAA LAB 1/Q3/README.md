# 🔄 Problem 3: Bubble Sort Performance Analysis

## Design and Analysis of Algorithms (DAA)

### Lab-01

---

# 📌 Problem Statement

Implement and compare two versions of the Bubble Sort algorithm:

1. **Normal Bubble Sort**
2. **Optimized Bubble Sort**

The program should count and compare the number of comparisons performed by both algorithms for different input sizes.

The performance difference between the two approaches is analysed using graphical visualization.

---

# 🎯 Objective

The objectives of this experiment are:

* To understand the working of Bubble Sort.
* To compare standard and optimized implementations.
* To analyse the effect of early termination optimization.
* To experimentally study the relationship between input size and number of comparisons.
* To visualize algorithm performance using graphs.

---

# 📚 Theory

## Bubble Sort

Bubble Sort is a comparison-based sorting algorithm that repeatedly compares adjacent elements and swaps them if they are in the wrong order.

During every pass:

* The largest unsorted element moves towards the end of the array.
* The process continues until the complete array is sorted.

Example:

Before sorting:

```text
5 3 8 1
```

After first pass:

```text
3 5 1 8
```

The largest element (`8`) reaches its correct position.

---

# 🔹 Normal Bubble Sort

The normal Bubble Sort algorithm always performs:

[
(n-1)
]

passes regardless of whether the array becomes sorted earlier.

Example:

For an already sorted array:

```text
1 2 3 4 5
```

it still performs unnecessary comparisons.

---

# 🔹 Optimized Bubble Sort

The optimized version introduces a **swap flag**.

During each pass:

* If any swapping occurs:

  * Continue sorting.
* If no swapping occurs:

  * The array is already sorted.
  * Stop execution early.

This reduces unnecessary comparisons.

---

# 🧠 Algorithm

## Normal Bubble Sort

1. Start from the first element.
2. Compare adjacent elements.
3. Swap if the left element is greater than the right element.
4. Repeat for all elements.
5. Continue for `(n-1)` passes.

---

## Optimized Bubble Sort

1. Start Bubble Sort normally.
2. Initialize:

```c
swapped = 0;
```

3. Perform comparisons and swaps.
4. Set:

```c
swapped = 1;
```

when a swap occurs.

5. After each pass:

```text
If swapped == 0:

Array is already sorted.
Stop.
```

---

# 🛠️ Implementation Details

The program:

* Generates input arrays.
* Applies both Bubble Sort techniques.
* Counts the number of comparisons.
* Stores performance data.

The generated data file:

```text
bubble.dat
```

contains:

```text
Array_Size     Normal_Comparisons     Optimized_Comparisons
```

Example:

```text
100        4950        1200
200        19900       2400
500        124750      6200
```

---

# 📊 Performance Analysis

The number of comparisons is used as the performance metric.

The program compares:

## Normal Bubble Sort

* Executes all passes.
* Performs maximum comparisons.

## Optimized Bubble Sort

* Terminates early when no swaps occur.
* Performs fewer comparisons for sorted/nearly sorted arrays.

---

# 📈 Graph Visualization

GNUPlot is used to compare the performance of both algorithms.

The graph contains:

## X-axis:

```text
Input Size (n)
```

## Y-axis:

```text
Number of Comparisons
```

The plotting script:

```text
bubble.gnu
```

uses:

```text
bubble.dat
```

to generate the graph.

Run:

```bash
gnuplot -persist bubble.gnu
```

---

# 🔍 Graph Interpretation

## Normal Bubble Sort Curve

The number of comparisons increases rapidly with input size.

The growth follows:

[
O(n^2)
]

---

## Optimized Bubble Sort Curve

The curve remains lower because unnecessary passes are avoided.

For already sorted arrays:

[
O(n)
]

performance can be achieved.

---

# 📊 Expected Observations

| Algorithm             | Best Case | Average Case | Worst Case |
| --------------------- | --------- | ------------ | ---------- |
| Normal Bubble Sort    | O(n²)     | O(n²)        | O(n²)      |
| Optimized Bubble Sort | O(n)      | O(n²)        | O(n²)      |

---

# ⏱️ Complexity Analysis

## Normal Bubble Sort

### Time Complexity

Worst Case:

[
O(n^2)
]

Average Case:

[
O(n^2)
]

Best Case:

[
O(n^2)
]

---

## Optimized Bubble Sort

### Time Complexity

Best Case:

[
O(n)
]

when the array is already sorted.

Average Case:

[
O(n^2)
]

Worst Case:

[
O(n^2)
]

---

## Space Complexity

Both algorithms use only temporary variables.

Therefore:

[
O(1)
]

---

# ▶️ How to Run

## Compile

```bash
gcc bubble.c -o bubble
```

---

## Execute

### Windows

```bash
bubble.exe
```

### Linux/Mac

```bash
./bubble
```

---

## Generate Graph

```bash
gnuplot -persist bubble.gnu
```

---

# 📁 Files Included

```text
Problem-03-Bubble-Sort/

│
├── bubble.c
├── bubble.dat
├── bubble.gnu
├── bubble.exe
└── README.md
```

---

# ✅ Conclusion

This experiment demonstrates the importance of optimization in algorithm design.

Observations:

* Normal Bubble Sort performs unnecessary comparisons even when the array is already sorted.
* Optimized Bubble Sort reduces execution by detecting already sorted conditions.
* Both algorithms have quadratic worst-case complexity.
* Simple optimizations can significantly improve practical performance.

The experiment highlights the importance of analysing and improving algorithms rather than only focusing on correctness.

---

## 👨‍💻 Author

**Subhang Didwania**

Course:

**Design and Analysis of Algorithms (DAA)**
