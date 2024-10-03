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
    unordered_set<string> dict;
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](string &a, string &b)
             { return a.size() < b.size(); });

        vector<string> res;
        vector<int> visited(30, 0);
        for (auto &w : words)
        {
            if (dfs(w, 0, visited))
                res.push_back(w);
            for (int i = 0; i < 30; i++)
                visited[i] = 0;
            dict.insert(w);
        }

        return res;
    }

    bool dfs(string &word, int st, vector<int> &visited)
    {
        if (word.size() == st)
            return true;
        if (visited[st] != 0)
            return visited[st] == 1;
        for (int i = st; i < word.size(); i++)
        {
            if (dict.find(word.substr(st, i - st + 1)) != dict.end() && dfs(word, i + 1, visited))
            {
                visited[st] = 1;
                return true;
            }
        }
        visited[st] = 2;
        return false;
    }
};
