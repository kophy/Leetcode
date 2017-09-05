class Solution {
public:
	string simplifyPath(string path) {
		vector<string> data;
		int pos = 0;
		while (pos < path.size()) {
			int k = 0;
			while (pos < path.size() && path[pos] == '/')
				++pos;
			while (pos + k < path.size() && path[pos + k] != '/')
				++k;
			string str = path.substr(pos, k);
			pos += k;

			if (str == "" || str == ".")
				continue;
			else if (str == "..") {
				if (data.size() > 0)
					data.pop_back();
			} else
				data.push_back(str);
		}
		ostringstream oss;
for (string &str : data)
			oss << "/" << str;
		return data.empty()? "/" : oss.str();
	}
};