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
    vector<Node *> ch;
    Node()
    {
        isEnd = false;
        ch.resize(26, nullptr);
    }
};

class WordDictionary
{
public:
    Node *root;
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
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

    bool search(string word)
    {
        return _search(word, root);
    }
    bool _search(string &word, Node *r)
    {
        Node *cur = r;
        for (int i = 0; i < word.size(); i++)
        {
            char &w = word[i];
            if (w == '.')
            {
                string next = word.substr(i + 1, string::npos);
                for (int j = 0; j < 26; j++)
                    if (cur->ch[j] && _search(next, cur->ch[j]))
                        return true;
                return false;
            }
            int idx = w - 'a';
            if (!cur->ch[idx])
                return false;
            cur = cur->ch[idx];
        }
        return cur->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
