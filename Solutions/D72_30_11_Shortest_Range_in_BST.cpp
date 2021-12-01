// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



 // } Driver Code Ends
// User function Template for C++

class Solution{
    
    public:
    void dfs(Node *n, int l, vector<pair<int,int>> &level, int &ml)
    {
        ml = max(ml, l);
        level.push_back({n->data, l});
        if(n->left)
            dfs(n->left, l+1, level, ml);
        if(n->right)
            dfs(n->right, l+1, level, ml);
    }
    
    pair<int, int> shortestRange(Node *root) {
        vector<pair<int,int>> level;
        
        int ml=0;
        dfs(root, 0, level, ml);
        sort(level.begin(), level.end());
        
        ml++;
        vector<int> done(ml, -1);
        multiset<int> ms;
        for(int i = 0;i<ml;i++)
            ms.insert(-1);
        
        pair<int,int> ans;
        ans.first = 0;
        ans.second = 1e9;
        
        for(int i = 0;i<level.size();i++)
        {
            ms.erase(ms.find(done[level[i].second]));
            done[level[i].second] = level[i].first;
            ms.insert(level[i].first);
            
            if((*ms.begin()) != -1)
            {
                int cl = (*ms.rbegin()) - (*ms.begin());
                if(cl < ans.second-ans.first)
                {
                    ans.first = (*ms.begin());
                    ans.second = (*ms.rbegin());
                }
                
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        pair<int, int> range = obj.shortestRange(root);
        cout << range.first << " " << range.second << "\n";
    }

    return 0;
}  // } Driver Code Ends
