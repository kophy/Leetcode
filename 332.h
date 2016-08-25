class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
		map<string, multiset<string>> targets;
		vector<string> route;
		for (auto ticket : tickets)
            targets[ticket.first].insert(ticket.second);
        visit(targets, route, "JFK");
        return vector<string>(route.rbegin(), route.rend());
    }

    void visit(map<string, multiset<string>> &targets, vector<string> &route, string airport) {
        while (targets[airport].size()) {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(targets, route, next);
        }
        route.push_back(airport);
    }
};