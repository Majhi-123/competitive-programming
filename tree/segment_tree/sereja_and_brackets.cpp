#include <bits/stdc++.h>
using namespace std;
//#define int long long 
struct type{
    int open;
    int full;
    int close;
};
vector<type> tree(4000006);
vector<char> v(1000001);
void build(int node ,int l,int r){
    if(l==r){
        if(v[l] == ')'){
            tree[node].close = 1;
        }
        else{
            tree[node].open = 1;
        }
        return;
    }
    
    int mid = (l+r)/2;
    
    build(2*node, l,mid);
    build(2*node +1,mid+1,r);
    
    int form = min(tree[2*node].open, tree[2*node +1].close);
    tree[node].open = tree[2*node].open + tree[2*node +1].open - form;
    tree[node].full = tree[2*node].full + tree[2*node +1].full + form;
    tree[node].close = tree[2*node].close + tree[2*node +1].close - form;
}
type query(int node, int l,int r, int start,int end){
    type req;
    req.open =0;
    req.full =0;
    req.close =0;
    if(end<l || start>r){
        return req;
    }
    
    if(start<=l && end>=r){
       // temp = tree[node];
        return tree[node];
    }
    
    int mid = (l+r)/2;
    type left  = query(2*node,l,mid,start,end);
    type right = query(2*node +1,mid+1,r,start,end);
    
    int form = min(left.open, right.close);
    req.open = left.open + right.open - form;
    req.full = left.full + right.full + form;
    req.close = left.close + right.close - form;
    return req;
}
int32_t main() {
	// your code goes here
 	int t=1;
// 	cin>>t;
	while(t--){
	  string st;
	  cin>>st;
	  int q;
	  cin>>q;
	    int n = st.size();
	    for(int i=1;i<=n;i++){
	        v[i] = st[i-1];
	    }
	    build(1,1,n);
	    
	    for(int i=1;i<=q;i++){
	        
	        int a,b;
	        cin>>a>>b;
	        type res = query(1,1,n,a,b);
	        cout<<res.full*2<<"\n";
	    }
	}
 
}
