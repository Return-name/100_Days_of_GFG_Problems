// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        // Your code goes here
        int dir[4][2] = {
            0, 1,   // 0 - right
            0, -1,  // 1 - left
            -1, 0,  // 2 - up
            1, 0,   // 3 - down
        };
        const int inf = -2e9;
        int d = 0;
        int i = 0, j = 0;
        while(1)
        {
            if(k == 1)
                return a[i][j];
            a[i][j] = inf;
            if(d == 0)
            {
                if(j < m-1 && a[i][j+1] > inf)
                    j++,k--;
                else
                    d = 3;
            }
            else if(d == 1)
            {
                if(j > 0 && a[i][j-1] > inf)
                    j--,k--;
                else
                    d = 2;
            }
            else if(d == 2)
            {
                if(i > 0 && a[i-1][j] > inf)
                    i--,k--;
                else
                    d = 0;
            }
            else
            {
                if(i < n-1 && a[i+1][j] > inf)
                    i++,k--;
                else
                    d = 1;
            }
            
        }
        
    }

};

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}  // } Driver Code Ends
