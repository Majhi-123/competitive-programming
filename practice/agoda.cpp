
// Given an array 
// a
// r
// r
// arr containing 
// N
// N non-negative integers and an element 
// K
// K, In one operation, 
// K
// K can be added to or subtracted from any element of the array. 
// M
// E
// X
// MEX of an array is defined as the smallest non-negative integer which is not present in the array.

// Your task is to find the maximum possible 
// M
// E
// X
// MEX of the array that can be achieved by doing the above operation any number of times.

// Write your code here
// Write your code here
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n,0);
        vector<int> mp(k,0);

        for(int i=0;i<n;i++){
            cin>>v[i];
            mp[v[i]%k]++;
        }
        int i=0;
        int cnt=0;
        while(mp[i]!=0){
           mp[i]--;
           cnt++;
           i = (i+1)%k;
        }

        cout<<cnt<<"\n";
    }
    return 0;
}
