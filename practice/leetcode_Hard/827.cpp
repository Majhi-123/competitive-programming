class Solution {
public:
     map<pair<int,int>, pair<int,int>> par;
     map<pair<int,int>, int> sz;
    
    void merge(pair<int,int> p1, pair<int,int> p2){

        if(findpar(p1) == findpar(p2)){
            return;
        }

        pair<int,int> x1 = findpar(p1);
        pair<int,int> x2 = findpar(p2);

        if(sz[x1] > sz[x2]){
            swap(x1,x2);
        }

        par[x1] = x2;
        sz[x2] += sz[x1];
    }
    pair<int,int> findpar(pair<int,int> p1){

        if(par[p1] == p1){
            return p1;
        }

        return par[p1] = findpar(par[p1]);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    par[{i,j}] = {i,j};
                    sz[{i,j}] = 1;
                }
            }
        }

         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    if(i+1 < n && grid[i+1][j]==1){
                        merge({i,j},{i+1,j});
                    }
                    if(j+1 <n && grid[i][j+1]==1){
                        merge({i,j},{i,j+1});
                    }
                    if(i-1 >=0  && grid[i-1][j]==1){
                        merge({i,j},{i-1,j});
                    }
                    if(j-1 >=0 && grid[i][j-1] ==1){
                        merge({i,j},{i,j-1});
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] ==0){
                    set<pair<int,int>> st;
                    if(i+1 < n && grid[i+1][j]==1){
                        st.insert(findpar({i+1,j}));
                    }
                    if(j+1 <n && grid[i][j+1]==1){
                        st.insert(findpar({i,j+1}));
                    }
                    if(i-1 >=0  && grid[i-1][j]==1){
                        st.insert(findpar({i-1,j}));
                    }
                    if(j-1 >=0 && grid[i][j-1] ==1){
                        st.insert(findpar({i,j-1}));
                    }
                    int curr =0;
                    for(auto it: st){
                        curr += sz[it];
                    }

                    ans = max(ans,curr + 1);
                }
                else{
                    ans = max(ans, sz[findpar({i,j})]);
                }
            }
        }

        return ans;
    }
};
