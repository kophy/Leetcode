class Solution {
public:
    bool validUtf8(vector<int> &data) {
        int pos = 0;
        while (pos < data.size()) {
            if (data[pos] >> 7 == 0)
                ++pos;
            else if (data[pos] >> 5 == 6) {
                ++pos;
                for (int i = 0; i < 1; ++i)
                    if (!valid(data, pos++))
                        return false;
            } else if (data[pos] >> 4 == 14) {
                ++pos;
                for (int i = 0; i < 2; ++i)
                    if (!valid(data, pos++))
                        return false;
            } else if (data[pos] >> 3 == 30) {
                ++pos;
                for (int i = 0; i < 3; ++i)
                    if (!valid(data, pos++))
                        return false;
            } else
                return false;
        }
        return true;
    }

private:
    bool valid(vector<int> &data, int pos) {
        return pos < data.size() && (data[pos] >> 6 == 2);
    }
};