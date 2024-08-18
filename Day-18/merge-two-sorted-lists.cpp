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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return NULL;
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        ListNode* newHead = NULL;
        if(curr1->val>curr2->val){
            newHead = curr2;
            curr2 = curr2->next;
        }else{
            newHead = curr1;
            curr1 = curr1->next;
        }

        ListNode* temp = newHead;

        while(curr1!=NULL && curr2!=NULL){
            if(curr1->val>curr2->val){
                temp->next = curr2;
                temp = temp->next;
                curr2 = curr2->next;
            }else{
                temp->next = curr1;
                temp = temp->next;
                curr1 = curr1->next;
            }
        }

        if(curr1!=NULL) temp->next = curr1;

        if(curr2!=NULL) temp->next =  curr2;
        
        return newHead;
    }
};
