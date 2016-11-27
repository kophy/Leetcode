public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> result = new ArrayList<>();
        if (strs == null || strs.length == 0)
            return result;
        Map<String, Integer> map = new HashMap<>();
        for (String s: strs) {
            char[] c = s.toCharArray();
            Arrays.sort(c);
            String unique = new String(c);
            if (map.get(unique) == null) {
                map.put(unique, map.size());
                result.add(new ArrayList<String>());
            }
            Integer id = map.get(unique);
            result.get(id).add(s);
        }
        return result;
    }
}