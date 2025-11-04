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
// Write your code here
// Write your code here

#include <bits/stdc++.h>
using namespace std;

const int FULL_MASK = (1LL << 31) - 1; // all bits 1 for 31 bits (values ≤ 2^31 - 1)

int n;
vector<int> val;
vector<vector<int>> adj;
vector<int> sub, up;
long long ans;

void dfs1(int u, int p) {
    sub[u] = val[u];
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        sub[u] &= sub[v];
    }
}

void dfs2(int u, int p) {
    int m = adj[u].size();
    vector<int> prefix(m, FULL_MASK), suffix(m, FULL_MASK);

    // prefix AND
    for (int i = 0; i < m; i++) {
        int v = adj[u][i];
        if (v == p) prefix[i] = (i == 0 ? FULL_MASK : prefix[i - 1]);
        else prefix[i] = (i == 0 ? sub[v] : (prefix[i - 1] & sub[v]));
    }

    // suffix AND
    for (int i = m - 1; i >= 0; i--) {
        int v = adj[u][i];
        if (v == p) suffix[i] = (i == m - 1 ? FULL_MASK : suffix[i + 1]);
        else suffix[i] = (i == m - 1 ? sub[v] : (suffix[i + 1] & sub[v]));
    }

    for (int i = 0; i < m; i++) {
        int v = adj[u][i];
        if (v == p) continue;

        int left = (i > 0 ? prefix[i - 1] : FULL_MASK);
        int right = (i < m - 1 ? suffix[i + 1] : FULL_MASK);
        int siblings_and = left & right;

        up[v] = val[u];
        if (p != -1) up[v] &= up[u];
        up[v] &= siblings_and;

        dfs2(v, u);
    }
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        val.assign(n, 0);
        adj.assign(n, {});
        sub.assign(n, 0);
        up.assign(n, FULL_MASK);
        ans = 0;

        for (int i = 0; i < n; i++)
            cin >> val[i];

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs1(0, -1);
        up[0] = FULL_MASK;
        dfs2(0, -1);

        for (int v = 1; v < n; v++) {
            if (sub[v] == up[v]) ans++;
        }

        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
