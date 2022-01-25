// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool check(int bs, int n, int k, int arr[])
    {
        int bc = 1;
        int bsum = 0;
        
        for(int i = 0;i<n;i++)
        {
            if(bsum + arr[i] <= bs)
                bsum += arr[i];
            else
            {
                bc++;
                if(bc > k)
                    return false;
                if(arr[i] > bs)
                    return false;
                bsum = arr[i];
            }
        }
        return true;
    }
  
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int l = 1, r=1e9;
        int mid;
        
        while(l <= r)
        {
            mid = (l+r)/2;
            
            int am = check(mid, N, D, arr);
            int amp = check(mid-1, N, D, arr);
            
            if(am)
            {
                if(amp)
                    r = mid;
                else
                    break;
                    
            }
            else
                l = mid+1;
        }
        return mid;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends
