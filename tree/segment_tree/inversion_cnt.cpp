#include <bits/stdc++.h>
using namespace std;
vector<int> tree(400008,0);
vector<int> arr(100002,0);
void build(int node,int l,int r){
    if(l==r){
        tree[node] = 0;
        return;
    }
    int mid = (l+r)/2;
    build(2*node, l,mid);
    build(2*node +1,mid+1,r);
    tree[node] = tree[2*node] + tree[2*node +1];
}
 
void update(int node, int l,int r ,int idx,int val){
    if(idx < l || r<idx){
        return;
    }
    
    if(l==r){
        tree[node] += val;
        return;
    }
    
    int mid = (l+r)/2;
    update(2*node, l,mid,idx,val);
    update(2*node+1,mid+1,r,idx,val);
    tree[node] = tree[2*node] + tree[2*node +1];
}
int query(int node,int l,int r,int start,int end){
    if(r<start || end<l){
        return 0;
    }
    
    if(start<=l && r<=end){
        return tree[node];
    }
    int mid = (l+r)/2;
    int left = query(2*node, l,mid,start,end);
    int right = query(2*node+1,mid+1,r,start,end);
    return left + right;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
       build(1,1,n);
        for(int i=1;i<=n;i++){
            cout<<query(1,1,n,arr[i],n)<<" ";
            update(1,1,n,arr[i],1);
        }
        
    }
    return 0;
}
