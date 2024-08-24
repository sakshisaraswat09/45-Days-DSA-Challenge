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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* newHead = NULL;
        ListNode* forward = NULL;

        while(curr){
            ListNode* temp = curr;
            int n = k-1;
            while(n--){
                if(!temp) return newHead;
                temp = temp->next;
            }
            if(!temp) return newHead;
            forward = temp->next;
            temp->next = NULL;

            if(!newHead){
                newHead = reverse(curr);
            }else{
                prev->next = reverse(curr);
            }

            prev = curr;
            curr = forward;

            prev->next = curr;
        }
        return newHead;
    }
};
