#include <bits/stdc++.h>
using namespace std;
vector<int> fenwick(200003,0);
void build(vector<int> &arr){
    int n = arr.size()-1;
    vector<int> pre(n+1,0);
    pre[1] = arr[1];
    for(int i=2;i<=n;i++){
        pre[i] = pre[i-1] + arr[i];
    }
    
    for(int i=1;i<=n;i++){
        int idx = i - (i&(-i));
        fenwick[i] = pre[i] - pre[idx];
    }
}

int query(int l){
    int sum =0;
    while(l>0){
        sum += fenwick[l];
        l -= (l&(-l));
    }
    
    return sum;
}
void update(int l,int val,int n){
    
    while(l<=n){
        fenwick[l] += val;
        l += (l&(-l));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        
    }
    return 0;
}
