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
