class Solution {
public:
    bool isOneBitCharacter(vector<int> &bits) {
        int N = bits.size();
        
        // only 1 decode way for bits[1...N-2]
        int i = 0;
        while (i < N - 1)
            i += (bits[i] == 0)? 1: 2;
        return i == N - 1;
    }
};