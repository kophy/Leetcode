public class Solution {
    public int[] nextGreaterElement(int[] findNums, int[] nums) {
        Map<Integer, Integer> next = new HashMap<Integer, Integer>();
        Stack<Integer> data = new Stack<Integer>();
        for (int num : nums) {
            while (!data.isEmpty() && data.peek() < num) 
                next.put(data.pop(), num);
            data.push(num);
        }
        int[] result = new int[findNums.length];
        for (int i = 0; i < findNums.length; ++i)
            result[i] = next.getOrDefault(findNums[i], -1);
        return result;
    }
}