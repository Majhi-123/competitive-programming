class Solution {
public:
    void dfs(int node,int par,vector<int> &height, vector<vector<int>> &adj){

        if(par!=-1){
            height[node] = height[par] + 1;
        }

        for(auto it: adj[node]){
            if(it != par){
                dfs(it,node,height,adj);
            }
        }
    }

    void rec(int node,vector<int> &dist, vector<vector<int>> &adj,vector<int> &vis,unordered_map<int,int> &check){
        
        vis[node] =1;
        for(auto it: adj[node]){
            if(dist[it] == 100 && vis[it]==0 && check[it]){
                dist[it] = dist[node] + 1 ;
                rec(it,dist,adj,vis,check);
            }
        }
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n+1);
        vector<int> ans(n-1,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> height(n+1,0);
        dfs(1,-1,height,adj);
        for(int i=1;i<(1<<n);i++){
            vector<int> temp;
            vector<int> dist(n+1,100);
            int root =-1;
            unordered_map<int,int> check;
            for(int j=0;j<n;j++){
                int x = i&(1<<(j));
                if(x >0){
                    if(root == -1){
                        root = j+1;
                    }
                    else if(height[j+1] > height[root]){
                        root = j+1;
                    }

                    temp.push_back(j+1);
                    check[j+1] =1;
                }
            }
           dist[root] = 0;
           vector<int> vis(n+1,0);
           vis[root] =1;
            rec(root,dist,adj,vis,check);
            bool cc = true;
            for(int j=0;j<temp.size();j++){
                if(vis[temp[j]] == 0){
                    cc = false;
                }
            }
            if(cc){
            unordered_map<int,int> mp;
            int maxi = -1;
            for(int j=0;j<temp.size();j++){
                mp[dist[temp[j]]]++;
                maxi = max(maxi, dist[temp[j]]);
            }
            bool check = true;
            for(int j=1;j<=maxi;j++){
                if(mp.find(j) == mp.end()){
                    check = false;
                }
            }
            
            if(check == true && maxi >=1){
                ans[maxi-1]++;
            }
           
            }
        }

        return ans;
    }
};
