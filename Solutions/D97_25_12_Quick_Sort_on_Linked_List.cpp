// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */
pair<node*, node*> qs(node *h)
{
    node *fs, *fe, *ss, *se;
    fs = fe = ss = se = NULL;
    int val = h->data;
    node *p = h;
    while(p->next)
    {
        if(p->next->data < val)
        {
            if(fs == NULL)
            {
                fs = fe = p->next;
                p->next = p->next->next;
                fs->next = NULL;
            }
            else
            {
                fe->next = p->next;
                p->next = p->next->next;
                fe = fe->next;
                fe->next = NULL;
            }
        }
        else
            p = p->next;
    }
    //fe->next = h;
    pair<node*, node*> r1, r2;
    if(fs && fs->next != h)
    {
        r1 = qs(fs);
        r1.second->next = h;
    }
    else if(!fs)
        r1.first = h;
    else if(fs->next == NULL)
    {
        fs->next = h;
        r1.first = fs;
    }
    
    if(h->next && h->next->next)
    {
        r2 = qs(h->next);
        h->next = r2.first;
    }
    else if(!h->next)
        r2.second = h;
    else
        r2.second = h->next;
    return {r1.first, r2.second};
}


//you have to complete this function
void quickSort(struct node **headRef) {
    node *head = *headRef;
    auto p = qs(head);
    *headRef = p.first;
}
