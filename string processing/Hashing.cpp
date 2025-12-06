long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;            //  hash[s] = (s[0] + s[1]*p + s[2]*p^2 + ....... s[n-1]*p^(n-1))%m ;    p==31 for lowercase && p==53 for uppercase
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

//finding duplicate string in array of strings -------  can be done with map also ----map<string,int> 

vector<vector<int>> group_identical_strings(vector<string> const& s) {
    int n = s.size();
    vector<pair<long long, int>> hashes(n);
    for (int i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());               //same string are together now due to hash value

    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}
"cat" → [0,2]
"dog" → [1,4]
"apple" → [3]


  //no . of different substring in a string        -----O(N^2)
  int count_unique_substrings(string const& s) {
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;                   //1, 31, 31^2, 31^3, .......

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
      //example "abc"      1 base indexed hashing
      // h[1] = a*31^0
      // h[2] = a*31^0 + b*31^1
      // h[3] = a*31^0 + b*31^1 + c*31^2

        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    int cnt = 0;
    for (int l = 1; l <= n; l++) {     //checking all the substrings of length l
        unordered_set<long long> hs;   //for pushing all the new hash values 
        for (int i = 0; i <= n - l; i++) {
            //cur_h is  s[i]*p^i + s[i+1]*p^(i+1) + ... + s[i+l-1]*p^(i+l-1)
            long long cur_h = (h[i + l] + m - h[i]) % m;
          //shifting of cur_h   s[i] * p^(n-1) +
          // s[i+1] * p^n +
          // s[i+2] * p^(n+1) +
          // ...
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}
  
