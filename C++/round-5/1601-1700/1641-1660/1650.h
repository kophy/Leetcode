/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
 public:
  Node* lowestCommonAncestor(Node* p, Node* q) {
    int depth_p = getDepth(p);
    int depth_q = getDepth(q);

    if (depth_p > depth_q) {
      for (int i = 0; i < depth_p - depth_q; ++i) {
        p = p->parent;
      }
    } else {
      for (int i = 0; i < depth_q - depth_p; ++i) {
        q = q->parent;
      }
    }

    while (p != q) {
      p = p->parent;
      q = q->parent;
    }
    return p;
  }

 private:
  int getDepth(Node* node) {
    int depth = 0;
    for (; node->parent != nullptr; node = node->parent) {
      ++depth;
    }
    return depth;
  }
};