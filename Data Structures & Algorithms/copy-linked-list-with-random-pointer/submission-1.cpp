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
        unordered_map<Node*, Node*> pam; // map of og node to copied node
        
        Node* curr = head;
        while (curr) {
            Node* temp = new Node(curr->val);
            pam[curr] = temp;

            curr = curr->next;
        }

        curr = head;

        while (curr) {
            Node* currCp = pam[curr];
            currCp->next = pam[curr->next];
            currCp->random = pam[curr->random];

            currCp = nullptr;

            curr = curr->next;
        }

        return pam[head];
    }
};
