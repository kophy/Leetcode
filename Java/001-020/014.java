public class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0)
            return "";
        StringBuilder prefix = new StringBuilder();
        for (int i = 0; i < strs[0].length(); ++i) {
            char c = strs[0].charAt(i);
            for (String s : strs)
                if (s.length() <= i || s.charAt(i) != c)
                    return prefix.toString();
            prefix.append(c);
        }
        return prefix.toString();
    }
}