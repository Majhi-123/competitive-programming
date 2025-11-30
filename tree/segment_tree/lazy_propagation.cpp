#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> tree(1000000,0);
vector<int> arr(200004,0);
vector<int> lazy(900004,0);
void build(int node,int l,int r){
    if(l==r){
        tree[node] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*node,l,mid);
    build(2*node+1, mid+1,r);
    
    tree[node] = tree[2*node] + tree[2*node +1];
    
}
void update(int node, int l,int r, int start,int end, int val){
    tree[node] += (r-l +1)*lazy[node];
        if(l!=r){
            lazy[2*node] +=lazy[node];
            lazy[2*node +1] += lazy[node];
      }
        lazy[node] =0;
    if(r<start || end<l){
        return;
    }
    
    if(start<=l && r<=end){
        tree[node] += (r-l +1)*val;
        if(l!=r){
            lazy[2*node] +=val;
            lazy[2*node +1] += val;
        }
        return;
    }
    
    int mid = (l+r)/2;
    update(2*node,l,mid,start,end,val);
    update(2*node +1,mid+1,r,start,end,val);
    tree[node] = tree[2*node] + tree[2*node +1];
}
 
int query(int node,int l,int r,int start,int end){
    tree[node] += (r-l +1)*lazy[node];
        if(l!=r){
            lazy[2*node] +=lazy[node];
            lazy[2*node +1] += lazy[node];
      }
        lazy[node] =0;
    if(r<start || end<l){
        return 0;
    }
    
    if(start<=l && r<=end){
        return tree[node];
    }
    
    
    int mid = (l+r)/2;
    int left = query(2*node,l,mid,start,end);
    int right = query(2*node+1,mid+1,r,start,end);
    
    return left + right;
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        build(1,1,n);
        for(int i=1;i<=q;i++){
            int a;
            cin>>a;
            if(a==1){
                int b,c,d;
                cin>>b>>c>>d;
                update(1,1,n,b,c,d);
            }
            else{
                int b;
                cin>>b;
                cout<<query(1,1,n,b,b)<<"\n";
            }
        }
    }
    return 0;
}
