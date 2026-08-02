# 📈 Problem 1: Growth Rate Analysis

## Design and Analysis of Algorithms (DAA)

### Lab-01

---

## 📌 Problem Statement

Implement the given mathematical functions in C and arrange them in increasing order of their growth rate for sufficiently large values of `n`.

The functions to be analysed are:

* `1/n`
* `log₂(n)`
* `√n`
* `n^0.51`
* `n`
* `nlog₂(n)`
* `100n² + 6n`
* `n² - 324`
* `50√n`
* `2n³`
* `n^(log₂n)`
* `3^n`

The growth behaviour of each function is visualized using graphs.

---

# 🎯 Objective

The objective of this experiment is to:

* Understand asymptotic growth rates.
* Compare different mathematical functions experimentally.
* Arrange functions according to their increasing order of growth.
* Visualize how algorithms with different complexities behave as input size increases.

---

# 📚 Theory

The efficiency of an algorithm is commonly represented using asymptotic notations such as:

* Big O notation
* Big Ω notation
* Big Θ notation

Growth rate describes how the running time increases as input size `n` becomes larger.

For large values of `n`, dominant terms decide the growth behaviour.

Example:

[
100n^2+6n \approx n^2
]

because the quadratic term dominates.

---

# 🧠 Algorithm

1. Generate values of `n` within a chosen range.
2. Calculate the value of each mathematical function.
3. Store the calculated values in a data file.
4. Plot the functions using GNUPlot.
5. Compare the curves and determine the increasing growth order.

---

# 📊 Increasing Order of Growth

For sufficiently large values of `n`:

```
1/n  <  log₂(n)  <  √n  <  n^0.51  <  n  <  nlog₂(n)  <  n²  <  n³  <  n^(log₂n)  <  3^n
```

---

# 🛠️ Implementation Details

The C program:

* Uses `math.h` for mathematical calculations.
* Calculates values for different values of `n`.
* Writes results into:

```
growth.dat
```

Example format:

```
n     log(n)     sqrt(n)     n     n^2     3^n
```

Each column represents the value of a function.

---

# 📈 Graph Visualization

GNUPlot is used to generate graphs.

The plot script:

```
growth.gnu
```

reads:

```
growth.dat
```

and displays the growth curves.

Run:

```bash
gnuplot -persist growth.gnu
```

---

# 🔍 Graph Interpretation

## Slow Growing Functions

Examples:

```
1/n
log₂(n)
√n
```

These increase very slowly even for large inputs.

---

## Polynomial Growth

Examples:

```
n
n²
n³
```

These grow faster as input size increases.

---

## Exponential Growth

Example:

```
3^n
```

The growth becomes extremely large and dominates all other functions.

---

# ⏱️ Complexity Analysis

The program evaluates each function once for every value of `n`.

## Time Complexity

```
O(n)
```

## Space Complexity

```
O(1)
```

(Excluding storage required for output files)

---

# ▶️ How to Run

## Compile

```bash
gcc growth.c -o growth -lm
```

The `-lm` option links the mathematical library.

---

## Execute

### Windows

```bash
growth.exe
```

### Linux/Mac

```bash
./growth
```

---

## Generate Graph

```bash
gnuplot -persist growth.gnu
```

---

# 📁 Files Included

```
Problem-01-Growth-Rate/

│
├── growth.c
├── growth.dat
├── growth.gnu
└── README.md
```

---

# ✅ Conclusion

This experiment demonstrates that different functions grow at significantly different rates as input size increases.

Understanding growth rates helps in:

* Comparing algorithms.
* Predicting scalability.
* Choosing efficient solutions for large problems.

The experiment highlights why algorithms with lower asymptotic complexity are preferred for large inputs.

---

## 👨‍💻 Author

**Subhang Didwania**

Course:

**Design and Analysis of Algorithms (DAA)**
