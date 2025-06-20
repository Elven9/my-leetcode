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
    vector<Node *> ch;
    int v;

    Node()
    {
        ch = vector<Node *>(100, nullptr);
        v = -1;
    }
};

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        Node *root = new Node();
        vector<vector<string>> res;

        for (auto &s : strs)
        {
            vector<int> freq(26, 0);
            for (auto &c : s)
                freq[c - 'a']++;

            // search and add ( trie )
            Node *cur = root;
            for (int i = 0; i < 26; i++)
            {
                if (cur->ch[freq[i]] == nullptr)
                    cur->ch[freq[i]] = new Node();
                cur = cur->ch[freq[i]];
            }
            if (cur->v == -1)
            {
                cur->v = res.size();
                res.push_back(vector<string>());
            }
            res[cur->v].push_back(s);
        }

        return res;
    }
};

// sort by frequency .. ? 26 維會不會很久
//
// O(n^2) won't work
//
// using trie like structure
// construct frequency -> search and find
