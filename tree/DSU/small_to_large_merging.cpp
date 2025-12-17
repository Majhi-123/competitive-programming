#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> tree[N];
int color[N];
int ans[N];

set<int> dfs(int u, int p) {
    set<int> curr;
    curr.insert(color[u]);

    for (int v : tree[u]) {
        if (v == p) continue;

        set<int> child = dfs(v, u);

        // small to large: ensure curr is larger
        if (child.size() > curr.size())
            swap(child, curr);

        // merge child into curr
        for (int c : child)
            curr.insert(c);
    }

    ans[u] = curr.size();
    return curr;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> color[i];

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}
