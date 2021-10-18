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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        
        Node *even=NULL, *odd=NULL, *se = NULL, *so=NULL;
        
        while(head != NULL)
        {
            if(head->data % 2 == 0)
            {
                if(se == NULL)
                {
                    se = head;
                    even = head;
                }
                else
                {
                    even->next = head;
                    even = head;
                }
            }
            else
            {
                if(odd == NULL)
                {
                    so = head;
                    odd = head;
                }
                else
                {
                    odd->next = head;
                    odd = head;
                }
            }
            head = head->next;
        }
        if(odd) odd->next = NULL;
        if(se == NULL)
            return so;
        even->next=  so;
        return se;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends
