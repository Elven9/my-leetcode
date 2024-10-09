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
    int idx;
    Node *ch[27];
    Node()
    {
        idx = -1;
        for (int i = 0; i < 27; i++)
            ch[i] = nullptr;
    }
};

class WordFilter
{
public:
    Node *root;
    WordFilter(vector<string> &words)
    {
        root = new Node();
        root->ch[26] = new Node();

        for (int i = 0; i < words.size(); i++)
        {
            string &w = words[i];

            Node *cur = root;
            for (int j = w.size() - 1; j >= 0; j--)
            {
                int idx = w[j] - 'a';
                if (!cur->ch[idx])
                    cur->ch[idx] = new Node();
                cur = cur->ch[idx];

                if (!cur->ch[26])
                    cur->ch[26] = new Node();
                _insert(w, i, cur->ch[26]);
            }
        }
    }

    void _insert(string &w, int index, Node *r)
    {
        Node *cur = r;
        for (auto &c : w)
        {
            int idx = c - 'a';
            if (!cur->ch[idx])
                cur->ch[idx] = new Node();
            cur = cur->ch[idx];
        }
        cur->idx = index;
    }

    int f(string pref, string suff)
    {
        Node *cur = root;
        for (int i = suff.size() - 1; i >= 0; i--)
        {
            int idx = suff[i] - 'a';
            if (!cur->ch[idx])
                return -1;
            cur = cur->ch[idx];
        }
        cur = cur->ch[26];
        for (auto &c : pref)
        {
            int idx = c - 'a';
            if (!cur->ch[idx])
                return -1;
            cur = cur->ch[idx];
        }
        return _findLargestIdx(cur);
    }

    int _findLargestIdx(Node *r)
    {
        int res = -1;
        queue<Node *> q;
        q.push(r);

        while (!q.empty())
        {
            auto f = q.front();
            q.pop();
            res = max(res, f->idx);
            for (int i = 0; i < 26; i++)
                if (f->ch[i])
                    q.push(f->ch[i]);
        }

        return res;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
