# 🪙 Problem 2: Fair vs Biased Coin Simulation

## Design and Analysis of Algorithms (DAA)

### Lab-01

---

# 📌 Problem Statement

Implement a coin toss simulation in C to compare the behaviour of:

1. **Fair Coin**
2. **Biased Coin**

The program should perform multiple coin toss experiments, calculate the experimental probability of getting Heads, and compare the results with theoretical probabilities using graphical visualization.

---

# 🎯 Objective

The objective of this experiment is to:

* Understand probability simulation using random experiments.
* Verify the behaviour of fair and biased probability distributions.
* Demonstrate the Law of Large Numbers.
* Analyse how experimental probability approaches theoretical probability as the number of trials increases.
* Visualize probability convergence using graphs.

---

# 📚 Theory

## Fair Coin

A **fair coin** is a coin where both outcomes have equal probability.

The probability of getting Head is:


$$P(Head)= \frac{1}{2}=0.5$$


The probability of getting Tail is:


$$P(Tail)=\frac{1}{2}=0.5$$


Therefore, after a large number of tosses:

```
HEAD ≈ 50%

TAIL ≈ 50%
```

---

## Biased Coin

A **biased coin** is a coin where the probability of Head and Tail are not equal.

Example:

[
P(Head)=0.7
]

[
P(Tail)=0.3
]

This means that Head has a higher chance of occurring.

In general:

[
P(Head)+P(Tail)=1
]

---

# 📖 Law of Large Numbers

This experiment demonstrates the **Law of Large Numbers**.

It states that:

> As the number of random trials increases, the experimental probability approaches the actual theoretical probability.

For coin toss simulation:

$$
P(Head)=
\frac{\text{Number of Heads}}{\text{Total Number of Tosses}}
$$

For a sufficiently large number of tosses:

```
Experimental Probability → Theoretical Probability
```

---

# 🧠 Algorithm

## Fair Coin Simulation

1. Initialize the number of tosses.
2. Generate random outcomes.
3. Assign:

```
0 → Tail

1 → Head
```

4. Count the number of Heads.
5. Calculate experimental probability:

$$
P(Head)=\frac{Heads}{Total\ Tosses}
$$

6. Repeat for increasing values of tosses.

---

## Biased Coin Simulation

1. Define the bias probability.

Example:

```
P(Head)=0.7
```

2. Generate a random number between 0 and 1.
3. Compare it with the bias value.

Condition:

```
Random Number < 0.7

        ↓

      HEAD
```

Otherwise:

```
TAIL
```

4. Calculate experimental probability.
5. Store the results.

---

# 🛠️ Implementation Details

The C program:

* Uses random number generation.
* Simulates multiple coin tosses.
* Calculates experimental probability.
* Stores results for graph plotting.

Files generated:

```
coin.dat
```

Example format:

```
Number_of_Tosses    Fair_Probability    Biased_Probability
```

Example:

```
100       0.52       0.68
500       0.49       0.71
1000      0.50       0.70
```

---

# 📈 Graph Visualization

GNUPlot is used to visualize the probability convergence.

The graph contains:

### X-axis:

```
Number of Tosses
```

### Y-axis:

```
Experimental Probability
```

The plotting script:

```
coin.gnu
```

uses:

```
coin.dat
```

to generate the graph.

Run:

```bash
gnuplot -persist coin.gnu
```

---

# 🔍 Graph Interpretation

## Fair Coin Graph

Initially, the probability fluctuates because the number of trials is small.

Example:

```
10 tosses:

Probability may be 0.3 or 0.7
```

As the number of tosses increases:

```
Probability approaches 0.5
```

---

## Biased Coin Graph

For a biased coin with:

```
P(Head)=0.7
```

the probability curve gradually stabilizes around:

```
0.7
```

The graph demonstrates that larger experiments produce more accurate probability estimates.

---

# 📊 Expected Observations

| Coin Type   | Theoretical Probability | Experimental Result   |
| ----------- | ----------------------- | --------------------- |
| Fair Coin   | 0.5                     | Approaches 0.5        |
| Biased Coin | Assigned Bias           | Approaches bias value |

---

# ⏱️ Complexity Analysis

Let `n` be the number of coin tosses.

## Time Complexity

Each toss requires constant time.

Therefore:

```
O(n)
```

---

## Space Complexity

Only counters and variables are stored.

Therefore:

```
O(1)
```

(Excluding output file storage)

---

# ▶️ How to Run

## Compile

```bash
gcc coin.c -o coin
```

---

## Execute

### Windows

```bash
coin.exe
```

### Linux/Mac

```bash
./coin
```

---

## Generate Graph

```bash
gnuplot -persist coin.gnu
```

---

# 📁 Files Included

```
Problem-02-Coin-Simulation/

│
├── coin.c
├── coin.exe
├── coin.dat
├── coin.gnu
└── README.md
```

---

# ✅ Conclusion

This experiment demonstrates how probability can be estimated using random simulations.

Observations:

* A fair coin approaches a probability of **0.5** after many trials.
* A biased coin approaches its predefined probability value.
* Increasing the number of experiments improves accuracy.
* Random behaviour becomes predictable when the number of trials is sufficiently large.

The experiment provides practical understanding of probability simulation and the Law of Large Numbers.

---

## 👨‍💻 Author

**Subhang Didwania**

Course:

**Design and Analysis of Algorithms (DAA)**
