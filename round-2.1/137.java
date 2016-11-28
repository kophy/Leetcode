public class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer, Integer> count = new HashMap<>();
        for (int num : nums)
            count.put(num, (count.containsKey(num)? count.get(num) : 0) + 1);
        for (Integer key : count.keySet())
            if (count.get(key) < 3)
                return key;
        return -1;
    }
}