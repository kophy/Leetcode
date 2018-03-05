class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result;
        
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
                result.push_back(i);
                data.push(i);
            }
        }
        while (!data.empty()) {
            int curr = data.front();
            data.pop();
            for (int succ : successors[curr]) {
                if (--precursor_count[succ] == 0) {
                    result.push_back(succ);
                    data.push(succ);
                }
            }
        }
        return result.size() == numCourses? result : vector<int>();
    }
};