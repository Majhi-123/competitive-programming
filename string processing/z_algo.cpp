vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n, 0);

    int L = 0, R = 0;   // [L, R] is current Z-box (inclusive)

    for (int i = 1; i < n; i++) {
        if (i <= R) {
            z[i] = min(R - i + 1, z[i - L]);         //storing max length up to which we can proceed <=r
        }

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {          //but we can still proceed after r if matches are valid  
            z[i]++;
        }

        if (i + z[i] - 1 > R){          //finally i to i +z[i] will be we our new range  ---
            L = i;
            R = i + z[i] - 1;
        }
    }
    return z;
}
