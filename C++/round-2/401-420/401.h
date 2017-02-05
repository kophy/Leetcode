class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for (int i = 0; i <= min(4, num); ++i) {
            set<int> hours = possible_values(i, 4, 12);
            set<int> minutes = possible_values(num - i, 6, 60);
            for (int hour : hours)
                for (int minute : minutes) {
                    string time = to_string(hour) + ":";
                    if (minute < 10)
                        time += "0";
                    time += to_string(minute);
                    result.push_back(time);
                }
        }
        return result;
    }

private:
    set<int> possible_values(int num, int len, int upper_bound) {
        set<int> values;
        if (num > len)
            return values;

        search(values, num, len, 0, upper_bound);

        return values;
    }

    void search(set<int> &values, int num, int len, int curr, int upper_bound) {
        if (num == 0) {
            if (curr < upper_bound)
                values.insert(curr);
        }
        if (len == 0 || curr >= upper_bound)
            return;
        if (num < len)
            search(values, num, len - 1, curr * 2, upper_bound);
        search(values, num - 1, len - 1, curr * 2 + 1, upper_bound);
    }
};