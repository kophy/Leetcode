class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		unordered_map<RandomListNode *, RandomListNode *> m;
		m[nullptr] = nullptr;
		for (auto node = head; node; node = node->next) {
			if (!m.count(node))
				m[node] = new RandomListNode(node->label);
			if (!m.count(node->next))
				m[node->next] = new RandomListNode(node->next->label);
			if (!m.count(node->random))
				m[node->random] = new RandomListNode(node->random->label);
			m[node]->next = m[node->next];
			m[node]->random = m[node->random];
		}
		return m[head];
	}
};