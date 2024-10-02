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
    vector<Node *> childs;
    bool isEnd;

    Node()
    {
        isEnd = false;
        childs.resize(26, nullptr);
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

    void insert(string word)
    {
        Node *cur = root;
        for (auto &w : word)
        {
            if (!cur->childs[w - 'a'])
                cur->childs[w - 'a'] = new Node();
            cur = cur->childs[w - 'a'];
        }
        cur->isEnd = true;
    }

    bool search(string word)
    {
        Node *cur = root;
        for (auto &w : word)
        {
            if (!cur->childs[w - 'a'])
                return false;
            cur = cur->childs[w - 'a'];
        }
        return cur->isEnd;
    }

    bool startsWith(string prefix)
    {
        Node *cur = root;
        for (auto &w : prefix)
        {
            if (!cur->childs[w - 'a'])
                return false;
            cur = cur->childs[w - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
