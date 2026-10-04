# DAA Lab 8 - Problem 2
## Coin Change: Total Number of Ways

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Dynamic%20Programming-orange)
![Complexity](https://img.shields.io/badge/Time-O(nV)-green)

---

## Problem Statement

Given a set of distinct positive coin denominations `C = {c1, c2, ..., cn}` and a target amount `V`, find the total number of distinct combinations of coins whose sum is exactly `V`.

The order of coins does not matter. For example, `1 + 2` and `2 + 1` are treated as the same combination.

## Objective

The objective is to count the number of ways to build the target amount using unlimited coins of each denomination.

## Concept Used - Dynamic Programming

Let `dp[x]` be the number of ways to form amount `x`.

```text
dp[0] = 1
for each coin c:
    for amount = c to V:
        dp[amount] += dp[amount - c]
```

This is the classic unbounded coin change formulation.

## Algorithm

```text
1. Read the number of denominations and target amount.
2. Initialize dp[0] = 1 and all other dp values to 0.
3. For each coin denomination c:
4.     For amount from c to V:
5.         dp[amount] += dp[amount - c]
6. Print dp[V].
```

## Implementation

File:

```text
02_coin_change_total_ways.c
```

## Input

```text
3
1 2 3
4
```

## Output

```text
Total number of combinations: 4
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| DP computation | `O(n * V)` | `O(V)` |
| Total | `O(n * V)` | `O(V)` |

## Important Test Cases

| Coins | Target | Expected output |
|---|---:|---:|
| `1, 2, 3` | `4` | `4` |
| `2, 3` | `7` | `2` |
| `1, 2, 5` | `10` | `10` |
| `1, 3` | `6` | `3` |

## Compilation and Execution

```bash
gcc 02_coin_change_total_ways.c -o coin_ways
./coin_ways
```

Windows:

```powershell
gcc 02_coin_change_total_ways.c -o coin_ways.exe
.\coin_ways.exe
```
