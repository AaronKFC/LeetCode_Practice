/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        
        Node* result = dfs(node);
        return result;
    }
    
private:
    // unordered_map<*Node, *Node> map; //wrong
    unordered_map<Node*, Node*> map;
    
    
    Node* dfs(Node* node) {
        if (map.find(node) != map.end()) {
            return map[node];
        }
        Node* copy= new Node(node->val);
        // map.insert({node, copy}); 
        map[node] = copy;
        for (int i=0; i<node->neighbors.size(); i++) {
            copy->neighbors.push_back(dfs(node->neighbors[i]));
        }
        return copy;
    }
};