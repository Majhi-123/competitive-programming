//rippling
// We have to paint 
// N
// N boards of length 
// A
// =
// {
// A
// 1
// ,
// A
// 2
// ,
// …
// ,
// A
// N
// }
// A={A 
// 1
// ​
//  ,A 
// 2
// ​
//  ,…,A 
// N
// ​
//  }. There are 
// k
// k painters available, and each painter takes 
// 1
// 1 unit time to paint 
// 1
// 1 unit of the board. The goal is to find the minimum time required to complete this task under the following constraints:

// Two painters cannot share a board. A board cannot be partially painted by one painter and partially by another.

// A painter can only paint contiguous boards. For example, if a painter paints board 
// 1
// 1 and 
// 3
// 3 but not 
// 2
// 2, it is invalid.

// Input Format
// The first line contains a single integer 
// T
// T (
// 1
// ≤
// T
// ≤
// 100000
// 1≤T≤100000) - the number of test cases.
// The first line of each test case contains 
// 2
// 2 space-separated integers 
// N
// ,
// K
// N,K (
// 1
// ≤
// N
// ≤
// 100000
// 1≤N≤100000, 
// 1
// ≤
// K
// ≤
// 100000
// 1≤K≤100000) - the number of boards and the number of painters.
// The second line of each test case contains 
// N
// N space-separated integers (
// 0
// ≤
// x
// i
// ≤
// 1
// 0
// 9
// 0≤x 
// i
// ​
//  ≤10 
// 9
//  ) - the length of the boards.
// Sum of 
// N
// N across all test cases 
// ≤
// 1
// 0
// 6
// ≤10 
// 6
//  .

// Output Format
// For each test case print the minimum time required to complete the painting in a new line.

// Constraints
// 1
// ≤
// T
// ≤
// 100000
// 1≤T≤100000.
// 1
// ≤
// N
// ≤
// 100000
// 1≤N≤100000.
// 1
// ≤
// K
// ≤
// 100000
// 1≤K≤100000.
// 0
// ≤
// x
// i
// ≤
// 1
// 0
// 9
// 0≤x 
// i
// ​
//  ≤10 
// 9
//  .
// Sum of 
// N
// N across all test cases 
// ≤
// 1
// 0
// 6
// ≤10 
// 6
//  .
  #include <bits/stdc++.h>
using namespace std;

