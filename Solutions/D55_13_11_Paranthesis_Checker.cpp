// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> s;
        for(int i = 0;i<x.size();i++)
        {
            int cont = 1;
            switch(x[i])
            {
                case '{':
                case '[':
                case '(':   s.push(x[i]);
                            break;
                case ')':   cont = (!s.empty() && s.top() == '(' ? s.pop(), 1 : 0);
                            break;
                case ']':   cont = (!s.empty() && s.top() == '[' ? s.pop(), 1 : 0);
                            break;
                case '}':   cont = (!s.empty() && s.top() == '{' ? s.pop(), 1 : 0);
                            break;
            }
            if(!cont)
                return false;
        }
        if(s.empty())
            return true;
        else
            return false;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
