public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> s1 = new HashSet<Integer>(), s2 = new HashSet<Integer>();
        for (int num : nums1)
            s1.add(num);
        for (int num : nums2)
            s2.add(num);
        Set<Integer> intersect = new HashSet<Integer>();
        for (int num : s1)
            if (s2.contains(num))
                intersect.add(num);
        int[] result = new int[intersect.size()];
        int k = 0;
        for (int num : intersect)
            result[k++] = num;
        return result;
    }
}