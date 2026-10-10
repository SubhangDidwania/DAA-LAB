# DAA Lab 9 - Problem 10
## Greedy Superstring Conjecture

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Approximation%20Heuristic-orange)
![Complexity](https://img.shields.io/badge/Time-O(n%5E3)-green)

---

## Problem Statement

Given a set of strings `S = {s1, s2, ..., sn}`, find the shortest single string that contains each `s_i` as a substring. The problem is open in the exact sense, but the classic greedy approach is widely used as a practical approximation.

## Objective

Generate a compact superstring by repeatedly merging the pair with the largest overlap.

## Concept Used - Greedy Overlap Merging

At each step, choose the pair of strings with the largest suffix-prefix overlap and merge them. This is the classical approximation heuristic for the shortest superstring problem.

## Algorithm

```text
1. Read the input strings.
2. For every pair of strings, compute the maximum overlap of one string's suffix with the other string's prefix.
3. Select the pair giving the largest overlap.
4. Merge the strings using that overlap.
5. Repeat until a single string remains.
6. Print the resulting superstring.
```

## Implementation

File:

```text
10_greedy_superstring.c
```

## Sample Input

```text
3
abc cde efg
```

## Sample Output

```text
abcdefg
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| Pairwise overlap checks | `O(n^3 * L)` | `O(n * L)` |
| Total | `O(n^3 * L)` | `O(n * L)` |

## Important Notes

- This is an approximation heuristic, not necessarily the true optimal superstring.
- The exact version remains an important open research problem in theoretical computer science.
- The greedy method is still useful for practical and educational implementations.

## Compilation and Execution

```bash
gcc 10_greedy_superstring.c -o superstring
./superstring
```

Windows:

```powershell
gcc 10_greedy_superstring.c -o superstring.exe
.\superstring.exe
```
