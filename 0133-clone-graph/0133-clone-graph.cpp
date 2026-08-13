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
   
    Node*dfs(Node* node,Node*clone_node,map<Node*,Node*>&mp){
        vector<Node*>neigbour;
       clone_node= new Node(node->val);
        mp[node]=clone_node;
        for(auto it:node->neighbors){
            if(mp.find(it)!=mp.end()){
                neigbour.push_back(mp[it]);
            }
            else{
                neigbour.push_back(dfs(it,clone_node,mp));
            }

        }
      clone_node->neighbors=neigbour;
      return clone_node;

    }

public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return node;
        }
        if(node->neighbors.size()==0){
            Node *clone=new Node(node->val);
            return clone;
        }
        map<Node*,Node*>mp;
        Node*clone_node;
       return dfs(node,clone_node,mp);
    }
};