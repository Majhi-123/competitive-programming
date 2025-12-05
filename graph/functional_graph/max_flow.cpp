//        c[i]
//node1-------->node2    flow through node1 and node2 will <= c[i]

// 

//Dinic algo
#include <bits/stdc++.h>
using namespace std;
struct edge{
    int to;
    long long int capacity;
    int rev;
};
class Dinic{
   public:
        int N;
        vector<vector<edge>> adj;
        vector<int> level;
        vector<int> ptr;
        
        Dinic(int n){
            
            N = n;
            adj.resize(n);
            level.resize(n);
            ptr.resize(n);
        }
        
        void addEdge(int u,int v, long long int cap){
            adj[u].push_back({v,cap,adj[v].size()});
            adj[v].push_back({u,0,adj[u].size()-1});
        }
        
        bool  bfs(int source,int sink){
            fill(level.begin(),level.end(),-1);
            
            queue<int> q;
            q.push(source);
            level[source] =0;
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                for(auto it: adj[node]){
                    if(level[it.to]==-1 && it.capacity>0){
                        level[it.to] = level[node] +1;
                        q.push(it.to);
                    }
                }
            }
            
            return level[sink] != -1;
        }
        
        long long dfs(int node,long long int pushed, int sink){
            
            if(pushed == 0){
                return 0;
            }
            if(node == sink){
                return pushed;
            }
            
            for(int i=ptr[node];i<adj[node].size();i++){
                
                int next = adj[node][i].to;
                long long int cap = adj[node][i].capacity;
                
                if(level[next] == level[node]+1 && cap>0){
                    long long int flow = dfs(next,min(pushed,cap),sink);
                    
                    if(flow >0){
                        
                        adj[node][i].capacity -= flow;
                        adj[next][adj[node][i].rev].capacity += flow;
                        
                        return flow;
                    }
                }
                
                ptr[node] = i+1;
            }
            
            return 0;
        }
        
        
        long long int maxflow(int source,int sink){
            
            long long flow =0;
            
            while(bfs(source,sink)){
                fill(ptr.begin(),ptr.end(),0);
                
                long long pushed = dfs(source,LLONG_MAX,sink);
                while(pushed>0){
                    
                    flow += pushed;
                    pushed = dfs(source,INT_MAX,sink);
                }
            }
            
            return flow;
        }
        
};
int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	Dinic D(n+1);
	
	for(int i=1;i<=m;i++){
	    int x,y,z;
	    cin>>x>>y>>z;
	    D.addEdge(x,y,z);
	}
	
	cout<<D.maxflow(1,n)<<"\n";
     
}
