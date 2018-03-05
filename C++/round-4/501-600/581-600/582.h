class Solution {
public:
	vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
		unordered_map<int, vector<int>> children_map;
		for (int i = 0; i < pid.size(); ++i)
			children_map[ppid[i]].push_back(pid[i]);

		queue<int> data;
		unordered_set<int> killed;
		data.push(kill);
		killed.insert(kill);

		while (!data.empty()) {
			int current = data.front();
			data.pop();
			for (int child : children_map[current]) {
				if (killed.find(child) == killed.end()) {
					data.push(child);
					killed.insert(child);
				}
			}
		}
		return vector<int>(killed.begin(), killed.end());
	}
};