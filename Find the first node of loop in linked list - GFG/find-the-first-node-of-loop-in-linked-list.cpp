//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
//User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/

class Solution {
public:
    // using Floyd's cycle-finding algorithm
    int findFirstNode(Node* head) {
        Node* slow = head;
        Node* fast = head;
        // Iterate through the linked list using two pointers, slow and fast
        // Move the slow pointer one step at a time and the fast pointer two steps at a time
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            // If the slow and fast pointers meet, it means there is a loop in the linked list
            if (slow == fast) {
                slow = head;
                // Iterate through the linked list again, this time moving both pointers one step at a time
                // The first time the slow and fast pointers meet again, the slow pointer will be at the first node of the loop
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow->data;
            }
        }
        // If there is no loop in the linked list, return -1
        return -1;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        int ans = ob.findFirstNode(head);
        cout<<ans<<"\n";
    }
	return 0;
}
// } Driver Code Ends