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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;

        ListNode* newHead = reverse(head);
        if(n==1){
            newHead = newHead->next;
            return reverse(newHead);
        }
        ListNode* prev = NULL;
        ListNode* curr = newHead;
        int k=1;
        while(k<n){
            prev = curr;
            curr = curr->next;
            k++;
        }
        prev->next = curr->next;
        curr = curr->next;

        return reverse(newHead);
    }
};
