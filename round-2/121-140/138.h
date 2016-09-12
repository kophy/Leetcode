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
        map<RandomListNode *, RandomListNode *> nodemap;
        nodemap[NULL] = NULL;
        for (auto curr = head; curr; curr = curr->next)
            nodemap[curr] = new RandomListNode(curr->label);
        for (auto curr = head; curr; curr = curr->next) {
            nodemap[curr]->next = nodemap[curr->next];
            nodemap[curr]->random = nodemap[curr->random];
        }
        return nodemap[head];
    }
};