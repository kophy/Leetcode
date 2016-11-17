public class Solution {
    public boolean isPalindrome(String s) {
        char[] data = s.toLowerCase().toCharArray();
        int i = 0, j = data.length - 1;
        while (i < j) {
            while (i < j && !Character.isLetterOrDigit(data[i]))
                ++i;
            while (i < j && !Character.isLetterOrDigit(data[j]))
                --j;
            if (data[i++] != data[j--])
                return false;
        }
        return true;
    }
}