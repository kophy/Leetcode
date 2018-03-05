class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size())
            return false;
        
        // index every word
        unordered_map<string, int> m;
        int index = 0;
        for (auto &p : pairs) {
            if (!m.count(p.first))
                m[p.first] = index++;
            if (!m.count(p.second))
                m[p.second] = index++;
        }
        
        // build union find set
        vector<int> labels(m.size());
        for (int i = 0; i < labels.size(); ++i)
            labels[i] = i;
        for (auto &p : pairs)
            unionLabels(labels, m[p.first], m[p.second]);
        
        for (int i = 0; i < words1.size(); ++i) {
            // [] operator will make insertion if key not exists
            if (!m.count(words1[i]) || !m.count(words2[i]))
                if (words1[i] != words2[i])
                    return false;
            if (findLabel(labels, m[words1[i]]) != findLabel(labels, m[words2[i]]))
                return false;
        }
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