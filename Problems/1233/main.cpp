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

struct Node
{
    bool isEnd;
    unordered_map<string, Node *> childs;
    Node()
    {
        isEnd = false;
    }

    Node *insert(string s)
    {
        if (childs.find(s) == childs.end())
            childs[s] = new Node();
        return childs[s];
    }
};

class Solution
{
public:
    Node *dict;
    vector<string> res;
    vector<string> removeSubfolders(vector<string> &folder)
    {
        dict = new Node();

        for (auto &s : folder)
        {
            int i = 1;
            Node *cur = dict;
            while (i != string::npos)
            {
                int j = s.find('/', i);
                Node *next = cur->insert(s.substr(i, j - i));
                cur = next;
                i = j;
                if (i != string::npos)
                    i++;
            }
            cur->isEnd = true;
        }
        dfs(dict, "");
        return res;
    }

    void dfs(Node *root, string cur)
    {
        if (!root)
            return;

        if (root->isEnd)
        {
            res.push_back(cur);
            return;
        }

        for (auto &[k, v] : root->childs)
        {
            dfs(v, cur + "/" + k);
        }
    }
};
