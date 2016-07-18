class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int> > distance(m + 1, vector<int> (n + 1, 0));
        for (int i = 1; i <= m; i++)
            distance[i][0] = i;
        for (int j = 1; j <= n; j++)
            distance[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1])
                    distance[i][j] = distance[i - 1][j - 1];
                else distance[i][j] = min(distance[i - 1][j - 1] + 1,
					min(distance[i][j - 1] + 1, distance[i - 1][j] + 1));
            }
        }
        return distance[m][n];
    }
};