// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int ans = 0;
        int i = 0;
        while(1)
        {
            //cout << i << " ";
            if(i == n-1)
                return ans;
            int next = i;
            int nd = 0;
            if(i+arr[i] >= n-1)
                    return ans+1;
            for(int j = 0;j<=arr[i] && i+j<n;j++)
            {
                
                if(i+j+arr[i+j] > nd)
                {
                    nd = i+j+arr[i+j];
                    next = i+j;//arr[i+j];
                }
            }
            if(next == i)
                return -1;
            i = next;
            ans++;
        }
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
