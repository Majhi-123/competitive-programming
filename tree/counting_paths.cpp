#include <bits/stdc++.h>
using namespace std;
 
//void build(int )
vector<int> height(200003,0);
vector<int> sz(200003,0);
vector<int> adj[200004];
vector<vector<int>> par(200003,vector<int> (20,-1));
void dfs1(int parent, int node,int h){
    
   par[node][0] = parent;
   height[node] = h;
    for(auto it: adj[node]){
        if(parent !=it){
            dfs1(node,it,h+1);
        }
    }
}
void dfs2(int parent, int node){
    
 
    for(auto it: adj[node]){
        if(parent !=it){
            dfs2(node,it);
            sz[node] += sz[it];
        }
    }
}
//vector<vector<int>> par(200003,vector<int>(20,-1));
int lca(int x,int y){
    
    if(height[x]>height[y]){
        swap(x,y);
    }
    
    int dist = height[y] -height[x];
    
    for(int i=19;i>=0;i--){
        if(dist & (1<<i)){
            y = par[y][i];
            dist -= (1<<i);
        }
    }
    
    if(x == y){
        return x;
    }
    
    for(int i=19;i>=0;i--){
        if(par[x][i]!=par[y][i]){
            x = par[x][i];
            y = par[y][i];
        }
    }
    
    return par[x][0];
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T = 1;
   // cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        dfs1(-1,1,0);
        
        for(int i=1;i<20;i++){
            for(int k=1;k<=n;k++){
                if(par[k][i-1]!=-1){
                    par[k][i] = par[par[k][i-1]][i-1];
                }
            }
        }
        
        for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            
            int node = lca(x,y);
            
            sz[x] += 1;
            sz[y] += 1;
            sz[node] -= 1;
            if(par[node][0] !=- 1){
                 sz[par[node][0]] -= 1;   
            }
                
                
            }
        dfs2(-1,1);
        
        for(int i=1;i<=n;i++){
            cout<<sz[i]<<"\n";
        }
    }
    return 0;
}
