//capital one
// You are given a large number 
// N
// N represented as a string, an integer 
// K
// K, and 
// Q
// Q queries. Your task is to determine, for each query, whether there exists a subsequence of 
// N
// N such that the resulting number leaves a remainder of 
// X
// X when divided by 
// K
// K.

// A subsequence is defined as a sequence derived by deleting zero or more elements from the original string without changing the order of the remaining elements.

// Input Format
// The first line contains three space-separated integers 
// N
// N, 
// K
// K, and 
// Q
// Q

// The next 
// Q
// Q lines contain the value 
// X
// X

// Output Format
// For each query, print "YES" if there exists a subsequence whose value leaves the remainder 
// X
// X when divided by 
// K
// K. Otherwise, print "NO".

// Constraints
// 1
// ≤
// len
// (
// N
// )
// ≤
// 1
// 0
// 5
// 1≤len(N)≤10 
// 5
 

// 1
// ≤
// Q
// ≤
// 1
// 0
// 6
// 1≤Q≤10 
// 6
 

// 2
// ≤
// K
// ≤
// 100
// 2≤K≤100

// 0
// ≤
// X
// ≤
// K
// −
// 1
// 0≤X≤K−1
// Write your code here
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    while (T--) {
         string st;
         cin>>st;
         int k,q;
         cin>>k>>q;

        set<int> s;
      

        for(int i=0;i<st.size();i++){
            int x  = st[i]-'0';
            
            set<int> bb;
            for(auto it: s){
                int temp = it;
                bb.insert(((temp)*10 + x)%k);
                //cout<<((temp)*10 + x)%k<<"////";
            }
            s.insert(x%k);
            for(auto it: bb){
                s.insert(it);
            }
           // cout<<(x%k)<<" ";
        }
        
      
        for(int i=0;i<q;i++){
            int a;
            cin>>a;

            if(s.find(a) != s.end()){
                cout<<"YES"<<"\n";
            }
            else{
                cout<<"NO"<<"\n";
            }
        }
    }
    return 0;
}
// In a neighborhood, there are 
// N
// N empty houses numbered from 
// 1
// 1 to 
// N
// N arranged in a line. Each day, starting from day 
// 1
// 1, one house will be occupied by residents. The sequence of occupied houses is given as a permutation of length 
// N
// N. On the 
// i
// t
// h
// i 
// th
//   day, the house with the number given by the 
// i
// t
// h
// i 
// th
//   element of the permutation will be occupied.

// The neighborhood will be considered happy if there is at least one set of consecutive occupied houses of length 
// K
// K or greater. On which day will the neighborhood become happy?

// Input Format
// The input consists of multiple test cases, and the first line contains a single integer 
// T
// T, the number of test cases.
// For each test case:
// The first line contains the integer 
// N
// N, representing the number of houses.
// The second line contains the integer 
// K
// K, representing the number of consecutive houses needed.
// The third line contains a sequence of 
// N
// N integers, each indicating the house that will be occupied on each day.

// Output Format
// For each test case, print a single integer representing the day on which the neighborhood becomes happy.

// Constraints
// 1
// ≤
// T
// ≤
// 50
// 1≤T≤50

// 1
// ≤
// N
// ≤
// 1
// 0
// 5
// 1≤N≤10 
// 5
 

// 1
// ≤
// K
// ≤
// N
// 1≤K≤N
#include <bits/stdc++.h>
using namespace std;
int par[100002];
int sz[100002];
void make(int temp){
    par[temp] =temp;
    sz[temp] = 1;
}

int findpar(int temp){
    if(par[temp]!=temp){
        
        return par[temp] = findpar(par[temp]);
    }

    return par[temp] ;
}

void add(int x,int y){
    x = findpar(x);
    y = findpar(y);

    if(x==y){
        return;
    }

    if(sz[x]>sz[y]){
        swap(x,y);
    }

    par[x] = y;
    sz[y] += sz[x];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        memset(par,-1,sizeof(par));
        memset(sz,0,sizeof(sz));
        
        int n,k;
        cin>>n>>k;
        
        vector<int> arr(n);
        vector<bool> occ(n+2,0);
        
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr[i] =x;
        }
        for(int i=0;i<n;i++){
            occ[arr[i]] = true;
            make(arr[i]);
            if(occ[arr[i]+1]){
                add(arr[i],arr[i]+1);
            }
            if(occ[arr[i]-1]){
                add(arr[i],arr[i]-1);
            }

            int x = findpar(arr[i]);
            if(sz[x]>=k){
                cout<<i+1<<"\n";
                break;
            }
         }

    }
    return 0;
}
// Given a number 
// N
// N, you are required to convert it into a binary palindromic number. A binary palindromic number is a number whose binary representation is a palindrome.

// You can perform the following two operations on the provided number:

// Increase the value of the number by 
// 1
// 1.
// Decrease the value of the number by 
// 1
// 1.
// You are required to calculate the minimum number of operations required to convert the given number into a binary palindromic number.

// Note: The given number must be represented in the form of the minimum number of bits (ignoring the leading zeros in its binary representation).

// Input Format
// The first line contains 
// T
// T denoting the total number of test cases.
// The first line of each test case contains an integer 
// N
// N denoting the number that must be converted into a binary palindromic number.

// Output Format
// For each test case in a new line, print the minimum number of operations that are required to convert a number into a binary palindromic number.

// Constraints
// 1
// ≤
// T
// ≤
// 1
// 0
// 5
// 1≤T≤10 
// 5
 
// 1
// ≤
// N
// ≤
// 2
// ×
// 1
// 0
// 9
// 1≤N≤2×10 
// 9
// Write your code here
#include <bits/stdc++.h>
using namespace std;

vector<long long> pals;

void generate_palindromes() {
    const long long LIMIT = 2e9;
    for (int len = 1; len <= 31; len++) {
        int half = (len + 1) / 2;
        int start = 1 << (half - 1);   // avoid leading zeros
        int end = 1 << half;

        for (int x = start; x < end; x++) {
            long long res = x;
            int temp = x;
            if (len % 2) temp >>= 1; // skip middle bit for odd lengths
            while (temp > 0) {
                res = (res << 1) | (temp & 1);
                temp >>= 1;
            }
            if (res <= LIMIT)
                pals.push_back(res);
        }
    }
    sort(pals.begin(), pals.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    generate_palindromes(); // precompute once

    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        auto it = lower_bound(pals.begin(), pals.end(), n);

        long long ans = LLONG_MAX;
        if (it != pals.end()) ans = min(ans, abs(*it - n));
        if (it != pals.begin()) {
            --it;
            ans = min(ans, abs(*it - n));
        }
        cout << ans << "\n";
    }
    return 0;
}
