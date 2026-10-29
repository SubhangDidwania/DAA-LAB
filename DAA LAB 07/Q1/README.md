# DAA Lab 7 - Problem 1
## Invert the Coin Triangle

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Geometric%20Optimization-orange)
![Complexity](https://img.shields.io/badge/Formula-O(1)-green)

---

## Problem Statement

Given an equilateral triangle made from closely packed coins, design an algorithm to turn the triangle upside down by sliding one coin at a time. Find the minimum number of moves and derive a compact formula.

## Objective

The objective is to maximize the number of coins that remain in common positions between the original upward triangle and the translated downward triangle. Only the unmatched coins need to be moved.

## Concept Used - Lattice Overlap

The coins occupy points on an equilateral triangular lattice. For each possible translation of the inverted triangle, the program counts the overlapping lattice points. The best translation gives the minimum number of slides.

Let `n = 3q + r`. The minimum number of moves is:

| Value of `r` | Minimum moves |
|---:|---:|
| `0` | `q(3q + 1) / 2` |
| `1` | `3q(q + 1) / 2` |
| `2` | `(q + 1)(3q + 2) / 2` |

For example, four rows need 3 moves and five rows need 5 moves.

## Algorithm

```text
1. Read the number of rows n.
2. Compute q = n / 3 and r = n % 3.
3. Use the appropriate formula for r.
4. For small n, enumerate translations of the inverted triangle.
5. Count the maximum overlap and compare it with the formula.
```

## Implementation

File:

```text
coin_triangle.c
```

The program also performs an exact lattice check for up to 60 rows.

## Input

```text
Enter the number of rows in the coin triangle: 5
```

## Output

```text
Minimum moves: 5
Coins: 15
Exact lattice check: passed
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| Formula | `O(1)` | `O(1)` |
| Exact lattice check | `O(n^4)` | `O(1)` |

The exact check examines `O(n^2)` possible translations. For each translation, it scans `O(n^2)` lattice points, giving `O(n^2) * O(n^2) = O(n^4)` time. It stores only counters and loop variables, so its extra space is `O(1)`.

## Important Test Cases

| Rows | Expected moves |
|---:|---:|
| `1` | `0` |
| `4` | `3` |
| `5` | `5` |
| `10` | `18` |

## Compilation and Execution

```bash
gcc coin_triangle.c -o coin_triangle
./coin_triangle
```

Windows:

```powershell
gcc coin_triangle.c -o coin_triangle.exe
.\coin_triangle.exe
```