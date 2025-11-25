
#include <bits/stdc++.h>
using namespace std;
 
//void build(int )
vector<vector<int>> par(200003,vector<int>(20,-1));
int findpar(int node, int dist){
    
    for(int i=19;i>=0;i--){
        if(dist>(1<<i)){
            node = par[node][i];
            dist -= (1<<i);
            if(node == -1){
                return -1;
            }
        }
    }
    
    return par[node][0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T = 1;
   // cin >> T;
    while (T--) {
        int n,q;
        cin>>n>>q;
        
        for(int i=2;i<=n;i++){
            int x;
            cin>>x;
            par[i][0] = x;
        }
        
        for(int i=1;i<20;i++){
            for(int k=1;k<=n;k++){
                if(par[k][i-1]!=-1){
                    par[k][i] = par[par[k][i-1]][i-1];
                }
            }
        }
        
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            cout<<findpar(x,y)<<"\n";
        }
    }
    return 0;
}
Share cod
