# DAA Lab 8 - Problem 1
## Minimum Coin Change

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Dynamic%20Programming-orange)
![Complexity](https://img.shields.io/badge/Time-O(nV)-green)

---

## Problem Statement

Given an integer array of coin denominations `C = {c1, c2, ..., cn}` and a target amount `V`, find the minimum number of coins needed to make up that amount. If the amount cannot be formed, return `-1`.

## Objective

The objective is to minimize the total number of coins used while allowing unlimited supply of each denomination.

## Concept Used - Dynamic Programming

Let `dp[x]` represent the minimum number of coins required to form amount `x`.

```text
dp[0] = 0
for amount = 1 to V:
    dp[amount] = INF
    for each coin c:
        if c <= amount and dp[amount - c] != INF:
            dp[amount] = min(dp[amount], dp[amount - c] + 1)
```

## Algorithm

```text
1. Read the number of coin denominations n.
2. Read the denominations and target amount V.
3. Initialize dp[0] = 0 and all other values to infinity.
4. For each amount from 1 to V:
5.     Try every coin denomination.
6.     Update the minimum coin count for that amount.
7. Print the result.
```

## Implementation

File:

```text
01_minimum_coin_change.c
```

## Input

```text
4
1 3 4
6
```

## Output

```text
Minimum number of coins required: 2
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| DP computation | `O(n * V)` | `O(V)` |
| Total | `O(n * V)` | `O(V)` |

## Important Test Cases

| Coins | Target | Expected output |
|---|---:|---:|
| `1, 3, 4` | `6` | `2` |
| `2, 3` | `1` | `-1` |
| `1, 2, 5` | `11` | `3` |
| `1, 5, 10` | `15` | `2` |

## Compilation and Execution

```bash
gcc 01_minimum_coin_change.c -o min_coin
./min_coin
```

Windows:

```powershell
gcc 01_minimum_coin_change.c -o min_coin.exe
.\min_coin.exe
```
