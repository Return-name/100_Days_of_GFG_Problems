// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool find4Numbers(int A[], int n, int X);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, i, x;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin>>x;
        cout << find4Numbers(a, n, x) << endl;

    }
    return 0;
}// } Driver Code Ends


//User function Template for C++

bool find4Numbers(int arr[], int n, int X)  
{
    sort(arr, arr+n);
    for(int i = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            int l = j+1;
            int r = n-1;
            int rs = X - (arr[i] + arr[j]);
            while(l < r)
            {
                int cs = arr[l] + arr[r];
                if(cs == rs)
                    return true;
                else if(cs < rs)
                    l++;
                else
                    r--;
            }
        }
    }
    return false;
}
