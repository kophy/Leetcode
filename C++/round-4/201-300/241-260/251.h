class Vector2D {
public:
	Vector2D(vector<vector<int>>& vec2d) {
		for (auto &vec : vec2d) {
			if (vec.empty())
				continue;
			begin.push(vec.begin());
			end.push(vec.end());
		}
	}

	int next() {
		int result = *(begin.front());
		if (++begin.front() == end.front()) {
			begin.pop();
			end.pop();
		}
		return result;
	}

	bool hasNext() {
		return !begin.empty();
	}

private:
	queue<vector<int>::iterator> begin;
	queue<vector<int>::iterator> end;
};