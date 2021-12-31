// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string exp)
    {
            // Your code here
            stack<int> s;
	    for(int i = 0;i<exp.size();i++)
	    {
		if(exp[i] >= '0' && exp[i] <= '9')
		    s.push(exp[i] - 48);
		else
		{
		    int a = s.top(); s.pop();
		    int b = s.top(); s.pop();
		    int c;
		    if(exp[i] == '+')
			c = a + b;
		    else if(exp[i] == '-')
			c = b-a;
		    else if(exp[i] == '*')
			c = b * a;
		    else 
			c = b / a;
		    s.push(c);
		}
	    }
    	    return s.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
