# DAA Lab 9 - Problem 2
## Huffman Coding

![Language](https://img.shields.io/badge/Language-C-blue)
![Topic](https://img.shields.io/badge/DAA-Greedy%20Compression-orange)
![Complexity](https://img.shields.io/badge/Time-O(n%20log%20n)-green)

---

## Problem Statement

Given symbol frequencies, construct a prefix-free binary code with minimum expected length. Also output the canonical Huffman codebook in which codes are ordered lexicographically by length.

## Objective

The objective is to minimise the total expected number of bits used to encode the symbols.

## Concept Used - Greedy Merge Tree

Huffman coding repeatedly merges the two lowest-frequency symbols into a parent node until a single tree remains. The path from root to each symbol forms its code.

## Algorithm

```text
1. Read the number of symbols and their frequencies.
2. Put all symbols in a min-heap keyed by frequency.
3. Extract the two smallest nodes and merge them.
4. Insert the merged node back into the heap.
5. Recurse until one node remains.
6. Traverse the tree to assign binary codes.
7. Convert the codebook to canonical form and print it.
```

## Implementation

File:

```text
02_huffman_coding.c
```

## Sample Input

```text
6
A 5
B 9
C 12
D 13
E 16
F 45
```

## Sample Output

```text
A 000
B 001
C 010
D 011
E 100
F 101
```

## Complexity Analysis

| Part | Time Complexity | Space Complexity |
|---|---:|---:|
| Heap construction and merges | `O(n log n)` | `O(n)` |
| Code generation | `O(n)` | `O(n)` |
| Total | `O(n log n)` | `O(n)` |

## Important Test Cases

| Frequencies | Expected behaviour |
|---|---|
| all equal | Huffman tree balances equally |
| one dominant symbol | dominant symbol gets shortest code |
| repeated merges | prefix-free property preserved |

## Compilation and Execution

```bash
gcc 02_huffman_coding.c -o huffman
./huffman
```

Windows:

```powershell
gcc 02_huffman_coding.c -o huffman.exe
.\huffman.exe
```
