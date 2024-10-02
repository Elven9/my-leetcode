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
        for (int i = 0; i < 26; i++)
            ch[i] = nullptr;
        isEnd = false;
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

    string getSmallestPrefix(string &word)
    {
        Node *cur = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!cur->ch[word[i] - 'a'])
                return "";
            cur = cur->ch[word[i] - 'a'];

            if (cur->isEnd)
                return word.substr(0, i + 1);
        }
        return "";
    }
};

class Solution
{
public:
    string replaceWords(vector<string> &D, string S)
    {
        Trie *dict = new Trie();
        for (auto &s : D)
            dict->insert(s);

        int i = 0;
        string res;
        while (true)
        {
            int next = S.find(' ', i);
            string word = S.substr(i, next - i);

            string root = dict->getSmallestPrefix(word);
            if (root == "")
                res.append(word);
            else
                res.append(root);
            res.push_back(' ');
            if (next == string::npos)
                break;
            i = next + 1;
        }

        res.pop_back();
        return res;
    }
};
