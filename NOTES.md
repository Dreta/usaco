# USACO Notes

## Key Observations

* Draw up your own test cases! Check for corner cases!
* For questions about permutations needing a speed-up, read Bronze 2021 January Problem 3.
* Minimizing something... maybe maximizing another thing makes it easier?
* Adding within a range can be converted into a prefix sum problem by adding the value at the start of the range and subtracting the value at the end of the range. This is because the value at the start of the range is added to all values in the range, and the value at the end of the range is subtracted from all values after the range. This is a common technique used in prefix sum problems. Read "Haybale Stacking" in `silver/1-prefix-sum`.
