# DAA Lab 9 - Problem 5
## Candy Distribution Problem

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Bi-directional%20Greedy-orange)
![Complexity](https://img.shields.io/badge/Time-O(n)-green)

---

## Problem Statement

`n` children stand in a line, each assigned a rating. Every child must receive at least one candy, and a child with a higher rating than a neighbour must receive more candies than that neighbour. Find the minimum total number of candies.

## Objective

Minimise the number of candies while satisfying both left-to-right and right-to-left constraints.

## Concept Used - Bi-directional Greedy

A child gets one candy by default. When ratings increase to the right, increment candies accordingly. Afterwards, scan from right to left and fix any descending slopes.

## Algorithm

```text
1. Read the ratings array.
2. Give each child one candy initially.
3. Traverse left to right:
      if rating[i] > rating[i-1], set candies[i] = candies[i-1] + 1
4. Traverse right to left:
      if rating[i] > rating[i+1], set candies[i] = max(candies[i], candies[i+1] + 1)
5. Sum all candies.
```

## Implementation

File:

```text
05_candy_distribution.c
```

## Sample Input

```text
5
1 0 2 3 2
```

## Sample Output

```text
Minimum candies required: 11
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| Left-to-right and right-to-left scans | `O(n)` | `O(n)` |
| Total | `O(n)` | `O(n)` |

## Important Test Cases

| Ratings | Output |
|---|---|
| `1 2 2` | `4` |
| `1 0 2` | `5` |
| `1 3 2 2 1` | `9` |

## Compilation and Execution

```bash
gcc 05_candy_distribution.c -o candies
./candies
```

Windows:

```powershell
gcc 05_candy_distribution.c -o candies.exe
.\candies.exe
```
