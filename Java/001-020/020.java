public class Solution {
    public boolean isValid(String s) {
        Stack<Character> data = new Stack<Character>();
        Map<Character, Character> match = new HashMap<Character, Character>();
        match.put('(', ')');
        match.put('[', ']');
        match.put('{', '}');

        for (char c : s.toCharArray()) {
            if (match.containsKey(c))
                data.push(match.get(c));
            else if (!data.isEmpty() && data.peek() == c)
                data.pop();
            else
                return false;
        }
        return data.isEmpty();
    }
}