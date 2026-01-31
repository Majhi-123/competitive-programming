class Solution {
public:
    const long long int mod = 1000000007;
    long long int bin_expo(long long int a,long long int b){
    
    long long ans = 1;
    long long prod = a;
    
    while(b>=1){
        if(b%2 == 1){
            ans = (ans*prod)%mod;
        }
        
        prod = (prod*prod)%mod;
        b = b/2;
    }
    
    return ans;
}

long long findinverse(long long int a){
    return bin_expo(a,mod-2);
}
    void dfs(int node, int par,vector<vector<int>> &adj, vector<long long int> &sz,vector<long long int> &dp,vector<long long int> &fact){

        for(auto it: adj[node]){

            dfs(it,node,adj,sz,dp,fact);
            sz[node] += sz[it];
        }
        if(adj[node].size() >=1){
        long long ans = fact[sz[node] -1];
        for(auto it: adj[node]){
             ans = (((ans * dp[it])%mod)*findinverse(fact[sz[it]]))%mod;
        }

        dp[node] = ans;
        }

    }
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
     vector<long long int> fact(n+1,1);
     for(int i=2;i<=n;i++){
         fact[i] = (fact[i-1]*i)%mod;
      }
        //int n = prevRoom.size();
        vector<vector<int>> adj(n);

        for(int i=1;i<prevRoom.size();i++){
            adj[prevRoom[i]].push_back(i);
        }

        vector<long long int> sz(n,1);
        vector<long long int> dp(n,1);
        dfs(0,-1,adj,sz,dp,fact);

        return dp[0]%mod;
    }
};
