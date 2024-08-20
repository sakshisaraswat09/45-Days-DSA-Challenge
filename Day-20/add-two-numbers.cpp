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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int carry = 0;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* prev1 = NULL;

        while(temp1 && temp2){
            int sum = temp1->val + temp2->val + carry;
            temp1->val = sum%10;
            carry = sum/10;

            prev1 = temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if(temp2){
            temp1 = prev1;
            temp1->next = temp2;
            temp1 = temp1->next;
            if(carry==0) return l1;
            else{
                while(temp1){
                    int sum = temp1->val+carry;
                    temp1->val = sum%10;
                    carry = sum/10;
                    temp1 = temp1->next;
                }
            }
        }

        if(temp1){
            if(carry==0) return l1;
            else{
                while(temp1){
                    int sum = temp1->val+carry;
                    temp1->val = sum%10;
                    carry = sum/10;
                    temp1 = temp1->next;
                }
            }
        }

        if(carry){
            ListNode* newNode = new ListNode(carry);
            ListNode* prev = NULL;
            ListNode* curr = l1;
            while(curr){
                prev = curr;
                curr = curr->next;
            }
            prev->next = newNode;
        }

        return l1;
    }
};
