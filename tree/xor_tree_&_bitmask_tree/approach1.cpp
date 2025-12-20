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

//The graph is guaranteed to be a tree.

approach from root to child nodes use bitmask, to store no of characters which occur odd or even length ---> 0000000, means all even 00010011, means a,b,d are odd counts
mask[child] = mask[parent] ^ (1<<edge_val);
now for each path between node u to v , either there needs to be every character needs to be even no.  of times, or only one element exists at odd count
so mask[u]^mask[v] == 0 || (1<<k)   ----->root to u ^ root to v
we can use map, count frequncy of each xor we are founding for each node. then for each node try to find if alternat exor exists --> O(n*26);

// Great question — you’re asking for problem patterns, not random links.
// Below is a curated list of problems that use the SAME core ideas you just mastered:

// Tree / XOR / Bitmask / Parity / Frequency-map counting

// I’ll group them by pattern, explain what’s common, and give concrete problems to practice.

// 🧠 PATTERN 1: Tree + XOR from root

// (Exactly what you just did)

// Core idea

// Store something from root → node

// Use XOR to cancel common paths

// Path query becomes xor[u] ^ xor[v]

// Problems

// Codeforces – Tree and XOR Queries

// Path XOR queries

// Same “cancel LCA automatically” trick

// Codeforces – XOR on Tree Paths

// Count / maximize XOR on paths

// LeetCode – Count Pairs With XOR in a Range

// Same mask-frequency logic (but array instead of tree)

// 👉 If you understand your problem, these feel natural.

// 🧠 PATTERN 2: Palindrome via Parity / Bitmask

// (Very important pattern for high-paying companies)

// Core idea

// Palindrome ⇔ ≤1 odd frequency

// Represent frequency parity with bitmask

// Use mask ^ (1<<k) trick

// Problems

// LeetCode 1915 – Number of Wonderful Substrings

// EXACT SAME logic

// Replace tree with prefix XOR on string

// LeetCode 1542 – Find Longest Awesome Substring

// Same parity mask idea

// Uses map + XOR

// Codeforces – Palindromic Characteristics

// Frequency parity reasoning

// 👉 Your tree problem = LC 1915 on a tree

// 🧠 PATTERN 3: Prefix XOR + Frequency Map

// (This is how n² becomes n)

// Core idea

// Instead of pairs (i, j):

// Fix j

// Count how many previous i work

// Problems

// LeetCode – Subarrays With XOR K

// LeetCode – Count Subarrays With Equal XOR

// Codeforces – Little Girl and Problem on XOR

// 👉 This is the same mental leap you made from n² → hashmap.

// 🧠 PATTERN 4: Tree + “forget the tree after DFS”

// (Interviewers LOVE this)

// Core idea

// Use DFS only to compute values

// Actual logic is array / map based

// Problems

// Codeforces – DSU on Tree (easy versions)

// LeetCode – Sum of Distances in Tree

// Codeforces – Tree Queries (offline)

// 👉 You already used this idea when you said
// “we can count outside DFS”.

// 🧠 PATTERN 5: At most K odd / mismatch

// (Your problem is K = 1)

// Core idea

// Generalize condition from “≤1 odd” to “≤K odd”

// Same bitmask trick, larger neighborhood

// Problems

// LeetCode – Longest Substring With At Most K Odd Counts

// Codeforces – Substrings with at most K bad chars

// Interview variant:

// “What if at most 2 odd characters are allowed?”

// 🧠 PATTERN 6: OA / 30 LPA Company-style questions

// These aren’t labeled hard, but test depth.

// Examples

// Count pairs on tree satisfying some parity / xor condition

// Path queries without LCA

// Precompute → answer many queries

// “Rearrangement allowed” (huge hint!)
