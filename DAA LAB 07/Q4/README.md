# DAA Lab 7 - Problem 4
## Security Switches

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Recursion-orange)
![Complexity](https://img.shields.io/badge/Sequence-O(M(N))-green)

---

## Problem Statement

A row contains `n` switches, initially all on. The rightmost switch can always be toggled. Any other switch can be toggled only when its immediate right neighbor is on and every switch farther right is off.

Design a minimum-length sequence that turns all switches off.

## Objective

The objective is to obey the switching rules while minimizing the number of toggles.

## Concept Used - Recursive Switch Sequence

Let `M(n)` be the minimum number of moves. The recurrence is:

```text
M(n) = 2*M(n-1)       when n is even
M(n) = 2*M(n-1) + 1   when n is odd
M(1) = 1
```

Therefore:

| Switch count | Minimum moves |
|---|---:|
| Odd `n` | `(2^(n+1) - 1) / 3` |
| Even `n` | `(2^(n+1) - 2) / 3` |

## Algorithm

```text
1. If n is odd, toggle switch n.
2. Recursively construct the sequence for n - 1 switches.
3. Insert a toggle of switch n after every move of the smaller sequence.
4. Simulate the sequence from the all-on state.
5. Confirm that the final state is all off.
```

## Implementation

File:

```text
security_switches.c
```

The program prints and validates the sequence for up to 10 switches. For larger inputs, it prints the exact minimum count without producing a very large sequence.

## Input

```text
Enter the number of switches: 4
```

## Output

```text
Minimum moves: 10
Formula: (2^(n+1) - 2) / 3
Sequence validation: toggles (left to right): 3 4 1 4 3 4 2 4 3 4
legal, minimum length confirmed
```

## Complexity Analysis

| Part | Complexity |
|---|---:|
| Formula | `O(1)` time |
| Sequence generation | `O(M(n))` time |
| Sequence storage for printed cases | `O(M(n))` space |

Here, `M(n)` is the number of minimum moves.

## Important Test Cases

| Switches | Expected moves |
|---:|---:|
| `1` | `1` |
| `2` | `2` |
| `3` | `5` |
| `4` | `10` |

## Compilation and Execution

```bash
gcc security_switches.c -o security_switches
./security_switches
```

Windows:

```powershell
gcc security_switches.c -o security_switches.exe
.\security_switches.exe
```