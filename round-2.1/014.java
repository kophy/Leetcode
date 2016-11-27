public class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0)
            return "";
        Arrays.sort(strs);
        StringBuilder result = new StringBuilder();

        // only compare the first and last string
        char[] a = strs[0].toCharArray();
        char[] b = strs[strs.length - 1].toCharArray();
        for (int i = 0; i < Math.min(a.length, b.length) && a[i] == b[i]; i ++)
            result.append(b[i]);
        return result.toString();
    }
}