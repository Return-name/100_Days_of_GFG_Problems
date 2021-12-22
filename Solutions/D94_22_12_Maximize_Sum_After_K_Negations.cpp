// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a, a+n);
        long long int ans = 0;
        int i = 0;
        int j = 0;
        for(;i<n && j<k;i++,j++)
            if(a[i] <= 0)
                a[i] = -a[i];
            else
                break;
        //if(j == k)
            
        if(i == n)
        {
            i = n-1;
        }
        while(j<k)
        {
            a[i] = -a[i];
            j++;
        }
        //ans += a[i];
        for(i=0;i < n;i++)
            ans += a[i];
        return ans;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends
