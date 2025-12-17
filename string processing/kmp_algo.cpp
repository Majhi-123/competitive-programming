//finding longest proper prefix which which also a suffix.
//O(n) algorithm cause j is increaing along side i, max decrease can be also n
vector<int> lps(n, 0);

int j = 0; // length of previous longest prefix-suffix

for (int i = 1; i < n; i++) {
    while (j > 0 && s[i] != s[j]) {
        j = lps[j - 1];   // fallback
    }

    if (s[i] == s[j]) {
        j++;
        lps[i] = j;
    }
}
//how this will help
//new_str = pattern + '$' + text ----> find its lps, the points at which lps[i] == pattern.size(), these are the result 
