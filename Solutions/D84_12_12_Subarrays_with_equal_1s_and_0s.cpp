// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        vector<int> S;
        S.push_back(0);
        int sum = 0;
        for(int i = 0;i<n;i++)
        {
            sum += arr[i];
            S.push_back(sum);
        }
        unordered_map<int,int> mp;
        mp[0] = 1;
        long long int ans = 0;
        for(int i = 2;i<S.size();i++)
        {
            ans += mp[2*S[i]-i];
            mp[2*S[i-1]-i+1]++;
        }
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
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends
