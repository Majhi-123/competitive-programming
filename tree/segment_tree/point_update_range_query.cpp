#include <bits/stdc++.h>
using namespace std;
//#define int long long 
vector<long long int> tree(1000000);
vector<int> arr(200003);
void build(int node ,int l,int r){
    if(l==r){
        tree[node] = arr[l];
        return;
    }
    
    int mid = (l+r)/2;
    
    build(2*node, l,mid);
    build(2*node +1,mid+1,r);
    tree[node] = tree[2*node] + tree[2*node +1];
}
void update(int node, int l,int r, int x, int val){
    if(x<l || x>r){
        return;
    }
    
    if(l==r){
        arr[x] = val;
        tree[node] = val;
        return ;
    }
    int mid = (l+r)/2;
    update(2*node, l ,mid,x,val);
    update(2*node+1,mid+1,r,x,val);
    tree[node] = tree[2*node] + tree[2*node +1];
}

long long query(int node, int l,int r, int start,int end){
    if(end<l || start>r){
        return 0;
    }
    
    if(start<=l && end>=r){
        return tree[node];
    }
    
    int mid = (l+r)/2;
    long long left  = query(2*node,l,mid,start,end);
    long long right = query(2*node +1,mid+1,r,start,end);
    
    return left + right;
}
int32_t main() {
	// your code goes here
 	int t=1;
// 	cin>>t;
	while(t--){
	    int n,q;
	    cin>>n>>q;
	    
	    for(int i=1;i<=n;i++){
	        cin>>arr[i];
	    }
	    build(1,1,n);
	    for(int i=1;i<=q;i++){
	        int a,b,c;
	        cin>>a>>b>>c;
	        
	        if(a==1){
	            update(1,1,n,b,c);
	        }
	        else{
	            cout<<query(1,1,n,b,c)<<"\n";
	        }
	    }
	}

}

