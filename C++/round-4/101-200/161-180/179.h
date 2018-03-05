class Solution {
public:
	string largestNumber(vector<int>& nums) {
		vector<string> data;
for (int &num : nums)
			data.push_back(to_string(num));
		sort(data.begin(), data.end(), [](string &a, string &b)->bool {
			// compare by behavior, instead of by property
			return a + b > b + a;
		});
		ostringstream oss;
for (string &str : data)
			oss << str;
		string result = oss.str();
		if (result.empty() || result[0] == '0')
			return "0";
		return result;
	}
};