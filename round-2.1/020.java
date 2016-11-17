public class Solution {
    public boolean isValid(String s) {
        HashMap<Character, Character> match = new HashMap<Character, Character>();
        match.put('(', ')');
        match.put('[', ']');
        match.put('{', '}');
        Stack<Character> data = new Stack<Character>();
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (match.get(c) != null)
                data.push(c);
            else {
                if (data.isEmpty() || match.get(data.peek()) != c)
                    return false;
                data.pop();
            }
        }
        return data.isEmpty();
    }
}