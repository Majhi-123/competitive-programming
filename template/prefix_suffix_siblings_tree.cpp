// Write your code here
// Write your code here
//computing and of subtree & rest of the subtree
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
