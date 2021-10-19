// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], long long int n)
    {
        // Your code here
        vector<int> left(n);
        left[0] = 1;
        stack<pair<long long int, int>> s;
        s.push({ arr[0], 1});
        for(int i = 1;i<n;i++)
        {
            if(s.top().first < arr[i])
            {
                left[i] = 1;
                s.push({arr[i], 1});
            }
            else
            {
                int c = 1;
                while(!s.empty() && s.top().first >= arr[i])
                {
                    c += s.top().second;
                    s.pop();
                }
                left[i] = c;
                s.push({ arr[i], c});
            }
        }
        
        vector<int> right(n);
        right[n-1] = 1;
        
        while(!s.empty())
            s.pop();
            
        s.push({ arr[n-1], 1 });
        for(int i = n-2;i>=0;i--)
        {
            if(s.top().first < arr[i])
            {
                right[i] = 1;
                s.push({ arr[i], 1});
            }
            else
            {
                int c = 1;
                while(!s.empty() && s.top().first >= arr[i])
                {
                    c += s.top().second;
                    s.pop();
                }
                right[i] = c;
                s.push({ arr[i], c});
            }
        }
        
        long long int ans = 0;
        for(int i = 0;i<n;i++)
        {
            long long int ar = arr[i] * (left[i] + right[i] -1 );
            ans = max(ans, ar);
        }
        return ans;
        
     }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