bool minimum(long long sum,int k, vector<int>&arr){

    long long curr =0;
    int seg =1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>sum){
            return false;
        }
        if(1LL*arr[i] + curr <= sum){
            curr += 1LL*arr[i];
        }
        else{
            seg++;
            curr = 1LL*arr[i];
        }
    }
    
    if(seg>k){
        return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;

        vector<int> arr(n,0);
        long long ss =0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            ss += arr[i];
        }
        //cout<<ss<<" ";
        long long lo =1;
        long long hi =ss;
        long long ans =1e15;
        while(lo<=hi){
            long long mid = (lo+hi)/2;
           // cout<<lo<<" "<<mid<<" "<<hi<<"\n";
            if(minimum(mid,k,arr)){
                  ans = min(ans,mid);
                  hi = mid-1;
             }
            else{
                lo = mid+1;
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}
// You are given 
// N
// N coins of different values 
// v
// a
// l
// val arranged in a row. You are given 
// Q
// Q queries of the following format.

// 0
// 0 
// X
// X 
// Y
// Y: Compute the sum of all the special coins in interval 
// (
// X
// ,
// N
// )
// (X,N).
// 1
// 1 
// X
// X 
// Y
// Y: Compute the multiplication of all the special coins in interval 
// (
// X
// ,
// N
// )
// (X,N).
// The 
// X
// t
// h
// X 
// th
//   position contains a special coin for each query. Here, a coin is considered a special coin if the distance of its index from the index of any other special coin is evenly divisible by 
// Y
// Y. For example, if coin at 
// i
// =
// 2
// i=2 is special and the value of 
// Y
// Y is 
// 3
// 3, then coin at 
// i
// =
// 5
// ,
// 8
// ,
// 11
// i=5,8,11 are also considered as special coins.

// Note: Since the answers can be large, print the answer modulus 
// 1
// 0
// 9
// +
// 7
// 10 
// 9
//  +7.

// Input Format
// The first line contains 
// T
// T, denoting the number of test cases.
// The first line of each test case contains 
// N
// N, denoting the number of coins.
// The second line of each test case contains 
// N
// N space-separated integers denoting the value of each coin.
// The third line of each test case contains 
// Q
// Q denoting the number of queries.
// Next, the Q lines of each test case contain three space-separated integers that have 
// 0
// 0 or 
// 1
// 1, 
// X
// X, and 
// Y
// Y.

// Output Format
// Print the answer for each query in a separate line.

// Constraints
// 1
// ≤
// T
// ≤
// 10
// 1≤T≤10
// 1
// ≤
// N
// ,
// Q
// ≤
// 5
// ×
// 1
// 0
// 4
// 1≤N,Q≤5×10 
// 4
 
// 1
// ≤
// X
// ,
// Y
// ≤
// N
// 1≤X,Y≤N
// 1
// ≤
// v
// a
// l
// ≤
// 1
// 0
// 9
// 1≤val≤10 
// 9
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> val(N + 1);
        for (int i = 1; i <= N; i++) cin >> val[i];

        int Q;
        cin >> Q;

        int K = sqrt(N) + 1;

        // Precompute for small Y
        vector<vector<long long>> preSum(K + 1, vector<long long>(N + 2, 0));
        vector<vector<long long>> preProd(K + 1, vector<long long>(N + 2, 1));

        for (int y = 1; y <= K; y++) {
            for (int x = N; x >= 1; x--) {
                if (x + y <= N) {
                    preSum[y][x] = (val[x] + preSum[y][x + y]) % MOD;
                    preProd[y][x] = (val[x] * preProd[y][x + y]) % MOD;
                } else {
                    preSum[y][x] = val[x] % MOD;
                    preProd[y][x] = val[x] % MOD;
                }
            }
        }

        while (Q--) {
            int type, X, Y;
            cin >> type >> X >> Y;
            if (Y <= K) {
                if (type == 0)
                    cout << preSum[Y][X] % MOD << "\n";
                else
                    cout << preProd[Y][X] % MOD << "\n";
            } else {
                long long ans = (type == 0 ? 0 : 1);
                for (int i = X; i <= N; i += Y) {
                    if (type == 0) ans = (ans + val[i]) % MOD;
                    else ans = (ans * val[i]) % MOD;
                }
                cout << ans % MOD << "\n";
            }
        }
    }
    return 0;
}
// There are 
// N
// N people standing in a line from left to right. Every person is facing either towards the left or right direction, which is given by the array 
// d
// i
// r
// dir, 
// d
// i
// r
// i
// =
// dir 
// i
// ​
//  = 'L', if the person is facing towards left, and 
// d
// i
// r
// i
// =
// dir 
// i
// ​
//  ='R', if he is facing right.

// Suppose if this group of 
// N
// N people have a leader, then only the people facing him will be able to listen to him. You need to choose a leader to maximise the number of people who can listen to him.

// Input Format
// The first line of the input contains one integer 
// T
// T - the number of test cases. Then 
// T
// T test cases follow.
// The first line of each test case contains an integer 
// N
// N.
// The second line of each test case contains 
// N
// N lower case alphabets 
// d
// i
// r
// 1
// ,
// d
// i
// r
// 2
// ,
// .
// .
// .
// ,
// d
// i
// r
// N
// dir 
// 1
// ​
//  ,dir 
// 2
// ​
//  ,...,dir 
// N
// ​
//  .

// Output Format
// For each test case, print on a new line the maximum number of people who can listen to their leader.

// Constraints
// 1
// ≤
// T
// ≤
// 1
// 0
// 3
// 1≤T≤10 
// 3
 
// 1
// ≤
// N
// ≤
// 1
// 0
// 5
// 1≤N≤10 
// 5
 
// It's guaranteed that the sum of 
// N
// N over all test cases 
// ≤
// 1
// 0
// 6
// ≤10 
// 6
 .
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

        vector<int> l(n,0);
        vector<int> r(n,0);

        for(int i=0;i<n;i++){
            char c;
            cin>>c;
            if(c == 'L'){
                l[i] =1;
            }
            else{
                r[i] =1;
            }

             if(i>=1){
                    l[i] += l[i-1];
                }
                if(i>=1){
                    r[i] += r[i-1];
                }
        }
        int maxi =-1;

        for(int i=0;i<n;i++){
            //cout<<l[i]<<" "<<r[i]<<"\n";
            int curr =0;
            if(i-1>=0){
               curr +=r[i-1];
            }
            if(i+1<=n-1){
                curr += l[n-1] - l[i];
            }

            maxi = max(maxi,curr);
        }

        cout<<maxi<<"\n";
    }
    return 0;
}
