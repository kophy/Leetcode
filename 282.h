class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if(num.size() == 0)
            return result;
        addOperators_help(result, num, target, "", 0, 0, 0);
        return result;
    }

private:
    void addOperators_help(vector<string>& result, string &num, int &target, string path, int pos, long cur, long prev) {
        if(pos == num.size()) {
            if(target == cur)
                result.push_back(path);
            return;
        }
        for(int i = pos; i < num.size(); ++i) {
            if (num[pos] == '0' && i > pos)
                return;
            string sub_str = num.substr(pos, i - pos + 1);
            long sub_int = stol(sub_str);

            if(pos == 0)
                addOperators_help(result, num, target, path + sub_str, i + 1, sub_int, sub_int);
            else {
                addOperators_help(result, num, target, path + "+" + sub_str, i + 1, cur + sub_int, sub_int);
                addOperators_help(result, num, target, path + "-" + sub_str, i + 1, cur - sub_int, -sub_int);
                addOperators_help(result, num, target, path + "*" + sub_str, i + 1, cur - prev + prev * sub_int, prev * sub_int);
            }
        }
    }
};