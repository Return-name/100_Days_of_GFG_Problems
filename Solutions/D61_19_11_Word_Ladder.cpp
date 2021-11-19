// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    bool check(string &a, string &b)
    {
        int diff = 0;
        for(int i = 0;i<a.size();i++)
        {
            if(a[i] != b[i])
                diff++;
            if(diff > 1)
                return false;
        }
        return true;
    }
 
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& A) {
        // code here
        //vector<string> mp;
        int sp = -1;
        int tp = -1;
        for(int i = 0;i<A.size();i++)
        {
            if(A[i] == beginWord)
                sp = i;
            if(A[i] == endWord)
                tp = i;
        }
        
        unordered_set<string> vis;
        vector<vector<string>> ans;
        queue<vector<string>> q;
        q.push({beginWord});
        unordered_set<string> st(A.begin(), A.end());
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                auto cp = q.front();
                q.pop();
                
                string l = cp.back();
                for(int i  = 0;i<l.size();i++)
                {
                    auto t = l;
                    for(char ch = 'a';ch<='z';ch++)
                    {
                        t[i] = ch;
                        if(st.find(t) != st.end())
                        {
                            auto np = cp;
                            np.push_back(t);
                            vis.insert(t);
                            if(t == endWord)
                                ans.push_back(np);
                            else
                                q.push(np);
                        }
                    }
                }
                
            }
            for(auto & string: vis)
                    st.erase(string);
        }
        return ans;
        /*
        if(sp == -1)
            A.push_back(beginWord), sp = A.size()-1;
        
        vector<int> edges[105];
        for(int i = 0;i<A.size();i++)
        {
            for(int j = i+1;j<A.size();j++)
            {
                if(check(A[i], A[j]))
                {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        
        queue<pair<int,vector<string>> > q;
        q.insert({sp, {A[sp]}});
        vector<int> vis(15, 0);
        vis[sp] = 1;
        
        vector<vector<string>> ans;
        while(!q.empty())
        {
            auto p = q.top();
            q.pop();
            if(p.first == tp)
            {
                ans.push_back(q.second);
                continue;
            }
            
            for(int v : edges[p.first])
            {
                if(!vis[v])
                {
                    p.second.push_back()
                }
            }
        }
        */
        
    }
};

// { Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}  // } Driver Code Ends
