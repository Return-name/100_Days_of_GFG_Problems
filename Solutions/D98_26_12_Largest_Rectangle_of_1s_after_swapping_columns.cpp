// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Returns area of the largest rectangle of 1's
	int maxArea(vector<bool> mat[], int r, int c) {
	    // code here
	    vector<vector<int>> v(r, vector<int>(c, 0));
	    for(int i = 0;i<r;i++)
	        for(int j = 0;j<c;j++)
	        {
	            v[i][j] = mat[i][j] == 1 ? 1 : 0;
	            if(i > 0)
	                if(v[i][j])
	                    v[i][j] += v[i-1][j];
	        }
	        
	   int ans = 0;
	   for(auto &u: v)
	   {
	       int lans = 0;
	       sort(u.begin(), u.end());
	       for(int i =0;i<c;i++)
	        lans = max(lans, u[i]*(c-i));
	       ans = max(ans, lans);
	   }
	   return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c, x;
        cin >> r >> c;
        vector<bool> mat[r];
        for (int i = 0; i < r; i++) {
            mat[i].assign(c, false);
            for (int j = 0; j < c; j++) {
                cin >> x;
                mat[i][j] = x;
            }
        }
        Solution ob;
        auto ans = ob.maxArea(mat, r, c);
        cout << ans << "\n";

    }
    return 0;
}
  // } Driver Code Ends
