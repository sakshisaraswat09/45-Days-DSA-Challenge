/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;

        Node* curr = head;

        while(curr){
            if(curr->child!=NULL){
                Node* temp = curr->child;
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next = curr->next;
                if(curr->next!=NULL){
                    curr->next->prev = temp;
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
                curr = curr->next;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
};
