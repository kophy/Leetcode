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
        map<RandomListNode *, RandomListNode *> my_map;
        my_map[NULL] = NULL;
        for (RandomListNode *curr = head; curr; curr = curr->next)
            my_map[curr] = new RandomListNode(curr->label);
        for (RandomListNode *curr = head; curr; curr = curr->next) {
            my_map[curr]->next = my_map[curr->next];
            my_map[curr]->random = my_map[curr->random];
        }
        return my_map[head];
    }
};