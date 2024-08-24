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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* prev = head;

        while(prev!=NULL && head!=NULL && prev->val==head->val){
            while(prev!=NULL && prev->val==head->val){
                prev = prev->next;
            }

            if(prev==head->next){
                prev = head;
                break;
            }else{
                head = prev;
            }
        }

        if(!head) return head;

        ListNode* curr = head->next;
        ListNode* forward = curr;
        while(curr){
            forward = curr->next;
            if(forward!=NULL && curr->val==forward->val){
                while(forward!=NULL && curr->val==forward->val){
                    forward = forward->next;
                }
                prev->next = forward;
                curr = forward;
            }else{
                prev = curr;
                curr = forward;
            }
        }
        return head;
    }
};
