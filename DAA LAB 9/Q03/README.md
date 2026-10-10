# DAA Lab 9 - Problem 3
## Minimum Initial Fuel (Reverse Greedy)

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Reverse%20Greedy-orange)
![Complexity](https://img.shields.io/badge/Time-O(n%20log%20n)-green)

---

## Problem Statement

A vehicle needs to reach a target distance `D` starting with fuel `F`. Along the route are stations `(d_i, f_i)`, where `d_i` is the distance from the origin and `f_i` is the amount of fuel available there. Find the minimum number of refuelling stops required to reach the target.

## Objective

The objective is to minimise the number of stops while ensuring the vehicle never runs out of fuel before the target.

## Concept Used - Reverse Greedy

Whenever the current fuel is insufficient to move to the next reachable station, pick the maximum fuel available among the stations that are already reachable.

## Algorithm

```text
1. Sort stations by distance from the origin.
2. Maintain a max-heap of fuel values from all reachable stations.
3. While the current fuel cannot reach the target:
      add all stations within reach to the heap,
      if no station is available, stop as impossible,
      take the maximum fuel and increment the stop count.
4. Print the minimum number of refuelling stops.
```

## Implementation

File:

```text
03_minimum_initial_fuel.c
```

## Sample Input

```text
4 1 10
2 2
3 3
5 5
7 4
```

## Sample Output

```text
Minimum refuelling stops: 2
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| Sorting and heap operations | `O(n log n)` | `O(n)` |
| Total | `O(n log n)` | `O(n)` |

## Important Test Cases

| Scenario | Expected behaviour |
|---|---|
| reachable fuel already sufficient | returns `0` |
| unreachable because of missing fuel | reports impossible |
| many stations clustered together | heap chooses the largest fuel first |

## Compilation and Execution

```bash
gcc 03_minimum_initial_fuel.c -o fuel
./fuel
```

Windows:

```powershell
gcc 03_minimum_initial_fuel.c -o fuel.exe
.uel.exe
```
