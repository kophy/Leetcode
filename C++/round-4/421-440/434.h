class Solution {
public:
	int countSegments(string s) {
		stringstream ss(s);
		string temp;
		int count = 0;
		while (ss >> temp)
			++count;
		return count;
	}
};