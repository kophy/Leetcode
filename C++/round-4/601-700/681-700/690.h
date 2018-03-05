class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee *> id2employee;
        for (auto &employee : employees)
            id2employee[employee->id] = employee;
        
        queue<int> data;
        unordered_set<int> visited;
        data.push(id);
        visited.insert(id);
        while (!data.empty()) {
            int curr = data.front();
            data.pop();
            for (int sub : id2employee[curr]->subordinates)
                if (!visited.count(sub)) {
                    data.push(sub);
                    visited.insert(sub);
                }
        }
        int result = 0;
        for (int id : visited)
            result += id2employee[id]->importance;
        return result;
    }
};