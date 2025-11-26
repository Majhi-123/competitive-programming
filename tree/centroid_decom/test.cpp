#include <bits/stdc++.h>
using namespace std;


int dfs_size(int node, int par){
    sz[node] = 1;
    
    for(auto it: adj[node]){
        if(it!=par && !blocked[it]){
            sz[node] += sz[it];
        }
    }
    
    return sz[node];
}

int find_centroid(int node,int par, int total){
    
    for(auto it: adj[node]){
        if(it!=par && !blocked[it]){
            if(sz[it] > total/2){
                return find_centroid(it,node,total);
            }
        }
    }
    
    return node;
}

void dfs_dis(int node,int par,int level){
    
    for(auto it: adj[node]){
        if(it!=par && !blocked[it]){
           distc[it][level] = dist[node][level] + 1;
           dfs_dis(it,par,level)
        }
    }
}
int build(int node, int level){
    int total = dfs_size(node,-1);
    int centroid = find_centroid(node,-1,total);
    
    blocked[c] = true;
    
    distc[c][level] = 0;
    dfs_dis(c,-1,level);
    
    for(auto it: adj[node]){
        if(!blocked[it]){
            build(it,level + 1);
            centroid_par[it] = node;
        }
    }
    
    return centroid;
}

void update(int node){
    
    int curr = node;
    int level = 0;
    while(curr != -1){
        best[curr] = min(best[curr], distc[level][node]);
        curr = centroid_par[curr];
        level++;
    }
}
int query(int node){
    int level = 0;
    int ans = 1e18;
    int curr = node;
    while(curr!=-1){
        ans = min(ans, best[curr] + distc[level][node]);
        curr = centroid_par[curr];
        level++;
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        
    }
    return 0;
}
