#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <functional>
#include <sstream>
#include <set>
#include <cctype>

using namespace std;

class Solution
{
public:
    unordered_map<int, int> root;
    int findCircleNum(vector<vector<int>> &graph)
    {
        int n = graph.size();

        for (int i = 0; i < n; i++)
            root[i] = i;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && graph[i][j] && find(i) != find(j))
                    merge(i, j);

        set<int> Set;
        for (int i = 0; i < n; i++)
            Set.insert(find(i));

        return Set.size();
    }

    int find(int idx)
    {
        if (root[idx] != idx)
            root[idx] = find(root[idx]);
        return root[idx];
    }

    void merge(int i, int j)
    {
        int ri = root[i], rj = root[j];
        root[ri] = rj;
    }
};
