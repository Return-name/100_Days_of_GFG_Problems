// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct et
{
	char value;
	et* left, *right;
	
	et(char x){
	    value = x;
	    left = right = NULL;
	}
};

bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '^')
		return true;
	return false;
}

void inorder(et *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}

et* constructTree(char []);

int main()
{   
    int t;
    cin>>t;
    while(t--){
    char postfix[25];
	cin>>postfix;
	et* r = constructTree(postfix);
	inorder(r);
	cout<<endl;
}
return 0;
}// } Driver Code Ends


/*struct et
{
	char value;
	et* left, *right;
};*/

//function to construct expression tree
et* constructTree(char p[])
{
    //code here
    stack<et*> s;
    et* root;
    for(int i = 0;p[i];i++)
    {
        if(p[i] >= 'a' && p[i] <= 'z')
        {
            et* e = new et(p[i]);
            e->left = e->right = NULL;
            s.push(e);
        }
        else
        {
            et* e = new et(p[i]);
            e->right = s.top();
            s.pop();
            e->left = s.top();
            s.pop();
            s.push(e);
        }
    }
    return s.top();
}

