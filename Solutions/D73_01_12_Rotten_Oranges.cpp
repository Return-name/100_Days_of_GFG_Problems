// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int step[505][505];
        queue<pair<int,int>> q;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 0)
                    step[i][j] = 0;
                else if(grid[i][j] == 1)
                    step[i][j] = 1e9;
                else
                {
                    step[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            if(x != 0 && grid[x-1][y] == 1 && step[x-1][y] > step[x][y]+1)
                step[x-1][y] = step[x][y]+1, q.push({x-1, y});
            if(x != n-1 && grid[x+1][y] == 1 && step[x+1][y] > step[x][y]+1)
                step[x+1][y] = step[x][y]+1, q.push({x+1, y});
            if(y != 0 && grid[x][y-1] == 1 && step[x][y-1] > step[x][y]+1)
                step[x][y-1] = step[x][y]+1, q.push({x, y-1});
            if(y != m-1 && grid[x][y+1] == 1 && step[x][y+1] > step[x][y]+1)
                step[x][y+1] = step[x][y]+1, q.push({x, y+1});
        }
             
        int ans = -1;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                ans = max(ans, step[i][j]);
        if(ans == 1e9)
            return -1;
        else
            return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
