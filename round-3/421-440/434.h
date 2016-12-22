class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        stringstream ss(s);
        string temp;
        while (ss >> temp)
            ++count;
        return count;
    }
};