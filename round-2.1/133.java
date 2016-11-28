/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        HashMap<UndirectedGraphNode, UndirectedGraphNode> map = new HashMap<>();
        map.put(null, null);
        Queue<UndirectedGraphNode> data = new LinkedList<>();
        HashSet<UndirectedGraphNode> visited = new HashSet<>();

        if (node != null)
            data.add(node);
        visited.add(node);

        while (!data.isEmpty()) {
            UndirectedGraphNode curr = data.poll();
            if (!map.containsKey(curr))
                map.put(curr, new UndirectedGraphNode(curr.label));
            for (UndirectedGraphNode neighbor : curr.neighbors) {
                if (!map.containsKey(neighbor))
                    map.put(neighbor, new UndirectedGraphNode(neighbor.label));
                map.get(curr).neighbors.add(map.get(neighbor));
                if (!visited.contains(neighbor)) {
                    data.add(neighbor);
                    visited.add(neighbor);
                }
            }
        }
        return map.get(node);
    }
}