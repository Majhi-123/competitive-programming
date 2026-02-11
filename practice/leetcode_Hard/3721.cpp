class Solution {
public:
    vector<pair<int,int>> tree;
    vector<int> lazy;
    void build(int node, int l,int r){
        if(l==r){
            tree[node].first =0;
            tree[node].second = 0;
            return;
        }

        int mid = (l+r)/2;
        build(2*node, l,mid);
        build(2*node +1, mid+1,r);

        pair<int,int> p1 = tree[2*node];
        pair<int,int> p2 = tree[2*node +1];
        
        tree[node].first = max(p1.first , p2.first);
        tree[node].second = min(p1.second, p2.second);
     }
    void update(int node, int l, int r,int left, int right,int val){
        //do lazy
        if(lazy[node]!=0){
            tree[node].first += lazy[node];
            tree[node].second += lazy[node];
            if(l!=r){
                lazy[2*node] += lazy[node];
                lazy[2*node +1] += lazy[node];
            }
            lazy[node] = 0;
        }
        
       

        //not lying 
        if(right<l || r<left){
            return;
        }
        //complete lying
        else if(left<=l && r<=right){
             tree[node].first += val;
             tree[node].second += val;
             if(l!=r){
                lazy[2*node] += val;
                lazy[2*node +1] += val;
             }
             return;
        }
        else{
            int mid = (l+r)/2;
            update(2*node,l,mid,left,right,val);
            update(2*node + 1,mid+1,r,left,right,val);
            tree[node].first = max(tree[2*node].first, tree[2*node + 1].first);
            tree[node].second = min(tree[2*node].second, tree[2*node + 1].second);
            return;
        }
    }
    int query(int node, int l,int r, int left,int right){
        if(lazy[node]!=0){
             tree[node].first += lazy[node];
             tree[node].second += lazy[node];
            if(l!=r){
                lazy[2*node] += lazy[node];
                lazy[2*node +1] += lazy[node];
            }
            lazy[node] = 0;
        }
         if(right < l || r < left){
            return 1000000;
         }

        if(l==r){
            if(tree[node].first ==0){
                return l;
            }
            return 1000000;
        }
        int x = 1000000;
        int maxi = tree[node].first;
        int mini = tree[node].second;
        if(maxi<0 || mini>0){
            return x;
        }
        
         int mid = (l+r)/2;
       
        x = query(2*node,l,mid,left,right);
        if(x >right){
             x = query(2*node +1,mid+1,r,left,right);
        }
        return x;
    }
    int longestBalanced(vector<int>& nums) {
        
        int n = nums.size();
        tree.resize(4*n + 4);
        lazy.resize(4*n + 4,0);
        //vector<int> pre(n,0);
        build(1,0,n-1);
        unordered_map<int,int> mp;
        int ans =0;
        for(int i=0;i<n;i++){

            int val = 1;
            if(nums[i]%2 == 1){
                val=-1;
            }
            int prev = -1;
            if(mp.find(nums[i])!= mp.end()){
                prev = mp[nums[i]];
            }

            update(1,0,n-1,prev+1,i,val);
            int x = query(1,0,n-1,0,i);
            if(x<n){
                ans = max(ans,i-x+1);
            }

            mp[nums[i]] = i;
        }

        return ans;
    }
};
