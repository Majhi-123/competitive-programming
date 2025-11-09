//deautsche bank
// Ishan plays Gardenscapes a lot. He wants to build two new fountains. There are 
// N
// N available fountains, for each fountain its 
// b
// e
// a
// u
// t
// y
// beauty and 
// c
// o
// s
// t
// cost are known. There are two types of money in the game: 
// c
// o
// i
// n
// s
// coins and 
// d
// i
// a
// m
// o
// n
// d
// s
// diamonds, so each fountain cost can be either in 
// c
// o
// i
// n
// s
// coins or 
// d
// i
// a
// m
// o
// n
// d
// s
// diamonds. No money changes between the types are allowed.

// Help Ishan find two fountains with maximum total beauty, such that he can buy both at the same time.

// Input Format
// The first line of input contains one integer 
// T
// T - the number of test cases. Then 
// T
// T test cases follow.
// The first line of each test case contains three space-separated integers 
// N
// N, 
// C
// C and 
// D
// D - denoting the number of fountains available, the number of coins and diamonds Ishan has respectively.
// The next 
// N
// N lines describe the fountains. Each of these lines contain two integers 
// b
// i
// b 
// i
// ​
//   and 
// p
// i
// p 
// i
// ​
//   — the beauty and the cost of the 
// i
// t
// h
// i 
// th
//   fountain, and then a letter 'C' or 'D', describing the type of money required to buy the 
// i
// t
// h
// i 
// th
//   fountain: in coins or diamonds, respectively.

// Output Format
// Print the maximum total beauty of exactly two fountains Ishan can build. If he cannot build two fountains, print 
// 0
// 0.

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
 
// 2
// ≤
// N
// ≤
// 1
// 0
// 5
// 2≤N≤10 
// 5
 
// 1
// ≤
// C
// ,
// D
// ≤
// 1
// 0
// 5
// 1≤C,D≤10 
// 5
 
// 1
// ≤
// b
// i
// ,
// p
// i
// ≤
// 1
// 0
// 5
// 1≤b 
// i
// ​
//  ,p 
// i
// ​
//  ≤10 
// 5
 
// It's guaranteed that the sum of 
// N
// N over all test cases 
// ≤
// 2
// ∗
// 1
// 0
// 5
// ≤2∗10 
// 5
  .
#include <bits/stdc++.h>
using namespace std;

bool sort1(pair<int,int> &a, pair<int,int> &b){
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, c, d;
        cin >> n >> c >> d;

        vector<pair<int,int>> c1, c2, d1, d2;

        for (int i = 0; i < n; i++) {
            int b, p;
            char t;
            cin >> b >> p >> t;
            if (t == 'C') {
                c1.push_back({b, p});  // beauty, cost
                c2.push_back({p, b});  // cost, beauty
            } else {
                d1.push_back({b, p});
                d2.push_back({p, b});
            }
        }

        sort(c1.begin(), c1.end(), sort1);
        sort(c2.begin(), c2.end(), sort1);
        sort(d1.begin(), d1.end(), sort1);
        sort(d2.begin(), d2.end(), sort1);

        // prefix max of beauty (for cost-ascending vectors)
        for (int i = 1; i < (int)c2.size(); i++)
            c2[i].second = max(c2[i].second, c2[i-1].second);
        for (int i = 1; i < (int)d2.size(); i++)
            d2[i].second = max(d2[i].second, d2[i-1].second);

        // best single coin/diamond fountain
        int maxCoinBeauty = -1, maxDiamondBeauty = -1;
        for (auto &x : c2) if (x.first <= c) maxCoinBeauty = max(maxCoinBeauty, x.second);
        for (auto &x : d2) if (x.first <= d) maxDiamondBeauty = max(maxDiamondBeauty, x.second);

        // best pair of same type
        int bestCoinPair = -1, bestDiamondPair = -1;

        for (auto &f : c1) {
            int beauty = f.first, cost = f.second;
            int rem = c - cost;
            if (rem < 0) continue;
            auto it = upper_bound(c2.begin(), c2.end(), make_pair(rem, INT_MAX));
            if (it != c2.begin()) {
                --it;
                if (it->first != cost) // avoid same fountain
                    bestCoinPair = max(bestCoinPair, beauty + it->second);
            }
        }

        for (auto &f : d1) {
            int beauty = f.first, cost = f.second;
            int rem = d - cost;
            if (rem < 0) continue;
            auto it = upper_bound(d2.begin(), d2.end(), make_pair(rem, INT_MAX));
            if (it != d2.begin()) {
                --it;
                if (it->first != cost)
                    bestDiamondPair = max(bestDiamondPair, beauty + it->second);
            }
        }

        // best mixed (coin + diamond)
        int bestMix = 0;
        if (maxCoinBeauty != -1 && maxDiamondBeauty != -1)
            bestMix = maxCoinBeauty + maxDiamondBeauty;

        cout << max({0, bestCoinPair, bestDiamondPair, bestMix}) << "\n";
    }
    return 0;
}
