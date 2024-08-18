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
    int getDecimalValue(ListNode* head) {
        string s = "";

        ListNode* temp = head;
        while(temp!=NULL){
            s+=(temp->val==1)?"1":"0";
            temp=temp->next;
        }

        int ans=0;
        int i=0;
        int j=s.length()-1;
        while(j>=0){
            ans+=(s[j]=='1')?pow(2,i):0;
            i++;
            j--;
        }
        return ans;
    }
};
