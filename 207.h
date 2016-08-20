class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> preNum(numCourses, 0);
        stack<int> sq; //DFS
        int count=0;

		for(auto req : prerequisites) {
            //collect all limited courses by req.second
            graph[req.second].push_back(req.first);
            //number of courses needed to be finished before req.first
            ++preNum[req.first];
        }

        //put avaliable courses in the stack
        for(int i = 0; i < numCourses; ++i)
            if(preNum[i] == 0)
                sq.push(i); //avaliable to take

        //start to take course one by one
        while(!sq.empty()) {
            //take one course
            int course = sq.top();
            sq.pop();
            ++count;
            //released courses after taking the course
		for(auto c : graph[course]) {
                //no prerequist, avaliable to take
                --preNum[c];
                if(preNum[c] == 0)
                    sq.push(c);
            }
        }
        return count == graph.size();
    }
};