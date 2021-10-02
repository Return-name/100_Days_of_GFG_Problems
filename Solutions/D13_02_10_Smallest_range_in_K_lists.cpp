// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        //code here
        map<int, vector<int>> arr;
      
        for(int i = 0;i<k;i++)
            for(int j = 0;j<n;j++)
                arr[KSortedArray[i][j]].push_back(i);
        
        vector<int> pos(k, -1e9);
        multiset<int> s;
        for(int i = 0;i<k;i++)
            s.insert(-1e9);
        
        pair<int,int> ans;
        int len=1e9;
        
        for(auto pp : arr)
        {
            auto i = pp.first;
            auto iv = pp.second;
            
            for(int j: iv)
            {
                int p = pos[j];
                s.erase(s.find(p));
                s.insert(i);
                pos[j] = i;
            }
            auto it = s.begin();
            if(*it != -1e9)
            {
                int local = i - (*it) + 1;
                if(local < len)
                {
                    len = local;
                    ans.first = *it;
                    ans.second = i;
                }
            }
            
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
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends
