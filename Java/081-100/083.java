/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode left = head, right = head;
        while (left != null) {
            while (right != null && left.val == right.val)
                right = right.next;
            left.next = right;
            left = right;
        }
        return head;
    }
}