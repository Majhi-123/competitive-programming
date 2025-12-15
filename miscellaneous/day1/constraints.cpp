Level 1 — Easy

You are given an integer array.
Return the sum of absolute differences between each element and the array median.

Example: [1,10,2,9] → median=5 → answer = |1-5|+|10-5|+|2-5|+|9-5| = 16.

Level 2 — Medium Constraint

Now the array may have up to 10⁵ elements and you must compute this after each update:

Update index i to new value v

Print new total cost

(Q queries; must be faster than O(n) per query.)

Level 3 — Hard Constraint

Now you must support:

Update index i

Query cost on any range [l, r]

Hint: two Fenwick trees or segment tree with augmented data.
