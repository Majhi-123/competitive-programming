// You are given an integer N (1 ≤ N ≤ 5 × 10⁵).

// A number is considered valid if:

// It is a prime number, and

// It can be expressed as the sum of one or more consecutive prime numbers.

// Your task is to:

// Return the largest prime number ≤ N that can be expressed as the sum of consecutive prime numbers (the sequence can start at any prime).

// If no such number exists, return 0.
// N = 50
// 5  = 2 + 3
// 17 = 2 + 3 + 5 + 7
// 23 = 5 + 7 + 11
// 41 = 2 + 3 + 5 + 7 + 11 + 13

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    // Step 1: Sieve for primes up to n
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    for(long long i = 2; i * i <= n; i++){
        if(isPrime[i]){
          for(long long j = i*i; j <= n; j += i){
                isPrime[j] = false;
            }
        }
    }

    // Collect all primes
    vector<int> primes;
    for(int i = 2; i <= n; i++){
        if(isPrime[i]) primes.push_back(i);
    }

    // Build prefix sum
    int m = primes.size();
    vector<long long> prefix(m+1,0);
    for(int i = 0; i < m; i++){
        prefix[i+1] = prefix[i] + primes[i];
    }

    long long best = 0;

    // Determine max prefix length that stays under n
    int maxLen = 0;
    while(maxLen < m && prefix[maxLen+1] <= n){
        maxLen++;
    }

    // Try windows from largest length to smallest
    for(int len = maxLen; len >= 1; len--){
        bool found = false;

        for(int start = 0; start + len <= m; start++){
            long long sum = prefix[start + len] - prefix[start];
            if(sum > n) break;         // further sums will only be larger
            if(isPrime[sum]){
                best = sum;
                found = true;
                break;
            }
        }

        if(found) break;  // no need to check smaller lengths
    }

    cout << best << "\n";
    return 0;
}
