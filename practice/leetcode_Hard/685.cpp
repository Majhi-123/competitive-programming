class Solution {
public:
    bool dfs(int node,int par,vector<int> &vis,vector<vector<int>> &adj,vector<int> &parent, int &start){
         //use dsu to check extra edge added they have different parent , if same remove that edge
        vis[node] = 2;
        parent[node] = par;

        for(auto it: adj[node]){
            int x = it;
            if(vis[x] == 0){
                if(dfs(x,node,vis,adj,parent,start)){
                    return true;
                }
            }
            if(vis[x] == 2){
                start = node;
                parent[x] = node;
                return true;
            }
        }

        vis[node] =1;
        return false;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        //if cycle exists find edge with max_val
        //find node when multiple indegree
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        vector<int> indeg(n+1,0);
        map<pair<int,int>,int> mp;
        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            mp[{edges[i][0], edges[i][1]}] = i+1;
            indeg[edges[i][1]]++;
        }
        
        vector<int> vis(n+1,0);
        vector<int> parent(n+1,-1);
        int start = -1;
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                start = -1;
                if(dfs(i,-1, vis,adj,parent,start)){
                    break;
                }
            }
        }
        //root no part in cirle
       int st =-1;
       for(int i=1;i<=n;i++){
        if(indeg[i] == 0){
            st = i;
            break;
        }
       }
       if(st!=-1 && start!=-1){
        //cout<<st<<" ";
          vector<int> ss;
        vector<int> dist(n+1,0);
       dist[st] = 1;
       queue<int> q;
       q.push(st);
       while(!q.empty()){
        int tt = q.front();
         q.pop();
        for(auto it: adj[tt]){
            if(dist[it]){
                if(ss.empty()){
                      ss.push_back(tt);
                      ss.push_back(it);
                }
            }
            else{
                dist[it] = dist[tt] +1; 
                q.push(it);
            }
        }
       }
          return ss;
       }
      
        // cout<<start ;

        //for root part of circle
        if(start!=-1){
             int tt = start;
        int ff = -1;
        ff = mp[{parent[start],start}];
        start = parent[start];
        while(start!=tt){
            if(ff < mp[{parent[start],start}]){
                ff = mp[{parent[start],start}];
            }
            start = parent[start];
        }

        ff--;
        return edges[ff];
        }
        else{
           
            //cout<<12345;
            //when edge deletion doesn't contain root
            vector<int> ans;
        for(int i=0;i<n;i++){

            if(indeg[edges[i][1]] >1 && indeg[edges[i][0]]){
                while(!ans.empty()){
                    ans.pop_back();
                }

                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
            }
        }
       
       //when edge deletion contains root
        int st =-1;
       for(int i=1;i<=n;i++){
        if(indeg[i] == 0){
            st = i;
            break;
        }
       }
       vector<int> ss;
       if(st!=-1){
        //cout<<st<<" ";
        vector<int> dist(n+1,0);
       dist[st] = 1;
       queue<int> q;
       q.push(st);
       while(!q.empty()){
        int tt = q.front();
         q.pop();
        for(auto it: adj[tt]){
            if(dist[it]){
                if(ss.empty()){
                      ss.push_back(st);
                      ss.push_back(it);
                }
            }
            else{
                dist[it] = dist[tt] +1; 
                q.push(it);
            }
        }
       }
          // ss;
       }
       if(ss.empty()){
        return ans;
       }
       if(ans.empty()){
        return ss;
       }

       if(mp[{ans[0],ans[1]}] < mp[{ss[0],ss[1]}]){
        return ss;
       }
        // if(!ans.empty()){
            return ans;
      //  }
        }
    }
};
