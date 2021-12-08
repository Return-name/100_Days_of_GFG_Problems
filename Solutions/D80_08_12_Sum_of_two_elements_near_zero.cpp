// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            // your code here 
            sort(arr, arr+n);
            int ans = 1e9;
            int i=0, j=n-1,sum;
            while(i<j)
            {
                sum = arr[i] + arr[j];
                if(abs(sum) < abs(ans))
                    ans = sum;
                else if(abs(sum) == abs(ans) && sum > ans)
                    ans = sum;
                if(sum == 0)
                    break;
                else if(sum > 0)
                    j--;
                else
                    i++;
            }
            return ans;
        }
};

// { Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}  // } Driver Code Ends
