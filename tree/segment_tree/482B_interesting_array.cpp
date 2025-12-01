#include <bits/stdc++.h>
using namespace std;
//#define int long long 
vector<int> arr(100003,0);
vector<int> tree(400007,0);
 
void build(int node,int l,int r){
    if(l==r){
        tree[node] = arr[l];
        return;
    }
    
    int mid = (l+r)/2;
    
    build(2*node, l,mid);
    build(2*node +1,mid+1,r);
    
    tree[node] = tree[2*node] & tree[2*node +1];
}
 
int query(int node, int l,int r, int start,int end){
    if(r<start || end<l){
        return (1<<30)-1;
    }
    
    if(start<=l && r<=end){
        return tree[node];
    }
    
    int mid = (l+r)/2;
    int left = query(2*node,l,mid,start,end);
    int right = query(2*node + 1,mid+1,r,start,end);
    return left&right;
}
int32_t main() {
	// your code goes here
 	int t=1;
// 	cin>>t;
	while(t--){
	  int n,m;
	  cin>>n>>m;
	  vector<int> l(m+1),r(m+1),q(m+1);
	  for(int i=1;i<=m;i++){
	      int a,b,c;
	      cin>>a>>b>>c;
	      l[i] = a;
	      r[i] =b;
	      q[i] =c;
	  }
	   for(int k=0;k<30;k++){
	       vector<int> sum(n+1,0);
	       for(int i=1;i<=m;i++){
	           if(q[i]&(1<<k)){
	               sum[l[i]]++;
	                if(r[i]+1<=n){
	               sum[r[i]+1]--;
	               }   
	           }
	       }
	       
	       for(int i=1;i<=n;i++){
	           if(i>1){
	             sum[i] += sum[i-1];   
	           }
	           
	           if(sum[i]){
	               arr[i] = arr[i] | (1<<k);
	           }
	       }
	    }
	    build(1,1,n);
	  bool check = true;
	  for(int i=1;i<=m;i++){
	      if(query(1,1,n,l[i],r[i])!=q[i]){
	          cout<<"NO"<<"\n";
	          check = false;
	          return 0;
	      }
	  }
	  
	  if(check){
	      cout<<"YES"<<"\n";
	      for(int i=1;i<=n;i++){
	          cout<<arr[i]<<" ";
	      }
	  }
	  
	}
 
}
