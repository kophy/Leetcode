class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        queue<pair<int, int>> data;
        set<string> visited;
        data.push(pair<int, int>(0, 0));

        while (!data.empty()) {
            auto temp = data.front();
            data.pop();
            int i1 = temp.first, i2 = temp.second;
            visited.insert(pair2key(i1, i2));
            if (i1 == s1.size() && i2 == s2.size())
                return true;
            if (i1 < s1.size() && s1[i1] == s3[i1 + i2])
                if (visited.find(pair2key(i1 + 1, i2)) == visited.end()) {
                    visited.insert(pair2key(i1 + 1, i2));
                    data.push(pair<int, int>(i1 + 1, i2));
                }
            if (i2 < s2.size() && s2[i2] == s3[i1 + i2])
                if (visited.find(pair2key(i1, i2 + 1)) == visited.end()) {
                    visited.insert(pair2key(i1, i2 + 1));
                    data.push(pair<int, int>(i1, i2 + 1));
                }
        }
        return false;
    }

    string int2str(int d) {
        stringstream ss;
        ss << d;
        return ss.str();
    }

    string pair2key(int d1, int d2) {
        return int2str(d1) + " " + int2str(d2);
    }
};