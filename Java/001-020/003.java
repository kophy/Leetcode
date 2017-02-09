public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxLen = 0;
        Set<Character> visited = new HashSet<Character>();
        for (int l = 0, r = 0; r < s.length(); ++r) {
            char c = s.charAt(r);
            while (l < r && visited.contains(c))
                visited.remove(s.charAt(l++));
            visited.add(c);
            maxLen = Math.max(maxLen, r - l + 1);
        }
        return maxLen;
    }
}