class Solution {
public:
	bool validTree(int n, vector<pair<int, int>> &edges) {
		if (edges.size() != n - 1)
			return false;
		vector<int> labels(n);
		for (int i = 0; i < n; ++i)
			labels[i] = i;
for (auto &edge : edges)
			unionLabels(labels, edge.first, edge.second);
		int label = findLabel(labels, 0);
		for (int i = 1; i < n; ++i)
			if (findLabel(labels, i) != label)
				return false;
		return true;
	}

private:
	int findLabel(vector<int> &labels, int i) {
		if (labels[i] != i)
			labels[i] = findLabel(labels, labels[i]);
		return labels[i];
	}

	void unionLabels(vector<int> &labels, int i, int j) {
		labels[findLabel(labels, i)] = findLabel(labels, j);
	}
};