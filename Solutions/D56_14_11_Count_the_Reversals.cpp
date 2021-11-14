// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string b)
{
    // your code here
    int ans = 0;
    stack<char> s;
    
    for(int i = 0;i<b.size();i++)
    {
        if(b[i] == '}')
        {
            if(!s.empty())
                s.pop();
            else
                s.push('{'),ans++;
        }
        else
        {
            s.push(b[i]);
        }
    }
    if(s.size() % 2 == 0)
        return s.size()/2+ans;

    else
        return -1;
}
