class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> successors(numCourses);
        vector<int> precursor_count(numCourses, 0);
        for (auto &p : prerequisites) {
            successors[p.second].push_back(p.first);
            ++precursor_count[p.first];
        }
        
        // topological sort
        queue<int> data;
        for (int i = 0; i < precursor_count.size(); ++i) {
            if (precursor_count[i] == 0) {
                --numCourses;
                data.push(i);
            }
        }
        while (!data.empty()) {
            int curr = data.front();
            data.pop();
            for (int succ : successors[curr]) {
                if (--precursor_count[succ] == 0) {
                    --numCourses;
                    data.push(succ);
                }
            }
        }
        return numCourses == 0;
    }
};