q1.You are given an array nums and an integer k.

An array is k-increasing if for all i:

nums[i] <= nums[i+k]


In one operation, you may change any element to any value.

Return the minimum number of operations needed.

//idea ---> [a1,a2,a3,a4,a5,a6,a7,a8,a9,a10] , k=2
//   Get the segment a[i], a[i+k],a[i+2k],......  -->find LIS(longest increasing subsequence of this) 
// answer for 1 such segment is = len(segment) - len(LIS)
// sum for all such segments --->total k segemnts
q2.Minimize Maximum Segment XOR

You are given an array nums and an integer k.

Split nums into exactly k non-empty contiguous segments.

Define the cost of a split =
maximum XOR of all the k segment XORs.

Return the minimum possible cost.

(VERY HARD — requires binary search + DP + bit tricks.)
