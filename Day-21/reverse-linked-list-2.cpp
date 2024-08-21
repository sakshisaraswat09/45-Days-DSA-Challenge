/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = curr->next;

        while(curr){
            forward = curr->next;

            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left==right) return head;

        int i=1;
        ListNode* leftNode = head;
        ListNode* prev = NULL;

        while(i<left){
            prev = leftNode;
            leftNode = leftNode->next;
            i++;
        }

        ListNode* rightNode = leftNode;
        int k=0;
        while(k!=(right-left)){
            k++;
            rightNode = rightNode->next;
        }

        ListNode* forward = rightNode->next;
        rightNode->next = NULL;

        ListNode* curr = reverse(leftNode);

        if(prev) prev->next = curr;
        else head = curr;

        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = forward;

        return head;
    }
};
