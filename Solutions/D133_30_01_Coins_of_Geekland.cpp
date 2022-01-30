// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>> &mat,int N,int K){
        // Your code goes here
        for(int i = 0;i<N;i++)
            for(int j = 1;j<N;j++)
                mat[i][j] += mat[i][j-1];
        
        for(int i = 1;i<N;i++)
            for(int j = 0;j<N;j++)
                mat[i][j] += mat[i-1][j];
                
        int ans = 0;
        for(int i = K-1;i<N;i++)
        {
            for(int j = K-1;j<N;j++)
                {
                    auto cur = mat[i][j];
                    cur -= i - K >= 0 ? mat[i - K][j] : 0;
                    cur -= j - K >= 0 ? mat[i][j - K] : 0;
                    cur += min(i - K, j - K) >= 0 ? mat[i - K][j - K] : 0;
                    ans = max(ans, cur);
                }
        }
        return ans;
    }  
};

// { Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
    	int N;
        cin>>N;
        vector<vector<int>> mat(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>mat[i][j];
            }
        }
        
        int k;cin>>k;
        Solution obj;
        cout << obj.Maximum_Sum(mat,N,k)<<"\n";
    }
        
    return 0;
}
  // } Driver Code Ends
