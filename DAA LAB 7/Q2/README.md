# DAA Lab 7 - Problem 2
## Super Egg Testing Experiment

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Dynamic%20Programming-orange)
![Complexity](https://img.shields.io/badge/Time-O(EF%5E2)-green)

---

## Problem Statement

Given `E` identical eggs and a building with `F` floors, determine the minimum number of droppings needed to find the highest floor from which an egg can fall without breaking, in the worst case.

For the assignment, use 2 eggs and 100 floors. The generalized solution must work for arbitrary values of `E` and `F`.

## Objective

The objective is to minimize the number of trials while considering both possible results of every drop:

- The egg breaks, so the answer is below the tested floor.
- The egg survives, so the answer is at or above the tested floor.

## Concept Used - Dynamic Programming

Let `dp[e][f]` be the minimum number of trials for `e` eggs and `f` floors. If an egg is dropped from floor `x`, the worst case is:

```text
1 + max(dp[e - 1][x - 1], dp[e][f - x])
```

The first term handles a broken egg. The second handles a surviving egg. Try every possible `x` and choose the minimum worst-case value.

## Algorithm

```text
1. Set dp[1][f] = f for every floor f.
2. Set dp[e][0] = 0.
3. For each number of eggs e from 2 to E:
4.     For each number of floors f from 1 to F:
5.         Try every dropping floor x from 1 to f.
6.         Store the minimum of 1 + max(break case, survive case).
7. Print dp[E][F].
```

## Implementation

File:

```text
egg_drop.c
```

## Input

```text
Enter the number of eggs and floors: 2 100
```

## Output

```text
Minimum droppings: 14
```

## Complexity Analysis

| Operation | Complexity |
|---|---:|
| Number of states | `O(EF)` |
| Choices per state | `O(F)` |
| Total time | `O(EF^2)` |
| Space | `O(EF)` |

## Important Test Cases

| Eggs | Floors | Expected result |
|---:|---:|---:|
| `1` | `10` | `10` |
| `2` | `10` | `4` |
| `2` | `100` | `14` |
| `3` | `14` | `4` |

## Compilation and Execution

```bash
gcc egg_drop.c -o egg_drop
./egg_drop
```

Windows:

```powershell
gcc egg_drop.c -o egg_drop.exe
.\egg_drop.exe
```