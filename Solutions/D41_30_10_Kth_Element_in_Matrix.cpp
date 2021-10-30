// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  set<pair<int, pair<int,int>>> s;
  int c = 0;
  s.insert({mat[0][0], {0, 0}});
  
  while(1)
  {
      auto t = *(s.begin());
      s.erase(s.begin());
      
      c++;
      if(c == k)
        return t.first;
        
      int x = t.second.first;
      int y = t.second.second;
      
      if(x != n-1)
      {
          s.insert({ mat[x+1][y], {x+1, y}});
      }
      if(y != n-1)
        s.insert({ mat[x][y+1], {x, y+1}});
  }
  
}

