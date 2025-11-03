
//uber
// Gerald of Rivia also known as The Witcher, on his journey to find Ciri, faced a dangerous labyrinth.

// He's in a tunnel that contains 
// N
// N different rooms. Each room contains 
// A
// i
// A 
// i
// ​
//   monsters inside it. He starts from room 
// 1
// 1. Every time he stays near a room 
// X
// X, he may go in and clear it from monsters, or just leave the room locked and move to the room 
// X
// +
// 1
// X+1. However, if he clears a room with 
// K
// K monsters and the next room he clears consists of 
// L
// L monsters, then the greatest common divisor of 
// K
// K and 
// L
// L must be greater than 
// 1
// 1, otherwise, he will die ( awful curse! ).

// Formally, let us say that the order of rooms he visited is 
// i
// 1
// ,
// i
// 2
// ,
// ,
// .
// .
// .
// ,
// i
// t
// i 
// 1
// ​
//  ,i 
// 2
// ​
//  ,,...,i 
// t
// ​
//  . Then 
// g
// c
// d
// (
// A
// i
// j
// ,
// A
// i
// j
// +
// 1
// )
// >
// 1
// gcd(Ai 
// j
// ​
//  ,Ai 
// j+1
// ​
//  )>1 for all 
// j
// <
// t
// j<t. Help him cross all the rooms by clearing the maximum number of rooms.

// Input Format
// The first line of input contains an integer 
// T
// T denoting the number of test cases.

// The first line of each test case contains one integer 
// N
// N denoting the number of elements in the sequence.

// The second line of each test case contains 
// N
// N integers where 
// i
// t
// h
// i 
// th
//   integer is a number of monsters in a room 
// A
// i
// A 
// i
// ​
//  .

// Output Format
// For each test case, output the maximum number of rooms he could clear. (Gerald should survive.)

// Constraints
// 1
// ≤
// T
// ≤
// 100
// 1≤T≤100
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
// A
// i
// ≤
// 1
// 0
// 7
// 1≤A 
// i
// ​
//  ≤10 
// 7
// Write your code here
#include <bits/stdc++.h>
using namespace std;

const int MAXA = 1e7 + 1;
vector<int> spf(MAXA, 0);  // smallest prime factor

void sieve() {
    for (int i = 2; i < MAXA; i++) {
        if (spf[i] == 0) {
            for (int j = i; j < MAXA; j += i)
                if (spf[j] == 0)
                    spf[j] = i;
        }
    }
}

vector<int> get_primes(int x) {
    vector<int> res;
    while (x > 1) {
        int p = spf[x];
        res.push_back(p);
        while (x % p == 0)
            x /= p;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        unordered_map<int, int> dp;  // prime -> longest chain using it
        int ans = 1;

        for (int x : A) {
            vector<int> primes = get_primes(x);
            int best = 0;
            for (int p : primes)
                best = max(best, dp[p]);
            best++; // include this room
            for (int p : primes)
                dp[p] = max(dp[p], best);
            ans = max(ans, best);
        }

        cout << ans << "\n";
    }
    return 0;
}
