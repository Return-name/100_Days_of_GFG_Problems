// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int dp[101][101];
        //for(int i = 0;i<201;i++)
            for(int j = 0;j<101;j++)
                for(int k = 0 ;k<101;k++)
                    dp[j][k] = 0;
        dp[0][0] = 1;
        //for(int i = 0;i<C.size();i++)
            for(int j = 0;j<=A.size();j++)
                for(int k = 0;k<=B.size();k++)
                {
                    if(dp[j][k] == 1)
                    {
                        if(j != A.size() && C[j+k] == A[j])
                            dp[j+1][k] = 1;
                        if(k != B.size() && C[j+k] == B[k])
                            dp[j][k+1] = 1;
                    }
                }
        
        return dp[A.size()][B.size()];
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends
