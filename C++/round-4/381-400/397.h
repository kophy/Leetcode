// version 1: whole queue
class Solution {
public:
	int integerReplacement(int n) {
		if (n == 1)
			return 0;

		queue<long> data;
		data.push(n);
		unordered_set<long> visited;
		visited.insert(n);

		int step = 0;
		while (!data.empty()) {
			++step;
			queue<long> next;
			while (!data.empty()) {
				long num = data.front();
				data.pop();
				if (num % 2 == 1) {
					if (num + 1 == 1 || num - 1 == 1)
						return step;
					if (visited.find(num + 1) == visited.end()) {
						next.push(num + 1);
						visited.insert(num + 1);
					}
					if (visited.find(num - 1) == visited.end()) {
						next.push(num - 1);
						visited.insert(num - 1);
					}
				} else {
					if (num / 2 == 1)
						return step;
					if (visited.find(num / 2) == visited.end()) {
						next.push(num / 2);
						visited.insert(num / 2);
					}
				}
			}
			data = next;
		}
		return -1;
	}
};

// version 2: each element
class Solution {
public:
	int integerReplacement(int n) {
		queue<pair<long, int>> data;
		data.push(make_pair(n, 0));
		unordered_set<long> visited;
		visited.insert(n);

		while (!data.empty()) {
			auto p = data.front();
			data.pop();
			long num = p.first;
			int step = p.second;

			if (num == 1)
				return step;
			if (num % 2 == 1) {
				if (visited.find(num + 1) == visited.end()) {
					data.push(make_pair(num + 1, step + 1));
					visited.insert(num + 1);
				}
				if (visited.find(num - 1) == visited.end()) {
					data.push(make_pair(num - 1, step + 1));
					visited.insert(num - 1);
				}
			} else {
				if (visited.find(num / 2) == visited.end()) {
					data.push(make_pair(num / 2, step + 1));
					visited.insert(num / 2);
				}
			}
		}
		return -1;
	}
};