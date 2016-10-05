/* compare funciton in priority queue and sort are mirroring each other */

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> result;

        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)->bool {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> data(cmp);
for (auto person : people)
            data.push(person);

        while (!data.empty()) {
            auto person = data.top();
            data.pop();
            result.insert(result.begin() + person.second, person);
        }
        return result;
    }
};

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> result;
        sort(people.begin(), people.end(), [](const pair<int, int> &a, const pair<int, int> &b)->bool {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        });
for (auto person : people)
            result.insert(result.begin() + person.second, person);
        return result;
    }
};