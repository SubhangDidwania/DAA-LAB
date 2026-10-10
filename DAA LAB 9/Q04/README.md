# DAA Lab 9 - Problem 4
## Minimum Cost to Connect Sticks

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Greedy%20Merging-orange)
![Complexity](https://img.shields.io/badge/Time-O(n%20log%20n)-green)

---

## Problem Statement

You are given sticks of lengths `L1, L2, ..., Ln`. Connecting two sticks of lengths `x` and `y` costs `x + y`, producing a single stick of length `x + y`. Find the minimum total cost to merge all sticks into one.

## Objective

The goal is to always combine the shortest pieces first so that the accumulated cost is as small as possible.

## Concept Used - Greedy Merging

The optimal strategy is to repeatedly merge the two shortest sticks, because each merge is the cheapest possible next step.

## Algorithm

```text
1. Read all stick lengths.
2. Insert them into a min-heap.
3. While more than one stick remains:
      pop the two smallest sticks,
      add their sum to the total cost,
      push the merged length back into the heap.
4. Print the minimum total cost.
```

## Implementation

File:

```text
04_min_cost_connect_sticks.c
```

## Sample Input

```text
4
1 2 3 4
```

## Sample Output

```text
Minimum total cost: 33
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| Heap-based merges | `O(n log n)` | `O(n)` |
| Total | `O(n log n)` | `O(n)` |

## Important Test Cases

| Sticks | Expected result |
|---|---|
| `1 2 3` | `11` |
| `5 5 5` | `30` |
| `1 8 10 20` | `142` |

## Compilation and Execution

```bash
gcc 04_min_cost_connect_sticks.c -o sticks
./sticks
```

Windows:

```powershell
gcc 04_min_cost_connect_sticks.c -o sticks.exe
.\sticks.exe
```
