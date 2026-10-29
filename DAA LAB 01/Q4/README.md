# 🗼 Problem 4: Tower of Hanoi

## Design and Analysis of Algorithms (DAA)

### Lab-01

---

# 📌 Problem Statement

Implement the **Tower of Hanoi** problem using recursion in C and analyse the number of moves required to solve the problem for different numbers of disks.

The program should generate the number of moves for increasing values of `n` and visualize the growth behaviour using graphs.

---

# 🎯 Objective

The objectives of this experiment are:

* To understand recursive problem-solving techniques.
* To implement the Tower of Hanoi algorithm using recursion.
* To analyse the relationship between the number of disks and required moves.
* To study exponential growth behaviour.
* To visualize algorithm performance using graphical representation.

---

# 📚 Theory

## Tower of Hanoi

Tower of Hanoi is a classic recursive problem consisting of:

* Three rods:

  * Source rod
  * Auxiliary rod
  * Destination rod

* `n` disks of different sizes placed on the source rod.

The objective is to move all disks from the source rod to the destination rod while following these rules:

1. Only one disk can be moved at a time.
2. A larger disk cannot be placed on top of a smaller disk.
3. Every move must transfer the top disk from one rod to another.

---

# 🔁 Recursive Approach

To move `n` disks:

1. Move the top `n-1` disks from the source rod to the auxiliary rod.
2. Move the largest disk from the source rod to the destination rod.
3. Move the `n-1` disks from the auxiliary rod to the destination rod.

This creates a recursive solution.

---

# 🧠 Algorithm

### Tower of Hanoi Algorithm

```
TOH(n, Source, Auxiliary, Destination)

If n = 1:
    Move disk from Source to Destination

Else:

    Move n-1 disks from Source to Auxiliary

    Move nth disk from Source to Destination

    Move n-1 disks from Auxiliary to Destination
```

---

# 📐 Mathematical Analysis

The number of moves required for `n` disks follows the recurrence:

[
$T(n)=2T(n-1)+1$
]

Solving the recurrence:

[
$T(n)=2^n-1$
]

Therefore, the number of moves grows exponentially.

---

# 🛠️ Implementation Details

The C program:

* Implements Tower of Hanoi using recursion.
* Calculates the total number of moves.
* Generates results for different values of `n`.
* Stores data for visualization.

Generated file:

```text
toh.dat
```

contains:

```text
Number_of_Disks     Number_of_Moves
```

Example:

```text
1        1
2        3
3        7
4        15
5        31
```

---

# 📈 Graph Visualization

GNUPlot is used to visualize the relationship between:

### X-axis:

```text
Number of Disks (n)
```

### Y-axis:

```text
Number of Moves
```

The plotting script:

```text
toh.gnu
```

uses:

```text
toh.dat
```

to generate the graph.

Run:

```bash
gnuplot -persist toh.gnu
```

---

# 🔍 Graph Interpretation

The graph represents exponential growth.

For every additional disk:

[
Moves \approx 2 \times Previous\ Moves
]

Example:

| Number of Disks | Number of Moves |
| --------------- | --------------- |
| 1               | 1               |
| 2               | 3               |
| 3               | 7               |
| 4               | 15              |
| 5               | 31              |

As the number of disks increases, the required number of moves grows rapidly.

---

# 📊 Expected Observations

* Small values of `n` can be solved quickly.
* Large values of `n` require an extremely large number of moves.
* Recursive calls increase exponentially with the number of disks.
* The algorithm becomes impractical for very large inputs.

---

# ⏱️ Complexity Analysis

## Time Complexity

The number of recursive calls follows:

[
$T(n)=2^n-1$
]

Therefore:

[
$O(2^n)$
]

---

## Space Complexity

The recursion stack stores function calls.

Maximum recursion depth:

[
n
]

Therefore:

[
O(n)
]

---

# ▶️ How to Run

## Compile

```bash
gcc toh.c -o toh
```

---

## Execute

### Windows

```bash
toh.exe
```

### Linux/Mac

```bash
./toh
```

---

## Generate Graph

```bash
gnuplot -persist toh.gnu
```

---

# 📁 Files Included

```text
Problem-04-Tower-of-Hanoi/

│
├── toh.c
├── toh.dat
├── toh.gnu
├── toh.exe
└── README.md
```

---

# ✅ Conclusion

This experiment demonstrates the power of recursion and shows how recursive algorithms can lead to exponential growth.

Observations:

* Tower of Hanoi has a simple recursive solution.
* The number of operations increases exponentially with the number of disks.
* The experiment highlights the importance of analysing algorithm complexity before applying it to large problems.

Understanding such growth patterns helps in designing efficient algorithms and selecting suitable approaches for computational problems.

---

## 👨‍💻 Author

**Subhang Didwania**

Course:

**Design and Analysis of Algorithms (DAA)**
