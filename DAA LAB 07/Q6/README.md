# DAA Lab 7 - Problem 6
## The Best Time to Be Alive

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Event%20Sorting-orange)
![Complexity](https://img.shields.io/badge/Time-O(N%20log%20N)-green)

---

## Problem Statement

Given the birth and death years of prominent scientists, find the time when the largest number of them were alive.

If one scientist dies in the same year another scientist is born, the death event occurs first.

## Objective

The objective is to convert every lifetime into events, process the events chronologically, and track the maximum number of scientists alive.

## Concept Used - Event Sweep

Each scientist contributes two events:

```text
Birth year: +1
Death year: -1
```

Events are sorted by year. When years are equal, death events are sorted before birth events as required by the problem.

## Algorithm

```text
1. Read n scientists.
2. Store one +1 birth event and one -1 death event per scientist.
3. Sort all events by year.
4. For equal years, process -1 before +1.
5. Sweep through the events while maintaining the alive count.
6. Store the year whenever a new maximum is reached.
```

## Implementation

File:

```text
scientists_alive.c
```

## Input

```text
Enter the number of scientists: 4
Enter birth and death years for scientist 1: 1900 1950
Enter birth and death years for scientist 2: 1910 1960
Enter birth and death years for scientist 3: 1920 1930
Enter birth and death years for scientist 4: 1950 2000
```

## Output

```text
Maximum alive: 3
Year: 1920
```

## Complexity Analysis

| Operation | Complexity |
|---|---:|
| Create events | `O(n)` |
| Sort events | `O(n log n)` |
| Sweep events | `O(n)` |
| Total time | `O(n log n)` |
| Extra space | `O(n)` |

## Important Test Cases

- One scientist
- Multiple scientists alive during the same interval
- Death and birth in the same year
- Non-overlapping lifetimes
- Several events in the same year

## Compilation and Execution

```bash
gcc scientists_alive.c -o scientists_alive
./scientists_alive
```

Windows:

```powershell
gcc scientists_alive.c -o scientists_alive.exe
.\scientists_alive.exe
```