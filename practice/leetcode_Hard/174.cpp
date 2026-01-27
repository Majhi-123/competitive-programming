class Solution {
public:
    //check if i can reach with 0 as initial value
    bool valid(int i,int j, int m,int n){
        return i<m && i>=0 && j<n && j>=0;
    }
    int rec(int i,int j,vector<vector<int>> &dp, vector<vector<int>> &dungeon){
        if(i==dungeon.size()-1 && j==dungeon[0].size()-1){
            if(dungeon[i][j]>0){
                return 0;
            }
            return dungeon[i][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans1 = INT_MIN,ans2 = INT_MIN;
            if(valid(i+1,j,dungeon.size(),dungeon[0].size())){
                ans1 = rec(i+1,j,dp,dungeon);
            }
             if(valid(i,j+1,dungeon.size(),dungeon[0].size())){
                ans2 = rec(i,j+1,dp,dungeon);
            }

            dp[i][j] = dungeon[i][j] + max(ans1,ans2);
            if(dp[i][j] >0){
                return dp[i][j] =0;
            }

            return dp[i][j];
        }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size(),vector<int>(dungeon[0].size(),-1));

        return abs(rec(0,0,dp,dungeon)) +1;
    }
};
