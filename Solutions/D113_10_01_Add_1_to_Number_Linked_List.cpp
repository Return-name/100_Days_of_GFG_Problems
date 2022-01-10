// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

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

class Solution
{
    public:
    Node* reverse_list(Node* A) {
        Node *h=A, *p = A, *next=A;
        next = h->next;
        h->next = NULL;
        while(next)
        {
            h = next->next;
            next->next = p;
            p = next;
            next = h;
        }
        return p;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head = reverse_list(head);
        Node *A = head;
        Node *B = new Node(1);
        
        Node* x = NULL, *y=NULL;
        int s=0, c=0;
        while(A && B)
        {
            s = A->data + B->data + c;
            if(!x)
                x = y = new Node(0);
            else
            {  
                y->next = new Node(0);
                y = y->next;
            }
            y->data = s%10;
            c = s/10;
            A = A->next;
            B = B->next;
        }
        while(A)
        {
            y->next = new Node(0);
            y = y->next;
            s = A->data + c;
            y->data = s%10;
            c = s/10;
            A = A->next;
        }
        while(B)
        {
            y->next = new Node(0);
            y = y->next;
            s = B->data + c;
            y->data = s%10;
            c = s/10;
            B = B->next;
        }
        while(c > 0)
        {
            y->next = new Node(0);
            y = y->next;
            y->data = c%10;
            c /= 10;
        }
        return reverse_list(x);
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends
