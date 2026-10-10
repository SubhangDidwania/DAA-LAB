# DAA Lab 9 - Problem 8
## Minimum Number of Meeting Rooms

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Interval%20Greedy-orange)
![Complexity](https://img.shields.io/badge/Time-O(n%20log%20n)-green)

---

## Problem Statement

Given start and end times for meetings, find the minimum number of conference rooms required to host them without overlap.

## Objective

The objective is to determine how many rooms are necessary to schedule all meetings by reusing rooms whenever a meeting ends.

## Concept Used - Interval Greedy

Sort all start times and end times. A room is needed whenever a new meeting begins before all previous meetings have ended.

## Algorithm

```text
1. Read all meeting intervals.
2. Sort the start times and end times separately.
3. Sweep through the timeline.
4. If a meeting starts before the current earliest ending one finishes, allocate another room.
5. Otherwise, reuse an existing room.
6. Print the minimum number of rooms.
```

## Implementation

File:

```text
08_min_meeting_rooms.c
```

## Sample Input

```text
6
0 30
5 10
15 20
20 25
30 40
35 45
```

## Sample Output

```text
Minimum rooms required: 2
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| Sorting and sweep | `O(n log n)` | `O(n)` |
| Total | `O(n log n)` | `O(n)` |

## Important Test Cases

| Intervals | Output |
|---|---|
| `[0,30], [5,10], [15,20]` | `2` |
| `[1,5], [2,7], [3,9]` | `3` |
| `[1,3], [2,4], [3,5]` | `2` |

## Compilation and Execution

```bash
gcc 08_min_meeting_rooms.c -o rooms
./rooms
```

Windows:

```powershell
gcc 08_min_meeting_rooms.c -o rooms.exe
.ooms.exe
```
