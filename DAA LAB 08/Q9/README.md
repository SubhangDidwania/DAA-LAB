# DAA Lab 8 - Problem 9
## Collatz Conjecture

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Number%20Theory-orange)
![Complexity](https://img.shields.io/badge/Time-Variable-green)

---

## Problem Statement

The Collatz Conjecture defines the following iterative sequence for any positive integer `n`:

```text
if n is even: n = n / 2
if n is odd: n = 3n + 1
```

Repeat this until the value becomes `1`.

The problem asks to analyze the trajectory for a single starting value and also across an interval `[a, b]`.

## Objective

The objective is to simulate the recursion behavior, determine the sequence, and analyze the longest trajectory in a range.

## Concept Used - Iterative Control Structures

This problem is a classic example of iterative simulation using loops and arithmetic operations.

```text
while n != 1:
    if n is even:
        n = n / 2
    else:
        n = 3 * n + 1
```

For interval analysis, the program computes the length of each trajectory and keeps track of the longest one.

## Algorithm

```text
1. Read the user choice: single value or interval analysis.
2. If single value, simulate the Collatz sequence until 1.
3. If interval analysis, for each value in [a, b]:
4.     Count the number of terms in its trajectory.
5.     Track the value with the maximum sequence length.
6. Print the trajectory and the longest interval result.
```

## Implementation

File:

```text
09_collatz_conjecture.c
```

## Input

```text
1
6
```

## Output

```text
Sequence: 6 3 10 5 16 8 4 2 1
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| Single value trajectory | variable | `O(1)` |
| Interval analysis | variable over each number in `[a, b]` | `O(1)` |
| Total | depends on trajectory length | `O(1)` |

## Important Test Cases

| Input | Expected result |
|---|---|
| `6` | `6, 3, 10, 5, 16, 8, 4, 2, 1` |
| `1` | `1` |
| `[1, 10]` | longest trajectory starts from `9` |
| `[10, 20]` | longest trajectory starts from `19` |

## Compilation and Execution

```bash
gcc 09_collatz_conjecture.c -o collatz
./collatz
```

Windows:

```powershell
gcc 09_collatz_conjecture.c -o collatz.exe
.\collatz.exe
```
