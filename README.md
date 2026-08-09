# 📘 Design and Analysis of Algorithms (DAA)

![Language](https://img.shields.io/badge/Language-C-blue)
![Course](https://img.shields.io/badge/Course-DAA-orange)
![Visualization](https://img.shields.io/badge/Visualization-GNUPlot-green)
![Status](https://img.shields.io/badge/Repository-Active-success)

> A structured collection of Design and Analysis of Algorithms laboratory implementations, experiments, analysis, and visualizations.

---

# 📌 About This Repository

This repository contains implementations and analysis of various algorithms covered in the **Design and Analysis of Algorithms (DAA)** course.

Each laboratory experiment focuses on:

* Algorithm implementation using **C programming**
* Understanding algorithm design techniques
* Time and space complexity analysis
* Experimental performance evaluation
* Data visualization using graphs
* Documentation of observations and conclusions

The repository will be updated regularly as new laboratory assignments and algorithm implementations are completed.

---

# 🗂️ Repository Structure

The repository follows a modular structure where every lab has its own folder containing source code, documentation, and required files.

```
DAA/
│
├── Lab-01/
│   │
│   ├── Problem-01-Growth-Rate/
│   │   ├── growth.c
│   │   ├── growth.dat
│   │   ├── growth.gnu
│   │   └── README.md
│   │
│   ├── Problem-02-Coin-Simulation/
│   │   ├── coin.c
│   │   ├── coin.dat
│   │   ├── coin.gnu
│   │   └── README.md
│   │
│   ├── Problem-03-Bubble-Sort/
│   │   └── README.md
│   │
│   └── ...
│
├── Lab-02/
│   └── README.md
│
├── Lab-03/
│   └── README.md
│
└── README.md
```

---

# 🧪 Completed Labs

## 🔹 Lab-01: Algorithm Analysis and Simulation

### Topics Covered

| Experiment                     | Concept                                        |
| ------------------------------ | ---------------------------------------------- |
| Growth Rate Analysis           | Asymptotic analysis and function comparison    |
| Fair vs Biased Coin Simulation | Probability simulation                         |
| Bubble Sort Analysis           | Best-case optimization and comparison counting |
| Tower of Hanoi                 | Recursion and exponential growth               |
| Partition Point Detection      | Binary search                                  |
| Element Uniqueness             | Duplicate detection and brute-force analysis   |

---

## Lab 02 — Divide and Conquer & Data Structure Analysis

| Problem | Concepts Covered | Analysis / Visualization |
|---------|------------------|--------------------------|
| Dictionary ADT Complexity Analysis | • Unsorted Array<br>• Sorted Array<br>• Singly Linked Lists<br>• Doubly Linked Lists<br>• Dictionary Operations<br>• Search, Insert, Delete<br>• Minimum, Maximum, Predecessor, Successor | • Complexity comparison<br>• Experimental validation<br>• GNUPlot visualization |
| Merge Sort Comparison | • Divide and Conquer<br>• Standard Merge Sort<br>• Three-way Merge Sort<br>• Recursion Analysis<br>• Comparison Counting | • Comparison count analysis<br>• Growth rate comparison<br>• Complexity validation |
| k-Way Merge | • k-Way Merging<br>• Sequential Merging<br>• Pairwise Merging<br>• Divide and Conquer Strategy<br>• Merge Analysis | • Comparison counting<br>• Performance comparison<br>• GNUPlot visualization |

---

# 🛠️ Technologies Used

## Programming Language

### C Programming

Used for implementing algorithms because of:

* Low-level control
* Efficient execution
* Understanding memory and complexity

---

## Development Environment

Recommended:

* Visual Studio Code
* GCC Compiler

---

## Visualization

### GNUPlot

Used for:

* Performance graphs
* Growth rate comparison
* Experimental analysis

---

# ⚙️ Setup Instructions

## 1. Install Required Software

### GCC Compiler

Verify installation:

```bash
gcc --version
```

---

### GNUPlot

Verify installation:

```bash
gnuplot --version
```

---

### Visual Studio Code Extensions

Recommended extensions:

* C/C++ Extension
* Code Runner
* Markdown Preview Enhanced

---

# ▶️ Running Programs

Navigate to the required lab folder:

Example:

```bash
cd Lab-01/Problem-03-Bubble-Sort
```

---

## Compile C Program

```bash
gcc filename.c -o output
```

Example:

```bash
gcc bubble.c -o bubble
```

---

## Run Program

### Windows

```bash
bubble.exe
```

### Linux/Mac

```bash
./bubble
```

---

# 📊 Generating Graphs

Experiments involving visualization contain:

```
.dat
.gnu
```

files.

Example:

```
bubble.dat
bubble.gnu
```

Run:

```bash
gnuplot -persist bubble.gnu
```

The generated graph represents the experimental behaviour of the algorithm.

---

# 📈 Complexity Analysis

Each algorithm implementation includes:

## Time Complexity

The amount of computation required as input size increases.

Examples:

```
O(1)       Constant
O(log n)   Logarithmic
O(n)       Linear
O(n²)      Quadratic
O(2ⁿ)      Exponential
```

---

## Space Complexity

The additional memory required by the algorithm.

---

# 📚 Documentation Format

Each problem folder contains its own:

```
README.md
```

The documentation includes:

* Problem statement
* Objective
* Algorithm explanation
* Implementation details
* Input/output examples
* Complexity analysis
* Graph interpretation
* Conclusion

---

# 🎯 Learning Objectives

Through these experiments, this repository demonstrates:

✅ Understanding of algorithm design techniques
✅ Practical implementation of algorithms
✅ Analysis of efficiency and scalability
✅ Mathematical growth behaviour
✅ Recursive problem solving
✅ Searching and sorting techniques
✅ Experimental validation using graphs

---

# 📌 Future Labs

This repository will be continuously updated with:

* Sorting algorithms
* Searching algorithms
* Divide and conquer techniques
* Greedy algorithms
* Dynamic programming
* Graph algorithms
* Backtracking
* Complexity analysis experiments

---

# 👨‍💻 Author

**Subhang Didwania**

Course:
**Design and Analysis of Algorithms (DAA)**

---

# ⭐ Repository Status

🚧 **Actively maintained**

New experiments and improvements will be added regularly throughout the semester.

---

## "The goal is not only to write algorithms, but to understand why they work and how efficiently they perform."

---

# </> License

## ![License](https://img.shields.io/badge/License-MIT-yellow.svg)
