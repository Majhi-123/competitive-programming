#include <bits/stdc++.h>
using namespace std;
//#define int long long 
vector<vector<int>> tree(400006,vector<int>(26,0));
vector<char> v(100001);
void build(int node ,int l,int r){
    if(l==r){
        tree[node][v[l]-'a']++;
        return;
    }
    
    int mid = (l+r)/2;
    
    build(2*node, l,mid);
    build(2*node +1,mid+1,r);
    
    for(int i=0;i<=25;i++){
        tree[node][i] = tree[2*node][i] + tree[2*node +1][i];   
    }
}
void update(int node, int l,int r, int x, int val){
    if(x<l || x>r){
        return;
    }
    
    if(l==r){
        tree[node][v[x]-'a']--;
        tree[node][val]++;
        v[x] = val+'a';
        return ;
    }
    int mid = (l+r)/2;
    update(2*node, l ,mid,x,val);
    update(2*node+1,mid+1,r,x,val);
    for(int i=0;i<=25;i++){
        tree[node][i] = tree[2*node][i] + tree[2*node +1][i];   
    }
}
vector<int> query(int node, int l,int r, int start,int end){
    vector<int> temp(26,0);
    if(end<l || start>r){
        return temp;
    }
    
    if(start<=l && end>=r){
       // temp = tree[node];
        return tree[node];
    }
    
    int mid = (l+r)/2;
    vector<int> left  = query(2*node,l,mid,start,end);
    vector<int> right = query(2*node +1,mid+1,r,start,end);
    for(int i=0;i<=25;i++){
        temp[i] = left[i] + right[i];   
    }
    return temp;
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
	        cin>>a;
	        if(a==1){
	            char c;
	            cin>>b>>c;
	            update(1,1,n,b,c-'a');
	        }
	        else{
	            int b,c;
	            cin>>b>>c;
	            vector<int> temp = query(1,1,n,b,c);
	            int cnt=0;
	            for(int i=0;i<temp.size();i++){
	                if(temp[i]>0){
	                    cnt++;
	                }
	            }
	            cout<<cnt<<"\n";
	        }
	    }
	}
 
}
