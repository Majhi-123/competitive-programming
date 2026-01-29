class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj,vector<int> &vis, int &cnt){
        vis[node] = 1;
        cnt = cnt +1;

        for(auto it: adj[node]){
            if(vis[it] == 0){
                dfs(it,adj,vis,cnt);
            }
        }
    }
   
    
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<vector<int>> adj(n);


        for(int i=0;i< n/2;i++){
            int x = row[2*i];
            int y = row[2*i +1];
            //adding between 2*i and 2*i +1, if they are same they will not contribute to ans, if they are diff, then their component size -1 will contribute
            adj[x/2].push_back(y/2);
            adj[y/2].push_back(x/2);
        }
       
        int ans =0;
        vector<int> vis(n/2,0);
        for(int i=0;i<n/2;i++){
            int cnt =0;
            if(vis[i] == 0){
                dfs(i,adj,vis,cnt);
                //cout<<cnt<<" ";
                ans += cnt -1;
                cnt = 0;
            }
        }

        return ans;
    }
};
