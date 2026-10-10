# DAA Lab 9 - Problem 6
## Reorganize String with K-Distance Apart

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Greedy%20Constraint-orange)
![Complexity](https://img.shields.io/badge/Time-O(n%20log%20n)-green)

---

## Problem Statement

Given a string `S` and an integer `K`, rearrange the letters so that the same character is at least `K` positions apart. If it is impossible, return an empty string.

## Objective

Arrange the letters while respecting the distance constraint and preserving all characters.

## Concept Used - Greedy with Validity Check

At every step, choose the character with the maximum remaining frequency that does not violate the latest `K` placements.

## Algorithm

```text
1. Count the frequency of each character.
2. Repeatedly choose the character with the highest remaining count.
3. Ensure that it is not placed within K positions of the same character.
4. If a valid character does not exist, return an empty string.
5. Continue until all characters are placed.
```

## Implementation

File:

```text
06_reorganize_string.c
```

## Sample Input

```text
aab 2
```

## Sample Output

```text
aba
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| Character selection and backtracking | `O(n log n)` worst-case | `O(n)` |
| Total | `O(n log n)` | `O(n)` |

## Important Test Cases

| String | K | Output |
|---|---:|---|
| `aab` | `2` | `aba` |
| `aaab` | `2` | empty |
| `abc` | `1` | `acb` |

## Compilation and Execution

```bash
gcc 06_reorganize_string.c -o reorganize
./reorganize
```

Windows:

```powershell
gcc 06_reorganize_string.c -o reorganize.exe
.eorganize.exe
```
