// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        auto it = s.find(".");
        if(it > s.size())
            it = s.size();
        reverse(s.begin(), s.begin()+it);
        it++;
        while(it > 0 && it < s.size())
        {
            auto it2 = s.find(".", it);
            if(it2 > s.size())
                it2 = s.size();
            auto it3 = it2;
            it3++;
            reverse(s.begin()+it, s.begin() + it2);
            it = it3;
        }
        
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends
