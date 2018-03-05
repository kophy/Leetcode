class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        sort(target.begin(), target.end());
        
        // convert each sticker to vector form
        vector<vector<int>> sticker_vecs(stickers.size(), vector<int>(26, 0));
        for (int i = 0; i < stickers.size(); ++i) 
            for (char c : stickers[i])
                ++sticker_vecs[i][c - 'a'];
        
        // cache result = from recursion to dp
        unordered_map<string, int> cache;
        cache[""] = 0;
        return helper(cache, sticker_vecs, target);
    }
    
private:
    int helper(unordered_map<string, int> &cache, vector<vector<int>>& stickers, string target) {
        if (cache.count(target))
            return cache[target];

        // build target vector
        vector<int> vec(26, 0);
        for (char c : target)
            ++vec[c - 'a'];
        
        cache[target] = INT_MAX;
        // try every sticker, find minimum stickers required
        for (auto &sticker : stickers) {
            string new_target = "";
            for (int i = 0; i < 26; ++i)
                new_target += string(max(vec[i] - sticker[i], 0), 'a' + i);
            
            // sticker must remove something (reduce the problem)
            if (new_target == target)
                continue;
            int rest = helper(cache, stickers, new_target);
            if (rest != -1)
                cache[target] = min(cache[target], 1 + rest);
        }
        if (cache[target] == INT_MAX)
            cache[target] = -1;
        return cache[target];
    }
};