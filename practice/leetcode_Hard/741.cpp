class Solution {
public:
    bool valid(int x,int y, vector<vector<int>> &grid){
        int n = grid.size();
        return x<n && y<n && (grid[x][y]== 0 || grid[x][y] ==1) ;
    }
    int rec(int idx1,int idx2, int idx3,int idx4, vector<vector<int>> &grid, vector<vector<vector<vector<int>>>> &dp){
        int n = grid.size();
        if(idx1 == n-1 && idx2 ==n-1 && idx3 == n-1 && idx4 ==n-1){
            if(grid[idx1][idx2] == 1){
                return 1;
            }
            return 0;
        }

        if(dp[idx1][idx2][idx3][idx4]!=-1){
            return dp[idx1][idx2][idx3][idx4];
        }
        int score = 0;
        
        if(!valid(idx1+1,idx2,grid) && !valid(idx3+1,idx4,grid) && !valid(idx1,idx2+1,grid) && !valid(idx3,idx4+1,grid)){
            return dp[idx1][idx2][idx3][idx4] = -100000000;
        }
        
        //cout<<idx1<<" "<<idx2<<" "<<idx3<<" "<<idx4<<"\n";
        if(idx1 == idx3 && idx2 == idx4){
            score += grid[idx1][idx2];
        }
        else{
            score += grid[idx1][idx2];
            score += grid[idx3][idx4];
        }
        int s1 =-100000000;
        if(valid(idx1+1,idx2,grid) && valid(idx3+1,idx4,grid)){
            int y = rec(idx1+1,idx2,idx3+1,idx4,grid,dp);
            //cout<<y<<" ";
            s1 = max(s1, y);
        }
        if(valid(idx1+1,idx2,grid) && valid(idx3,idx4+1,grid)){
            int y = rec(idx1+1,idx2,idx3,idx4+1,grid,dp);
             //cout<<y<<" ";
            s1 = max(s1, y);
        }
        if(valid(idx1,idx2+1,grid) && valid(idx3+1,idx4,grid)){
            int y = rec(idx1,idx2+1,idx3+1,idx4,grid,dp);
             //cout<<y<<" ";
            s1 = max(s1, y);
        }
        if(valid(idx1,idx2+1,grid) && valid(idx3,idx4+1,grid)){
            int y = rec(idx1,idx2+1,idx3,idx4+1,grid,dp);
             //cout<<y<<" ";
            s1 = max(s1, y);
        }


        //cout<<s1<<"\n";
        if(s1 < 0){
            return dp[idx1][idx2][idx3][idx4] = -100000000;
        }
        return dp[idx1][idx2][idx3][idx4] = score + s1;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>> (n,vector<vector<int>> (n,vector<int>(n,-1))));
        
       int x =rec(0,0,0,0,grid,dp);
       if(x>0){
            return x;
        }
       return 0;
    }
};
