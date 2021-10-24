// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        typedef vector<int> vi;

        class UnionFind {                                // OOP style
        private:
          vi p, rank, setSize;                           // vi p is the key part
          int numSets;
        public:
          UnionFind(int N) {
            p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
            rank.assign(N, 0);                           // optional speedup
            setSize.assign(N, 1);                        // optional feature
            numSets = N;                                 // optional feature
          }
        
          int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
          bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        
          int numDisjointSets() { return numSets; }      // optional
          int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional
        
          void unionSet(int i, int j) {
            if (isSameSet(i, j)) return;                 // i and j are in same set
            int x = findSet(i), y = findSet(j);          // find both rep items
            if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
            p[x] = y;                                    // set x under y
            if (rank[x] == rank[y]) ++rank[y];           // optional speedup
            setSize[y] += setSize[x];                    // combine set sizes at y
            --numSets;                                   // a union reduces numSets
          }
        };
        
        vector<pair<int, pair<int,int>>> v;
        for(int i = 0;i<V;i++)
        {
            for(int j = 0;j<adj[i].size();j++)
            {
                v.push_back( { adj[i][j][1], { i, adj[i][j][0]} } );
            }
        }
        sort(v.begin(), v.end());
        UnionFind UF(V);
        int ans = 0;
        for(auto p : v)
        {
            if(UF.numDisjointSets() == 1)
            {
                break;
            }
            if(!UF.isSameSet(p.second.first, p.second.second))
            {
                ans += p.first;
                UF.unionSet(p.second.first, p.second.second);
            }
        }
        return ans;
    }
};






// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
