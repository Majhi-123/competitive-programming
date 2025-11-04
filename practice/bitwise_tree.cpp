//DE SHAW
// An unweighted tree is given with 
// N
// N vertices. Each vertex 
// v
// i
// v 
// i
// ​
//   has some value 
// v
// a
// l
// i
// val 
// i
// ​
//   associated with it. Your task is to find the number of ways to remove an edge from the tree such that the bitwise AND of the two trees thus formed are equal.

// Bitwise AND of a tree is defined as the bitwise AND of all the values of the nodes of the tree.

// Input Format
// The first line contains an integer 
// T
// T - the number of testcases.
// T
// T testcases follows, where
// The first line of each testcase contains an integer 
// N
// N - the number of vertices in the tree.

// The second line of each testcase contains 
// N
// N integers representing the value of each node.

// The next 
// n
// −
// 1
// n−1 lines contain two space separated integers denoting the edges between the two vertices(
// 0
// 0-indexed).

// Output Format
// For each test case, output the number of ways to remove an edge from the tree such that the bitwise AND of the two trees thus formed are equal.

// Constraints
// 1
// ≤
// T
// ≤
// 100
// 1≤T≤100
// 2
// ≤
// N
// ≤
// 1
// 0
// 5
// 2≤N≤10 
// 5
 
// 0
// ≤
// u
// i
// ,
// v
// i
// ≤
// N
// −
// 1
// 0≤u 
// i
// ​
//  ,v 
// i
// ​
//  ≤N−1
// u
// i
// ≠
// v
// i
// u 
// i
// ​
 
// 
// =v 
// i
// ​
 
// 1
// ≤
// v
// a
// l
// i
// ≤
// 2
// 31
// −
// 1
// 1≤val 
// i
// ​
//  ≤2 
// 31
//  −1
// Sum of 
// N
// N over all testcases does not exceed 
// 1
// 0
// 5
// 10 
// 5
 // Write your code here
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 100005;
vector<int> adj[MAXN];
int val[MAXN];
int sub_and[MAXN];
int total_and;

void dfs(int u, int p) {
    sub_and[u] = val[u];
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sub_and[u] &= sub_and[v];
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> val[i];
        for (int i = 0; i < n; i++) adj[i].clear();

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 1️⃣ Compute total AND
        total_and = val[0];
        for (int i = 1; i < n; i++) total_and &= val[i];

        // 2️⃣ Compute subtree AND
        dfs(0, -1);

        // 3️⃣ Count edges that satisfy condition
        int ans = 0;
        for (int i = 1; i < n; i++) { // all nodes except root
            if (sub_and[i] == total_and)
                ans++;
        }

        cout << ans << "\n";
    }
}
