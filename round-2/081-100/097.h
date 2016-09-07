class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        /*  BFS
        	all state (x, y) form a 2D graph
        	let m = s1.size(), n = s2.size()
        	isInterleave judges whether there is a path from (0, 0) to (m, n)
        	that characters on the path itself form s3.
        */
        queue<pair<int, int>> data;
        set<string> visited;

        // 1. start point
        data.push(make_pair(0, 0));
        while (!data.empty()) {
            auto temp = data.front();
            data.pop();
            int x = temp.first, y = temp.second;

            // 2. end point
            if (x == s1.size() && y == s2.size())
                return true;

            // 3. search constraint
            if (x < s1.size() && s1[x] == s3[x + y]) {
                if (visited.find(cod2key(x + 1, y)) == visited.end()) {
                    data.push(make_pair(x + 1, y));
                    visited.insert(cod2key(x + 1, y));
                }
            }
            if (y < s2.size() && s2[y] == s3[x + y]) {
                if (visited.find(cod2key(x, y + 1)) == visited.end()) {
                    data.push(make_pair(x, y + 1));
                    visited.insert(cod2key(x, y + 1));
                }
            }
        }
        return false;
    }

private:
    string cod2key(int x, int y) {
        return to_string(x) + "@" + to_string(y);
    }
};