struct Manacher {
    string s;
    vector<int> rad;
    int n;
    void build(string t)
    {
        s = t;
        n = 2*s.size();
        rad.clear(); rad.resize(n, 0);
        for (int i = 0, j = 0, k; i < n; i += k, j = max(j - k, 0))
        {
            for (; i >= j && i + j + 1 < n && s[(i - j) / 2] == s[(i + j + 1) / 2]; ++j);

            rad[i] = j;

            for (k = 1; i >= k && rad[i] >= k && rad[i - k] != rad[i] - k; ++k)
                rad[i + k] = min(rad[i - k], rad[i] - k);
        }
    }
    bool is_palindrome(int l, int r)
    {
        return l >= 0 && r < s.size() &&  rad[l+r] >= r - l + 1;
    }
    // Longest odd palindrome with center at ith position
    int longestOdd(int i){ return rad[i*2]; }
    // Longest even palindrome with center between ith and (i+1)th position
    int longestEven(int i){ return rad[2*i+1]; }
};
Manacher man;
