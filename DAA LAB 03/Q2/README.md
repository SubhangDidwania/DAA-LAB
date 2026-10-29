# Search the Defective Coin

**Course:** Design and Analysis of Algorithm (DAA) — Lab-03
**Program:** BTech (CSE-B), 3rd Semester
**Instructor:** Dr. Ajaya Kumar Dash

## Problem Statement

A batch of `n` coins is supposed to be identical in weight. At most **one**
coin may be defective — and if defective, it can only be **lighter** than
the rest (never heavier). Using only a balance (two-pan) weighing scale,
the task is to identify the lighter coin if one exists, or correctly report
that **none** of the coins are defective — all in `⌊log₂ n⌋ + c` weighings,
for some positive constant `c`.

## Approach (Divide and Conquer)

1. Split the `n` coins into three groups as evenly as possible (two groups
   of equal size to place on the balance pans, and a leftover group set
   aside when `n` is not divisible by the pan-group size).
2. Weigh the two equal-sized groups against each other:
   - **Balanced:** both groups are genuine; the defective coin (if any)
     must be in the leftover group — recurse on it.
   - **Unbalanced:** the lighter pan contains the defective coin — recurse
     on that group only.
3. The recursion terminates when the current group has 1 coin (that coin
   is the answer) or 0 coins under suspicion (report **none defective**).
4. Because each weighing eliminates roughly half the candidate coins, the
   recursion depth — and hence the number of weighings — is bounded by
   `⌊log₂ n⌋ + c`.

## Complexity

- **Weighings:** O(log₂ n)
- **Recurrence:** T(n) = T(⌈n/2⌉) + O(1) → T(n) = O(log n)

## File Structure

```
Q2/
├── defective.c   # Source code
├── defective.exe # Compiled executable (Windows)
└── README.md
```

## How to Build

```bash
gcc -o defective defective.c
```

On Windows:

```bash
gcc -o defective.exe defective.c
```

## How to Run

```bash
./defective
```

The program prompts for:
1. The number of coins `n`.
2. The weights of the coins (or a simulated defective index for testing).

It then reports the index of the lighter coin (if found) or prints
"No defective coin found", along with the total number of weighings used,
confirming it stays within `⌊log₂ n⌋ + c`.

## Sample Output

```
Enter number of coins: 13
Coin weights: 10 10 10 10 9 10 10 10 10 10 10 10 10

Defective (lighter) coin found at index 5 (weight = 9)
Total weighings used: 4   (log2(13) ≈ 3.70)
```
