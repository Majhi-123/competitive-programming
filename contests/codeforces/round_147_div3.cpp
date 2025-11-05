d)
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        map<int,int> mp;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr[i] =x;
            mp[x]++;
        }
        int check =0;
        for(auto it: mp){
            //sum += it.first;
            if(it.first > it.second || it.second%it.first !=0){
                cout<<"-1"<<"\n";
                check =1;
                break;
            }
        }
                //int cnt =1;
            if(check==0){
            vector<vector<int>> adj(n+1);
            

             int cnt =1;
            for(auto it: mp){
                int i = it.first;
                int curr = it.second/it.first;
                for(int j=cnt;j<(cnt) + curr;j++){
                    for(int k=1;k<=i;k++){
                        adj[i].push_back(j);
                    }
                }
                
                cnt += curr;
            }
            // for(auto it: mp){
                
            //   cout<<it.first<<" "<<adj[it.first].size()<<"\n";;
            // }
            for(int i=0;i<n;i++){
                int x = arr[i];
                int sz = adj[x].size();
                cout<<adj[x][sz-1]<<" ";
                adj[x].pop_back();
            }
            cout<<"\n";
            }
            
       }
    return 0;
}
            
           
   
