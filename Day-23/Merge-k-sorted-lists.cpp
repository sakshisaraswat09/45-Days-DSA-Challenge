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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        int cnt = 0;
        for(int i=0;i<lists.size();i++){
            if(lists[i]==NULL) cnt++;
        }
        if(cnt==lists.size()) return NULL;

        ListNode* head = NULL;
        ListNode* temp = head;

        for(int i=0;i<lists.size();i++){
            if(!temp){
                temp = lists[i];
                head = temp;
            }else{
                temp->next = lists[i];
            }
            while(temp!=NULL && temp->next!=NULL) temp = temp->next;
        }

        vector<int>v;
        temp = head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(),v.end());
        temp = head;
        int i=0;
        while(temp!=NULL){
            temp->val = v[i++];
            temp = temp->next;
        }
        return head;
    }
};
