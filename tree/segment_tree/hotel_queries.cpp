#include <bits/stdc++.h>
using namespace std;
//#define int long long 
vector<int> arr(200003,0);
vector<int> tree(800007,0);
 
void build(int node,int l,int r){
    if(l==r){
        tree[node] = arr[l];
        return;
    }
    
    int mid = (l+r)/2;
    
    build(2*node, l,mid);
    build(2*node +1,mid+1,r);
    
    tree[node] = max(tree[2*node], tree[2*node +1]);
}
void update(int node,int l,int r,int idx,int x){
    if(idx<l || r<idx){
        return;
    }
    
    if(l == r){
        tree[node] -= x;
        arr[l] -= x;
        return;
    }
    
    int mid = (l+r)/2;
    update(2*node,l,mid,idx,x);
    update(2*node +1,mid+1,r,idx,x);
    
    tree[node] = max(tree[2*node] , tree[2*node +1]);
}
int query(int node, int l,int r, int val){
    if(tree[node]<val){
        return 0;
    }
    
    
    if(l==r){
        if(tree[node]>=val){
            return l;
        }
        return 0;
    }
    
    int mid = (l+r)/2;
    int ans = 0;
    if(tree[2*node]>=val){
        ans = query(2*node,l,mid,val);
    }
    else if(tree[2*node +1]>=val){
        ans = query(2*node +1, mid+1,r,val);
    } 
    return ans;
}
int32_t main() {
	// your code goes here
 	int t=1;
// 	cin>>t;
	while(t--){
	  int n,m;
	  cin>>n>>m;
	  
	  for(int i=1;i<=n;i++){
	      cin>>arr[i];
	  }
	  
	  build(1,1,n);
	  for(int i=1;i<=m;i++){
	      int x;
	      cin>>x;
	      int idx = query(1,1,n,x);
	      cout<<idx<<" ";
	      if(idx){
	         update(1,1,n,idx,x);   
	      }
	  }
	  
	}
 
}
