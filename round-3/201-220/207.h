class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> successors(numCourses);
		vector<int> pred_count(numCourses, 0);
		
		for (auto preq : prerequisites) {
			successors[preq.second].push_back(preq.first);
			++pred_count[preq.first];
		}
		
		queue<int> data;
		int count = 0;
		for (int i = 0; i < numCourses; ++i)
			if (pred_count[i] == 0)
				data.push(i);
		while (!data.empty()) {
			int curr = data.front();
			data.pop();
			++count;
			for (int course : successors[curr])
				if (--pred_count[course] == 0)
					data.push(course);
		}
		return count == numCourses;
    }
};