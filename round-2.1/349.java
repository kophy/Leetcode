public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> temp = new HashSet<Integer>();
        for (int num : nums1)
            temp.add(num);
        Set<Integer> intersect = new HashSet<Integer>();
        for (int num : nums2)
            if (temp.contains(num))
                intersect.add(num);
        int result[] = new int[intersect.size()];
        int i = 0;
        for (int num : intersect)
            result[i++] = num;
        return result;
    }
}