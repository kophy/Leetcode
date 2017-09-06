class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> data;
for (int &num : nums) {
			if (data.size() < k)
				data.push(num);
			else if (num > data.top()) {
				data.pop();
				data.push(num);
			}
		}
		return data.top();
	}
};