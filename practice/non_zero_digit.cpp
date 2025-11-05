//paytm
//You will be given an array A of N non-negative integers. Your task is to find the rightmost non-zero digit in the product of array elements if exist.

// Input Format
// First-line contains N, the size of the array A.
// The second line contains N non-negative integers. 

// Output Format
// Print the rightmost non-zero digit in the product of array elements, if there is no rightmost non-zero digit, then print -1.

// Constraints
// 1 ≤ N ≤ 105
// 0 ≤ A[i] ≤ 105 

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // If any element is zero, product is zero
    for (auto x : a)
        if (x == 0) {
            cout << -1;
            return 0;
        }

    long long count2 = 0, count5 = 0;
    long long mod = 1000000000;  // large enough to avoid overflow
    long long prod = 1;

    for (auto x : a) {
        // count factors of 2
        while (x % 2 == 0) {
            x /= 2;
            count2++;
        }
        // count factors of 5
        while (x % 5 == 0) {
            x /= 5;
            count5++;
        }
        prod = (prod * (x % mod)) % mod;
    }

    // Balance out 2s and 5s
    long long diff = count2 - count5;
    if (diff > 0) {
        for (int i = 0; i < diff; i++) prod = (prod * 2) % mod;
    } else {
        for (int i = 0; i < -diff; i++) prod = (prod * 5) % mod;
    }

    // Remove trailing zeros and find rightmost non-zero digit
    while (prod % 10 == 0) prod /= 10;
    cout << prod % 10;
}
