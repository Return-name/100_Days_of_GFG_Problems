// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int> arr(100001, 0);
        vector<int> v;
        int ans = 0;
        for(int i = 0;i<k;i++)
        {
            if(arr[A[i]] == 0)
                ans++;
            arr[A[i]]++;
        }
        v.push_back(ans);
        int l = 0;
        int r = k-1;
        for(;r<n;)
        {
            arr[A[l]]--;
            if(arr[A[l]] == 0)
                ans--;
            l++;
            r++;
            if(r == n)
                break;
            if(arr[A[r]] == 0)
                ans++;
            arr[A[r]]++;
            v.push_back(ans);
        }
        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
