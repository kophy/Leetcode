/* version 1: StringBuilder */
public class Solution {
    public String reverseString(String s) {
        StringBuilder data = new StringBuilder(s);
        data.reverse();
        return data.toString();
    }
}

/* version 2: char array */
public class Solution {
    public String reverseString(String s) {
        char[] data = s.toCharArray();
        for (int i = 0, j = data.length - 1; i < j; ++i, --j) {
            char temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
        return new String(data);
    }
}