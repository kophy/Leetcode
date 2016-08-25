class Solution {
public:
    string simplifyPath(string path) {
        string result;
		vector<string> directory;
		stringstream ss(path);
		string temp;
		while(getline(ss, temp, '/')) {
			if (temp == "" || temp == ".")
				continue;
			else if (temp == ".." && !directory.empty())
				directory.pop_back();
			else if (temp != "..")
				directory.push_back(temp);
		}
		for (int i = 0; i < directory.size(); ++i)
			result += "/" + directory[i];
		return result.empty() ? "/" : result;
    }
};