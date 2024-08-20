/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head){
        int len = 0;

        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }

        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = getLength(headA);
        int len2 = getLength(headB);

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        if(len1>len2){
            int n = len1-len2;
            while(n--) temp1 = temp1->next;
        }else{
            int n = len2-len1;
            while(n--) temp2 = temp2->next;
        }

        while(temp1!=NULL && temp2!=NULL && temp1!=temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
};
