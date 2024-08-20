//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node* root) {
    Node* temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* reverse(Node* head){
        if(!head || !head->next) return head;
        
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = curr->next;
        
        while(curr){
            forward = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
  
    Node *compute(Node *head) {
        if(!head || !head->next) return head;
        
        Node* temp = reverse(head);
        
        Node* prev = temp;
        Node* curr = temp->next;
        
        while(curr){
            if(curr->data<prev->data){
                prev->next = curr->next;
                curr = curr->next;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        
        head = reverse(temp);
        
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }
        Solution ob;
        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Node* result = ob.compute(head);
        print(result);
        cout << endl;
    }
}

// } Driver Code Ends
