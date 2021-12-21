// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int ans(string &A, string &B, string &C, int i, int j, int k, int dp[25][25][25])
{
    if(i < 0 || j < 0 || k < 0)
        return 0;
        
    if(dp[i][j][k] > -1)
        return dp[i][j][k];
        
    if(A[i] == B[j] && B[j] == C[k])
        return dp[i][j][k] = (ans(A, B, C, i-1, j-1, k-1, dp) + 1);
    
    int mx = -1;
    mx = max(mx, ans(A, B, C, i-1, j-1, k, dp));
    mx = max(mx, ans(A, B, C, i, j-1, k-1, dp));
    mx = max(mx, ans(A, B, C, i-1, j, k-1, dp));
    mx = max(mx, ans(A, B, C, i-1, j, k, dp));
    mx = max(mx, ans(A, B, C, i, j-1, k, dp));
    mx = max(mx, ans(A, B, C, i, j, k-1, dp));
    
    dp[i][j][k] = mx;
    return mx;
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here

    int dp[25][25][25];
    for(int i = 0;i<=n1;i++)
        for(int j = 0;j<=n2;j++)
            for(int k = 0;k<=n3;k++)
                dp[i][j][k] = -1;
    
    
                
    return ans(A, B, C, n1-1, n2-1, n3-1, dp);
}
