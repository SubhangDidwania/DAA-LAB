# Problem 4 — Maximum Party Attendance

## Problem Statement

A camera records the entry time `ai` and exit time `bi` of each of `n` people attending a party.

The task is to determine the time when the maximum number of people were simultaneously present.

All entry and exit times are distinct.

The required complexity is **O(n log n)**.

---

## Approach

Convert every entry and exit into an event.

For every person:

```text
Entry → +1
Exit  → -1
```

Then sort all events according to their time.

Traverse the sorted events while maintaining a counter:

```text
current = current + event.type
```

Whenever `current` becomes greater than the previous maximum, update:

```text
maximum
maxTime
```

---

## Algorithm

```text
1. For every person:
      Create an entry event (+1).
      Create an exit event (-1).

2. Sort all 2n events by time.

3. Set current = 0 and maximum = 0.

4. Traverse the events:
      current += event.type

      If current > maximum:
          maximum = current
          maxTime = event.time

5. Print maximum and maxTime.
```

---

## Example

Consider:

```text
Person 1: 2 7
Person 2: 4 6
Person 3: 5 9
```

Events:

```text
2 → +1
4 → +1
5 → +1
6 → -1
7 → -1
9 → -1
```

At time `5`:

```text
3 people
```

Therefore:

```text
Maximum people = 3
Time = 5
```

---

## Time Complexity

There are `2n` events.

Sorting:

```text
O(2n log(2n)) = O(n log n)
```

Scanning:

```text
O(n)
```

Therefore:

```text
O(n log n)
```

### Overall Complexity

**Time:** `O(n log n)`

**Space:** `O(n)`

---

## Key Concepts

* Event-based processing
* Sorting
* Sweep-line technique
* Counting active intervals
* Time complexity
