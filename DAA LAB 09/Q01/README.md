# DAA Lab 9 - Problem 1
## Fractional Knapsack with Deterioration Rate

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Greedy%20Scheduling-orange)
![Complexity](https://img.shields.io/badge/Time-O(nW)-green)

---

## Problem Statement

You are given `n` items with base values `v_i`, weights `w_i`, and deterioration rates `λ_i > 0`. If an item is consumed at time `t`, its effective value density becomes

`(v_i / w_i) - λ_i * t`.

The knapsack has capacity `W`. Determine the optimal scheduling order and fractional choices to maximise the total value.

## Objective

The goal is to decide which fraction of which item to take at each moment so that total value is maximised under the decay rule.

## Concept Used - Greedy Scheduling

At any moment, the best strategy is to choose the item with the highest effective value density among the remaining items; once selected, take as much as possible until the next item becomes more attractive.

```text
current_density(item) = (value / weight) - decay_rate * elapsed_time
```

## Algorithm

```text
1. Read n, capacity W, and each item (value, weight, decay rate).
2. Maintain elapsed time and remaining capacity.
3. Repeatedly choose the item with largest current density.
4. Take a fraction of that item up to the remaining capacity.
5. Update the total value and the elapsed time.
6. Stop when the bag is full or no positive-density item remains.
```

## Implementation

File:

```text
01_fractional_knapsack_deterioration.c
```

## Sample Input

```text
4 10
50 3 0.4
80 5 0.2
60 4 0.3
70 2 0.5
```

## Sample Output

```text
Maximum total value: 184.00
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| Greedy selection across items | `O(n * W)` in the fractional model | `O(n)` |
| Total | `O(n * W)` | `O(n)` |

## Important Test Cases

| Input | Expected behaviour |
|---|---|
| `n = 3, W = 5` with positive decay | picks the best current-density item first |
| Items with zero or negative density | avoid them after they become unattractive |
| Very small capacity | all items may be selected partly |

## Compilation and Execution

```bash
gcc 01_fractional_knapsack_deterioration.c -o knapsack
./knapsack
```

Windows:

```powershell
gcc 01_fractional_knapsack_deterioration.c -o knapsack.exe
.\knapsack.exe
```
