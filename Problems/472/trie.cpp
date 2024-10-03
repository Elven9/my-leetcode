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

class Trie
{
public:
    Node *root;
    Trie() { root = new Node(); }
    void insert(string &word)
    {
        Node *cur = root;
        for (auto &w : word)
        {
            int idx = w - 'a';
            if (!cur->ch[idx])
                cur->ch[idx] = new Node();
            cur = cur->ch[idx];
        }
        cur->isEnd = true;
    }
};

class Solution
{
public:
    Trie *dict;
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](string &a, string &b)
             { return a.size() < b.size(); });
        dict = new Trie();

        vector<string> res;
        vector<int> visited(30, 0);
        for (auto &w : words)
        {
            if (dfs(w, 0, visited))
                res.push_back(w);
            for (int i = 0; i < 30; i++)
                visited[i] = 0;
            dict->insert(w);
        }

        return res;
    }

    bool dfs(string &word, int st, vector<int> &visited)
    {
        int n = word.size();
        if (st == n)
            return true;
        if (visited[st] != 0)
            return visited[st] == 1;

        Node *cur = dict->root;
        bool res = false;
        for (int i = st; i < n; i++)
        {
            int idx = word[i] - 'a';
            if (!cur->ch[idx])
                break;
            cur = cur->ch[idx];
            if (cur->isEnd && dfs(word, i + 1, visited))
            {
                res = true;
                break;
            }
        }

        visited[st] = res ? 1 : 2;
        return res;
    }
};
