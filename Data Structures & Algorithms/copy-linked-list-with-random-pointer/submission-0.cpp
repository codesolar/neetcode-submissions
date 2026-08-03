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
        unordered_map<Node*, Node*> map;
        if(head == NULL) return head;
        Node* temp = head;
        Node* thead = new Node(head->val);
        map[head] = thead;
        Node* temp_thead = thead;
        while(temp -> next){
            Node* thead_next = new Node(temp->next->val);
            map[temp->next] = thead_next;
            temp_thead->next = thead_next;
            temp = temp->next;
            temp_thead = thead_next;
        }
        temp = head;
        temp_thead = thead;
        while(temp){
            map[temp]->random = map[temp->random];
            temp = temp->next;
        }
        return thead;
    }
};
