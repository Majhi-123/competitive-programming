Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.

 

Example 1:


Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation: 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.
Example 2:

Input: grid = [[7]]
Output: 7


  //can be optimized by picking  min from (grid[row][0] to grid[row]col-1] and grid[row][col+1] to grid[row][grid[0].size()-1]) using precomputation
  class Solution {
public:
    int rec(int row,int prev,vector<vector<int>> &dp,vector<vector<int>> &grid){
        if(row == grid.size()){
            return 0;
        }
        if(dp[row][prev]!=-10000000){
            return dp[row][prev];
        }
        
        int ans = 100000000;
        for(int i=0;i<grid.size();i++){
            if(i!= prev){
               ans = min(ans,grid[row][i] + rec(row + 1,i,dp,grid));
            }   
        }

        return dp[row][prev] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size()+5, -10000000));

        return rec(0,grid[0].size()+1,dp,grid);
    }
};
