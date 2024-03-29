// { Driver Code Starts
// CPP program to find maximum sum
// by selecting a element from n arrays
#include<bits/stdc++.h>

using namespace std;

// To calculate maximum sum by
// selecting element from each array
int maximumSum( int n,int m, vector<vector<int>> &a);



// Driver program to test maximumSum
int main() {
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vector<int>> arr(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            cin>>arr[i][j];
            
        cout << maximumSum(n,m,arr)<<endl;
    
    }
    return 0;

}
// } Driver Code Ends


int maximumSum( int n,int m, vector<vector<int>> &a) {
    // Complete the function
    int ans = a[n-1][0];
    for(int i = 1;i<m;i++)
        ans = max(ans, a[n-1][i]);
    
    int s = ans;
    for(int i = n-2;i>=0;i--)
    {
        int s2 = -1e9;
        for(int j=  0;j<m;j++)
        {
            if(a[i][j] < s)
                s2 = max(s2, a[i][j]);
                
        }
        if(s2 == -1e9)
            return 0;
        ans += s2;
        s = s2;
    }
    return ans;
}
