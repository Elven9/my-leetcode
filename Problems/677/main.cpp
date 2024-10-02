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
    int val;
    Node *ch[26];
    Node()
    {
        for (int i = 0; i < 26; i++)
            ch[i] = nullptr;
        val = 0;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(string &word, int &val)
    {
        Node *cur = root;
        for (auto &w : word)
        {
            int idx = w - 'a';
            if (!cur->ch[idx])
                cur->ch[idx] = new Node();
            cur = cur->ch[idx];
        }
        cur->val = val;
    }

    int getScore(string &word)
    {
        Node *cur = root;
        for (auto &w : word)
        {
            int idx = w - 'a';
            if (!cur->ch[idx])
                return 0;
            cur = cur->ch[idx];
        }

        int res = 0;
        queue<Node *> q;
        q.push(cur);

        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            res += top->val;
            for (int i = 0; i < 26; i++)
                if (top->ch[i])
                    q.push(top->ch[i]);
        }

        return res;
    }
};

class MapSum
{
public:
    Trie *dict;
    MapSum()
    {
        dict = new Trie();
    }

    void insert(string key, int val)
    {
        dict->insert(key, val);
    }

    int sum(string prefix)
    {
        return dict->getScore(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
