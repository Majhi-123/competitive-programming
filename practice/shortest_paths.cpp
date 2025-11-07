//apple
Given an undirected graph with N nodes and M edges. Find the number of nodes that lie on any shortest path from node S to node T. If there is no path from S to T, print -1.

In a graph, a path is a sequence of nodes in which each node is connected by an edge to the next. The path length corresponds to the number of edges in the path.

Input Format
The first line contains an integer T ( 1 ≤ T ≤ 100000), the number of test cases.

The first line of each test case contains 4 space-separated integers N, M, S, T (2 ≤ N ≤ 10^5, 0 ≤ M ≤ (N*(N-1))/2, 1 ≤ S, T ≤ N, S≠T.

The next M lines contain 2 space-separated integers A, B which represents that there is an edge between node A and B. (1 ≤ A, B ≤ N, A≠B).

Sum of N+M across all test cases ≤ 10^6.

Output Format
For each test case, print the number of nodes that lie on any shortest path from node S to node T. If there is no path from S to T, print -1.
#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int start, const vector<vector<int>>& adj) {
    int n = adj.size() - 1;
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M, S, T;
        cin >> N >> M >> S >> T;

        vector<vector<int>> adj(N + 1);
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        auto distS = bfs(S, adj);
        auto distT = bfs(T, adj);

        int d = distS[T];
        if (d == -1) {
            cout << -1 << "\n";
            continue;
        }

        int count = 0;
        for (int i = 1; i <= N; i++) {
            if (distS[i] != -1 && distT[i] != -1 && distS[i] + distT[i] == d)
                count++;
        }
        cout << count << "\n";
    }
    return 0;
}
