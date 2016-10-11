class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
        vector<pair<int, int>> result;
        if (matrix.empty() || matrix[0].empty())
            return result;
        M = matrix.size(), N = matrix[0].size();

        set<int> pacific, atlantic;
        for (int i = 0; i < M; ++i) {
            pacific.insert(pos2key(i, 0));
            atlantic.insert(pos2key(i, N - 1));
        }
        for (int j = 0; j < N; ++j) {
            pacific.insert(pos2key(0, j));
            atlantic.insert(pos2key(M - 1, j));
        }
        grow(pacific, matrix);
        grow(atlantic, matrix);

        for (auto iter = pacific.begin(); iter != pacific.end(); ++iter)
            if (atlantic.find(*iter) != atlantic.end())
                result.push_back(key2pos(*iter));
        return result;
    }

private:
    int M, N;

    void grow(set<int> &reachable, vector<vector<int>> &matrix) {
        queue<int> data();
        for (auto iter = reachable.begin(); iter != reachable.end(); ++iter)
            data.push(*iter);
        while (!data.empty()) {
            pair<int, int> curr = key2pos(data.front());
            data.pop();
            int i = curr.first, j = curr.second;
            int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
            for (int k = 0; k < 4; ++k) {
                int key = pos2key(i + di[k], j + dj[k]);
                if (valid(i + di[k], j + dj[k]) && matrix[i + di[k]][j + dj[k]] >= matrix[i][j] &&
                        reachable.find(key) == reachable.end()) {
                    reachable.insert(key);
                    data.push(key);
                }
            }
        }
    }

    bool valid(int i, int j) {
        return i >= 0 && i < M && j >= 0 && j < N;
    }

    int pos2key(int i, int j) {
        return i * N + j;
    }

    pair<int, int> key2pos(int key) {
        return make_pair(key / N, key % N);
    }
};