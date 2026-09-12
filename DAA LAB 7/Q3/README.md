# DAA Lab 7 - Problem 3
## Reve's Four-Peg Puzzle

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Frame--Stewart-orange)
![Complexity](https://img.shields.io/badge/DP-O(N%5E2)-green)

---

## Problem Statement

There are `n` disks of different sizes on one peg and four pegs in total. Move all disks to another peg while obeying the rule that a larger disk cannot be placed on a smaller disk.

For eight disks, the program must produce a solution in 33 moves and generalize the method for `n` disks.

## Objective

The objective is to choose how many top disks should be moved temporarily with four pegs before moving the remaining disks with the ordinary three-peg Tower of Hanoi procedure.

## Concept Used - Frame-Stewart Dynamic Programming

Let `T4(n)` be the minimum number of moves using four pegs. If `k` top disks are moved aside:

```text
T4(n) = min(2 * T4(k) + T3(n - k))
T3(m) = 2^m - 1
```

The first term moves the top `k` disks to a spare peg. The three-peg term moves the remaining disks to the destination. The final term moves the `k` disks onto the destination.

## Algorithm

```text
1. Set T3(0) = 0 and T3(1) = 1.
2. Set T4(0) = 0 and T4(1) = 1.
3. For n from 2 to the requested disk count:
4.     Try every split k from 1 to n - 1.
5.     Select the minimum 2*T4(k) + T3(n-k).
6. Store the best split.
7. Use the stored splits to print moves for small n.
```

## Implementation

File:

```text
reve_hanoi.c
```

The complete move sequence is printed for at most eight disks so that the result remains readable.

## Input

```text
Enter the number of disks: 8
```

## Output

```text
Minimum moves (Frame-Stewart): 33
Move disk from A to D
...
```

## Complexity Analysis

| Part | Complexity |
|---|---:|
| Dynamic programming | `O(n^2)` time |
| DP tables | `O(n)` space |
| Printing moves | `O(T4(n))` time |

## Important Test Cases

| Disks | Expected moves |
|---:|---:|
| `1` | `1` |
| `3` | `5` |
| `4` | `9` |
| `8` | `33` |

## Compilation and Execution

```bash
gcc reve_hanoi.c -o reve_hanoi
./reve_hanoi
```

Windows:

```powershell
gcc reve_hanoi.c -o reve_hanoi.exe
.\reve_hanoi.exe
```