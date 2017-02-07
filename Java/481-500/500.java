public class Solution {
    public String[] findWords(String[] words) {
        String[] strs = {"QWERTYUIOP","ASDFGHJKL","ZXCVBNM"};
        Map<Character, Integer> char2row = new HashMap<Character, Integer>();
        for (int i = 0; i < strs.length; ++i)
            for (char c : strs[i].toCharArray())
                char2row.put(c, i);
        List<String> result = new LinkedList<String>();
        for (String s : words) {
            if (s.length() == 0)
                continue;
            boolean flag = true;
            int index = char2row.get(Character.toUpperCase(s.charAt(0)));
            for (char c : s.toUpperCase().toCharArray()) {
                if (char2row.get(c) == index)
                    continue;
                flag = false;
                break;
            }
            if (flag)
                result.add(s);
        }
        return result.toArray(new String[0]);
    }
}