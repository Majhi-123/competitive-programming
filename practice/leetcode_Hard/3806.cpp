You are given an integer array nums and two integers k and m.

You may perform at most k operations. In one operation, you may choose any index i and increase nums[i] by 1.

Return an integer denoting the maximum possible bitwise AND of any subset of size m after performing up to k operations optimally.

 

Example 1:

Input: nums = [3,1,2], k = 8, m = 2

Output: 6

Explanation:

We need a subset of size m = 2. Choose indices [0, 2].
Increase nums[0] = 3 to 6 using 3 operations, and increase nums[2] = 2 to 6 using 4 operations.
The total number of operations used is 7, which is not greater than k = 8.
The two chosen values become [6, 6], and their bitwise AND is 6, which is the maximum possible.
Example 2:

Input: nums = [1,2,8,4], k = 7, m = 3

Output: 4

Explanation:

We need a subset of size m = 3. Choose indices [0, 1, 3].
Increase nums[0] = 1 to 4 using 3 operations, increase nums[1] = 2 to 4 using 2 operations, and keep nums[3] = 4.
The total number of operations used is 5, which is not greater than k = 7.
The three chosen values become [4, 4, 4], and their bitwise AND is 4, which is the maximum possible.​​​​​​​
Example 3:

Input: nums = [1,1], k = 3, m = 2

Output: 2

Explanation:

We need a subset of size m = 2. Choose indices [0, 1].
Increase both values from 1 to 2 using 1 operation each.
The total number of operations used is 2, which is not greater than k = 3.
The two chosen values become [2, 2], and their bitwise AND is 2, which is the maximum possible.
 

Constraints:

1 <= n == nums.length <= 5 * 104
1 <= nums[i] <= 109
1 <= k <= 109
1 <= m <= n

class Solution {
public:
    int cost(int x,int target){
        int y = x;
        
        for(int i=30;i>=0;i--){
            if(target&(1<<i)){         //if ith bit is set
                int temp = y%(1<<(i+1));         //let 100000101000 & i is 6, changing it to 0101000
                if(temp<=(1<<i)){
                    y += (1<<i) - temp;         //i want to set 0101000 to 1000000
                }
            }
        }

        return y-x;
    }
    int maximumAND(vector<int>& nums, int k, int m) {            
        
        int ans =0;

        for(int i=30;i>=0;i--){
            int target = ans | (1<<i);       //finding can i set bit or not
            
            vector<long long int> v;
            for(int j=0;j<nums.size();j++){
                 v.push_back(cost(nums[j],target));
            }

            sort(v.begin(),v.end());
            long long int sum =0;
            for(int k=0;k<m;k++){
               sum += v[k];          //picking smallest m nos.
            }

            if(sum<=k){
                ans = target;
            }
        }

        return ans;
    }
};

//alternate soln
class Solution {
public:
    int cost(int x,int target){
        int y = x;
        int cost =0;
        
        for(int i=30;i>=0;i--){
            if(target&(1<<i) && ((x&(1<<i)) ==0)){
                int temp = y%(1<<(i+1));
                if(temp<=(1<<i)){
                    y += (1<<i) - temp;
                    cost += (1<<i) - temp;
                }
                break;
            }
        }

       for(int i=30;i>=0;i--){
            if(target&(1<<i) && ((y&(1<<i)) ==0)){
               cost += (1<<i);
            }
        }

        return cost;
    }
    int maximumAND(vector<int>& nums, int k, int m) {
        
        int ans =0;

        for(int i=30;i>=0;i--){
            int target = ans | (1<<i);
            
            vector<long long int> v;
            for(int j=0;j<nums.size();j++){
                 v.push_back(cost(nums[j],target));
            }
            
           // vector<long long int> tt = v;
            sort(v.begin(),v.end());
            long long int sum =0;
            for(int k=0;k<m;k++){
               sum += v[k];
            }

            if(sum<=k){
                // cout<<target<<"---" ;
                // for(int x=0;x<tt.size();x++){
                //     cout<<tt[x]<<" ";
                // }
                // cout<<"\n";
                ans = target;
                
            }
        }

        return ans;
    }
};
