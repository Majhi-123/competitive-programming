// ques-->🧩 Problem Statement: Nice Pairs in a Tree

// You are given a tree consisting of n nodes numbered from 1 to n.
// The tree has n − 1 edges, and each edge is labeled with an uppercase English letter ('A' to 'Z').

// 🔹 Definition: Path String

// For any two nodes u and v, there exists a unique path between them in the tree.

// Consider the sequence of characters written on the edges along the path from u to v.

// This sequence forms a string.

// 🔹 Definition: Nice Pair

// A pair of nodes (u, v) is called a nice pair if:

// The string formed by the characters on the path between u and v

// can be rearranged to form a palindrome

// 📌 Rearrangement is allowed.

// 🔹 Task

// Your task is to count the total number of nice pairs (u, v) such that 1 ≤ u < v ≤ n.

// 🔹 Input Format

// The first line contains an integer n — the number of nodes.

// The next n − 1 lines each contain:

// u v c


// where:

// u and v are connected nodes

// c is the uppercase letter written on the edge between them

// 🔹 Output Format

// Print a single integer — the number of nice pairs.

// 🔹 Constraints (typical)

// 1 ≤ n ≤ 2 × 10^5

// c ∈ ['A', 'Z']

The graph is guaranteed to be a tree.
