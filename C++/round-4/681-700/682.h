class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> data;
        for (string& op : ops){
            if (op == "C")
                data.pop_back();
            else if (op == "D")
                data.push_back(2 * data.back());
            else if (op == "+")
                data.push_back(data.end()[-2] + data.end()[-1]);
            else
                data.push_back(stoi(op));
        }
        return accumulate(data.begin(), data.end(), 0);
    }
};