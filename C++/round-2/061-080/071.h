class Solution {
public:
    string simplifyPath(string path) {
        vector<string> directory;
        stringstream ss(path);
        string temp;
        while (getline(ss, temp, '/')) {	// string split in C++
            // case 1: current directory
            if (temp == "." || temp == "")
                continue;
            // case 2: parent directory
            else if (temp == "..") {
                if (directory.size())
                    directory.pop_back();
            }
            // case 3: regular directory
            else
                directory.push_back(temp);
        }
        string result;
        for (int i = 0; i < directory.size(); ++i)
            result += "/" + directory[i];
        return (result.size() == 0)? "/" : result;	// return "/" for root directory
    }
};