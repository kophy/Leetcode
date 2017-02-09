public class Solution {
    private int[] data;

    public Solution(int[] nums) {
        this.data = nums;
    }

    public int[] reset() {
        return data;
    }

    public int[] shuffle() {
        int[] temp = data.clone();
        Random random = new Random();
        for (int i = temp.length - 1; i > 0; --i) {
            int j = random.nextInt(i + 1);
            int t = temp[i];
            temp[i] = temp[j];
            temp[j] = t;
        }
        return temp;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */