# DAA Lab 7 - Problem 5
## Hitting a Moving Target

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Greedy%20Strategy-orange)
![Complexity](https://img.shields.io/badge/Time-O(N)-green)

---

## Problem Statement

A target hides in one of `n > 1` spots arranged in a line. The shooter cannot see the target. Between two shots, the target must move to an adjacent spot.

Design a strategy that guarantees hitting the target, or prove that no such strategy exists.

## Objective

The objective is to force the target into a spot that will be shot, regardless of its initial position and movement choices.

## Concept Used - Inward and Outward Sweep

For `n = 2`, shoot spot 1 twice. The target cannot remain away from spot 1 between the two shots.

For `n >= 3`, use:

```text
2, 3, ..., n - 1, n - 1, ..., 3, 2
```

If the target avoids the inward sweep, it is forced toward an endpoint. The reverse sweep then catches it because the target must move one position after every shot.

## Algorithm

```text
1. Read n.
2. If n = 2, print shots 1, 1.
3. Otherwise, print spots 2 through n - 1.
4. Print spots n - 1 down through 2.
```

## Implementation

File:

```text
moving_target.c
```

The program prints a guaranteed sequence rather than attempting to observe the hidden target.

## Input

```text
Enter the number of hiding spots: 6
```

## Output

```text
Guaranteed strategy in 8 shots:
2 3 4 5 5 4 3 2
```

## Complexity Analysis

| Part | Complexity |
|---|---:|
| Time to print strategy | `O(n)` |
| Extra space | `O(1)` |
| Number of shots for `n >= 3` | `2n - 4` |

## Important Test Cases

| Spots | Expected strategy length |
|---:|---:|
| `2` | `2` |
| `3` | `2` |
| `4` | `4` |
| `6` | `8` |

## Compilation and Execution

```bash
gcc moving_target.c -o moving_target
./moving_target
```

Windows:

```powershell
gcc moving_target.c -o moving_target.exe
.\moving_target.exe
```