class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        // preprocess original string
        int N = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '-')
                continue;
            else
                S[N++] = toupper(S[i]);
        }
        
        string T(N + (N - 1) / K, ' ');
        int ps = 0, pt = 0;
        
        // first part
        if ((N % K) != 0) {
            for (int i = 0; i < N % K; ++i)
                T[pt++] = S[ps++];
        }
        // rest parts
        while (ps < N) {
            if (pt > 0)
                T[pt++] = '-';
            for (int i = 0; i < K; ++i)
                T[pt++] = S[ps++];
        }
        return T;
    }
};