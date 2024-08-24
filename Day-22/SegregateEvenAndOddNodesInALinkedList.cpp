//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* divide(Node* head) {
        if(!head || !head->next) return head;
        
        Node* end = head;
        while(end->next!=NULL) end = end->next;
        
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = curr->next;
        Node* temp = end;
        
        
        while(curr!=end){
            forward = curr->next;
            if(curr->data%2!=0){
                temp->next = curr;
                curr->next = NULL;
                temp = temp->next;
                if(prev!=NULL){
                    prev->next = forward;
                }else{
                    head = forward;
                }
                curr = forward;
            }else{
                prev = curr;
                curr = forward;
            }
        }
        forward = curr->next;
        if(curr->data%2!=0 && forward!=NULL){
            temp->next = curr;
            curr->next = NULL;
            temp = temp->next;
            if(prev!=NULL){
                prev->next = forward;
            }else{
                head = forward;
            }
        }
        return head;
    }
    
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty())
            continue;

        int data = arr[0];
        int N = arr.size();
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < N; ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(head);
        printList(ans);
    }
    return 0;
}

// } Driver Code Ends
