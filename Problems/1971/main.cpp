#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int src, int dst)
    {
        // dfs
        // visited node pruning
        // adjacency matrix
        unordered_map<int, vector<int>> adjMat;
        for (auto it = edges.begin(); it != edges.end(); it++)
        {
            adjMat[(*it)[0]].push_back((*it)[1]);
            adjMat[(*it)[1]].push_back((*it)[0]);
        }
        vector<bool> visited(n, false);
        stack<int> st;
        st.push(src);
        while (!st.empty())
        {
            int node = st.top();
            cout << node << endl;
            if (node == dst)
            {
                return true;
            }
            visited[node] = true;
            st.pop();
            for (int i = 0; i < adjMat[node].size(); i++)
            {
                if (!visited[adjMat[node][i]])
                {
                    st.push(adjMat[node][i]);
                }
            }
        }
        return false;
    }
};
