/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        vector<Node*>nodes;
        Node* temp = head;
        while(temp){
            nodes.push_back(temp);
            temp = temp->next;
        }
        int n = nodes.size();
        unordered_map<Node*, int>mp;
        for(int i = 0; i<n; i++){
            mp[nodes[i]] = i;
        }
        vector<Node*>newNodes(n);

        newNodes[n-1] = new Node(nodes[n-1]->val);
        for(int i = n-2; i>=0; i--){
            newNodes[i] = new Node(nodes[i]->val);
            newNodes[i]->next = newNodes[i+1];
        }
        for(int i = 0; i<n; i++){
            newNodes[i]->random = nodes[i]->random == NULL? NULL : newNodes[mp[nodes[i]->random]];
        }
        return newNodes[0];
    }
};
