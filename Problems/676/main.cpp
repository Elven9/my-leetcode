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
    Node *ch[26];
    Node()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            ch[i] = nullptr;
    }
};

class MagicDictionary
{
public:
    Node *root;
    MagicDictionary()
    {
        root = new Node();
    }

    void buildDict(vector<string> D)
    {
        for (auto &w : D)
        {
            Node *cur = root;
            for (auto &c : w)
            {
                int idx = c - 'a';
                if (!cur->ch[idx])
                    cur->ch[idx] = new Node();
                cur = cur->ch[idx];
            }
            cur->isEnd = true;
        }
    }

    bool search(string word)
    {
        // dfs search
        unordered_map<string, bool> visited;
        return dfs(word, 0, root, false, visited);
    }
    bool dfs(string &word, int st, Node *r, bool hasModified, unordered_map<string, bool> &visited)
    {
        // string key = to_string(st)+"-"+to_string(hasModified);
        // if (visited.find(key) != visited.end()) return visited[key];

        int idx = word[st] - 'a';
        // pruning
        if (!r->ch[idx] && hasModified)
        {
            // visited[key]=false;
            return false;
        }

        if (st == word.size() - 1)
        {
            bool res = false;
            if (hasModified)
            {
                res = r->ch[idx]->isEnd;
            }
            else
            {
                for (int i = 0; i < 26; i++)
                {
                    if (i != idx && r->ch[i] && r->ch[i]->isEnd)
                    {
                        res = true;
                        break;
                    }
                }
            }
            // visited[key]=res;
            return res;
        }

        for (int i = 0; i < 26; i++)
        {
            if (!r->ch[i])
                continue;
            if (dfs(word, st + 1, r->ch[i], hasModified || (idx != i), visited))
            {
                // visited[key]=true;
                return true;
            }
        }
        // visited[key]=false;
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
