class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> post_vec(numCourses);
        vector<int> preq_count(numCourses, 0);

        for(auto pq : prerequisites) {
            post_vec[pq.second].push_back(pq.first);
            ++preq_count[pq.first];
        }

        queue<int> data;
        for(int i = 0; i < numCourses; ++i)
            if(preq_count[i] == 0)
                data.push(i);

        while(!data.empty()) {
            int course = data.front();
            data.pop();
            --numCourses;

            for(auto post : post_vec[course])
                if(--preq_count[post] == 0)
                    data.push(post);
        }
        return numCourses == 0;
    }
};