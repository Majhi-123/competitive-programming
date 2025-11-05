//atlassian
//You are given an array 
// A
// A of integers.

// You can perform the following operation any number of times to make all elements equal:

// Choose a prefix of the array (i.e., the first 
// k
// k elements for some 
// 1
// ≤
// k
// ≤
// n
// 1≤k≤n).
// Add an integer 
// x
// x (which can be positive, negative, or zero) to every element inside that prefix.
// The cost of such an operation is 
// ∣
// x
// ∣
// ∣x∣, where 
// ∣
// x
// ∣
// ∣x∣ denotes the absolute value of 
// x
// x.
// Your task is to find the minimum total cost required to make all array elements equal.

// Input Format
// The first line contains an integer 
// T
// T — the number of test cases.

// For each test case:

// The first line contains an integer 
// N
// N, representing the number of elements in the array.
// The second line contains 
// N
// N space-separated integers, each
// Output Format
// Output a single integer representing the minimum number of operations required to make all elements equal.
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
 
// N
// ≤
// 1
// 0
// 5
// N≤10 
// 5
 
// −
// 1
// 0
// 9
// ≤
// A
// i
// ≤
// 1
// 0
// 9
// −10 
// 9
//  ≤A 
// i
// ​
//  ≤10 
//9
//quick observation
// a₁ + (x₁ + x₂ + … + xₙ₋₁)
// = a₂ + (x₂ + … + xₙ₋₁)
// = a₃ + (x₃ + … + xₙ₋₁)
// = … = aₙ
// (a₂ − a₁) = x₁
// (a₃ − a₂) = x₂

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (auto &x : A) cin >> x;
        
        long long cost = 0;
        for (int i = 0; i + 1 < N; i++) {
            cost += abs(A[i+1] - A[i]);
        }
        
        cout << cost << "\n";
    }
}

// A foreign system passes a numeric input to an encryption function, but due to a bug, exactly one digit 
// d
// ∈
// {
// 0
// ,
// …
// ,
// 9
// }
// d∈{0,…,9} is consistently mistranslated into one digit 
// e
// ∈
// {
// 0
// ,
// …
// ,
// 9
// }
// e∈{0,…,9} (the same pair 
// (
// d
// →
// e
// )
// (d→e) for all occurrences).

// All other digits remain unchanged. The transformation must not produce a number with leading zeros. The mistranslated digit might not appear in the number (yielding no change).

// Given the input number 
// N
// N (as a string of digits), determine the maximum value 
// N
// max
// ⁡
// N 
// max
// ​
//   and the minimum value 
// N
// min
// ⁡
// N 
// min
// ​
//   achievable under one such global digit mapping, and output the difference

// N
// max
// ⁡
// −
// N
// min
// ⁡
// .
// N 
// max
// ​
//  −N 
// min
// ​
//  .
// Input Format
// The first line has an integer 
// N
// N representing the number to be encoded.
// Output Format
// Output a single integer representing the difference between the Maximum and Minimum valid encodings.
// Constraints
// 1
// ≤
// N
// ≤
// 1
// 0
// 9
// 1≤N≤10 
// 9
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        int cp = n;
        //int cnt =0;
        string st ="";
        while(cp>0){
            st += '0' + cp%10;
            cp = cp/10;
        }
        reverse(st.begin(),st.end());
        //cout<<st<<" ";
        string maxi="";
        int id=-1;
        for(int i=0;i<st.size();i++){
             if(st[i]-'0'!=9){
                  id =st[i]-'0';
                  break;
             }
        }
        for(int i=0;i<st.size();i++){
             if(id>=0 && st[i]-'0'==id){
                maxi += '0' +9; 
             }
             else{
                maxi += st[i];
             }
        }
        id =-1;
        bool check = false;
        if(st[0]-'0' >1){
            id = st[0] -'0';
            check = true;
        }

        if(id==-1){
            for(int i=1;i<st.size();i++){
                if(st[i]-'0'!=0 && st[i]-'0'!= 1){
                    id = st[i]-'0';
                    break;
                }
            }
        }

        string mini = "";
        for(int i=0;i<st.size();i++){
             if(id>=0 && st[i]-'0'==id){
                if(check == true){
                    mini += '0' +1; 
                }
                else{
                    mini += '0' +0; 
                }
             }
             else{
                mini += st[i];
             }
        }

        int maxx = stoi(maxi);
        int minn = stoi(mini);
        //cout<<maxx<<" "<<minn<<"\n";
        cout<<maxx-minn<<"\n";
        
    }
    return 0;
}
