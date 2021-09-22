// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{

    public:
    int repeatedStringMatch(string A, string B) 
    {
        // Your code goes here
        int ans = 1e9;
        for(int i = 0;i<A.size();i++)
        {
            if(A[i] == B[0])
            {
                int lans = 1;
                int j = i;
                int k = 0;
                while(k < B.size())
                {
                    //cout << "comparing j="<<j<<":"<<A[j] << " and k="<<k<<":" << B[k] << "\n";
                    if(A[j] != B[k])
                        break;
                    k++;
                    if(k > B.size()-1)
                    {
                        ans = min(ans, lans);
                        break;
                    }
                    j++;
                    if(j == A.size())
                    {
                        j = 0;
                        lans++;
                    }
                }
            }
        }
        if(ans == 1e9)
            return -1;
        else
            return ans;
        
    }
  
};

// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution obj;
        cout<<obj.repeatedStringMatch(A,B)<<"\n";
    }
    return 0;
}
  // } Driver Code Ends
