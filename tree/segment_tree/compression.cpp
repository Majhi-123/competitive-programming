//CSES Salary queries
#include <bits/stdc++.h>
using namespace std;
vector<int> tree(4000010,0);
vector<int> arr(200002,0);
vector<int> comp;
 
int findid(int val){
    return lower_bound(comp.begin(),comp.end(),val) - comp.begin()  +1;
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
        int n,q;
        cin>>n>>q;
        int cnt=1;
        set<int> st;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            st.insert(arr[i]);
        }
        vector<pair<int,pair<int,int>>> queries;
        for(int i=1;i<=q;i++){
            char c;
            cin>>c;
            if(c == '?'){
                int a,b;
                cin>>a>>b;
                queries.push_back({1,{a,b}});
                st.insert(a);
                st.insert(b);
            }
            else{
                int a,b;
                cin>>a>>b;
                queries.push_back({2,{a,b}});
                st.insert(b);
                
            }
        }
        //cnt--;
        //build(1,1,cnt);
        vector<int> v;
        for(auto it: st){
            v.push_back(it);
        }
        comp = v;
        int sz = comp.size();
        //add values of arr in tree
        for(int i=1;i<=n;i++){
            int id = findid(arr[i]);
            update(1,1,sz,id,+1);
        }
        for(int i=0;i<queries.size();i++){
            if(queries[i].first == 1){
                int a = queries[i].second.first;
                int b = queries[i].second.second;
                int id1 = findid(a);
                int id2 = findid(b);
                cout<<query(1,1,sz,id1,id2)<<"\n";
            }
            else{
                int a = queries[i].second.first;
                int b = queries[i].second.second;
                int id = findid(arr[a]);
                update(1,1,sz,id,-1);
                arr[a] =b;
                id = findid(b);
                update(1,1,sz,id,+1);
            }
        }
       
        
    }
    return 0;
}
