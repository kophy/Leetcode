public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0)
            return null;
        
        PriorityQueue<ListNode> data = new PriorityQueue<ListNode>(lists.length, new Comparator<ListNode>(){
            @Override
            public int compare(ListNode o1, ListNode o2) {
                return Integer.compare(o1.val, o2.val);
            }
        });
        for (ListNode head : lists)
            if (head != null)
                data.add(head);
        
        ListNode dummy = new ListNode(0), curr = dummy;
        while (!data.isEmpty()){
            curr.next = data.poll();
            curr = curr.next;
            if (curr.next != null) {
                data.add(curr.next);
                curr.next = null;
            }
        }
        return dummy.next;
    }
}