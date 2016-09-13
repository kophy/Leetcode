class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> sidx(256, -1), tidx(256, -1);

        /*  three cases that dismatch
        	1. s[i] appears, t[i] doesn't
        	2. t[i] appears, s[i] doesn't       -- sidx or tidx will be -1, another won't be
        	3. both appears, but not correspond -- their last apprearance positions are different
        */
        for(int i = 0; i < s.size(); ++i) {
            if(sidx[s[i]] != tidx[t[i]])
                return false;
            sidx[s[i]] = tidx[t[i]] = i;
        }
        return true;
    }
};