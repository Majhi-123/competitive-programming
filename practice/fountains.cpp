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

struct SegTree {
    int n;
    vector<int> st;
    SegTree(int _n=0){init(_n);}
    void init(int _n){
        n = 1;
        while(n < _n) n <<= 1;
        st.assign(2*n, -1);
    }
    void build(const vector<int>& a){
        int m = (int)a.size();
        init(m);
        for(int i=0;i<m;i++) st[n+i] = a[i];
        for(int i=n-1;i>0;i--) st[i] = max(st[2*i], st[2*i+1]);
    }
    // query max on [l, r] inclusive (0-indexed)
    int query(int l, int r){
        if(l>r) return -1;
        l += n; r += n;
        int res = -1;
        while(l<=r){
            if(l&1) res = max(res, st[l++]);
            if(!(r&1)) res = max(res, st[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

int bestPairWithBudget(vector<pair<int,int>>& v, int budget){
    // v: (cost, beauty), sorted by cost ascending
    int n = (int)v.size();
    if(n < 2) return -1;
    vector<int> beauty(n);
    for(int i=0;i<n;i++) beauty[i] = v[i].second;
    SegTree seg;
    seg.build(beauty);

    int best = -1;
    for(int i=0;i<n;i++){
        int cost = v[i].first;
        int b = v[i].second;
        int rem = budget - cost;
        if(rem < 0) continue;
        // find last index with cost <= rem
        auto it = upper_bound(v.begin(), v.end(), make_pair(rem, INT_MAX));
        int idx = int(it - v.begin()) - 1;
        if(idx < 0) continue;
        // we need max beauty in [0..idx] excluding index i
        int cand = -1;
        if(i-1 >= 0) cand = max(cand, seg.query(0, min(idx, i-1)));
        if(i+1 <= idx) cand = max(cand, seg.query(i+1, idx));
        if(cand != -1) best = max(best, b + cand);
    }
    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin>>T)) return 0;
    while(T--){
        int n, C, D;
        cin >> n >> C >> D;
        vector<pair<int,int>> coins, diamonds; // (cost, beauty)
        for(int i=0;i<n;i++){
            int b, p; char t;
            cin >> b >> p >> t;
            if(t == 'C') coins.push_back({p, b});
            else diamonds.push_back({p, b});
        }

        sort(coins.begin(), coins.end());     // by cost then beauty
        sort(diamonds.begin(), diamonds.end());

        int bestCoinPair = bestPairWithBudget(coins, C);
        int bestDiamondPair = bestPairWithBudget(diamonds, D);

        int bestCoinSingle = -1, bestDiamondSingle = -1;
        for(auto &pr: coins) if(pr.first <= C) bestCoinSingle = max(bestCoinSingle, pr.second);
        for(auto &pr: diamonds) if(pr.first <= D) bestDiamondSingle = max(bestDiamondSingle, pr.second);

        int bestMix = -1;
        if(bestCoinSingle != -1 && bestDiamondSingle != -1) bestMix = bestCoinSingle + bestDiamondSingle;

        int ans = 0;
        if(bestCoinPair != -1) ans = max(ans, bestCoinPair);
        if(bestDiamondPair != -1) ans = max(ans, bestDiamondPair);
        if(bestMix != -1) ans = max(ans, bestMix);

        cout << ans << '\n';
    }
    return 0;
}

