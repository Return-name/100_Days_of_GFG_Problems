// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    
    
    int bfs(auto start, auto dest, int n)
    {
        //int n = 8;
        int dir[8][2] = {
         -2,  1,
         -1,  2,
          1,  2,
          2,  1,
          2, -1,
          1, -2, 
         -1, -2,
         -2, -1,
    	};
      bool vis[n][n];
      for(int i = 0;i<n;i++)
	        for(int j = 0;j<n;j++)
	            vis[i][j] = false;
      
        queue<pair<pair<int,int>, int>> q;
        q.push({start, 0});
        vis[start.first][start.second] = true;
    
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            auto loc = top.first;
            auto len = top.second;
            
            if(loc == dest)
                return len;
            
            int a, b;
            for(int i = 0;i<8;i++)
            {
                a = loc.first + dir[i][0];
                b = loc.second + dir[i][1];
                
                if(a < 0 || b < 0)
                    continue;
                    
                if(a >= n || b >= n)
                    continue;
                
                if(vis[a][b])
                    continue;
                    
                q.push({{a, b}, len+1});
                vis[a][b] = true;
            }
        }
        
        return -1;
    }
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&k, vector<int>&t, int N)
	{
	    // Code here
	    int n = N;
	    
	    pair<int,int> start, dest;
	    
	            
	   start.second = k[0]-1;
	   start.first = n - k[1] ;
	   
	   dest.second = t[0]-1;
	   dest.first = n- t[1] ;
	   
	   return bfs(start, dest, n);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
