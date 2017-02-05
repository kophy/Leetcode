/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode *, RandomListNode *> m;
        m[nullptr] = nullptr;
        for (auto curr = head; curr; curr = curr->next)
            m[curr] = new RandomListNode(curr->label);
        for (auto curr = head; curr; curr = curr->next) {
            m[curr]->next = m[curr->next];
            m[curr]->random = m[curr->random];
        }
        return m[head];
    }
};