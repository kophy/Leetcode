class Solution {
public:
    int lengthLongestPath(string input) {
        istringstream ss(input);
        vector<string> data;
        string temp;
        int result = 0;

        while (getline(ss, temp, '\n')) {
            int pos = 0;
            while (pos < temp.size() && temp[pos] == '\t')
                ++pos;
            int level = pos;
            // case 1: directory
            if (find(temp.begin(), temp.end(), '.') == temp.end()) {
                string directory = temp.substr(pos);
                if (level == data.size())
                    data.push_back("");
                data[level] = directory;
            }
            // case 2: file
            else {
                string file = temp.substr(pos);
                if (level == data.size())
                    data.push_back("");
                data[level] = file;
                int length = data[0].size();
                for (int i = 1; i <= level; ++i)
                    length += 1 + data[i].size();
                result = max(result, length);
            }
        }
        return result;
    }
};