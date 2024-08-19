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

using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, bool> visited;

        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end())
            wordList.push_back(beginWord);

        for (auto &a : wordList)
            for (auto &b : wordList)
                if (wordDiff(a, b) == 1)
                    graph[a].push_back(b);

        queue<string> q;
        int res = 1;
        q.push(beginWord);
        q.push("#");

        while (!q.empty())
        {
            string next = q.front();
            q.pop();
            if (visited[next])
                continue;
            if (next == "#")
            {
                res++;
                if (!q.empty())
                    q.push("#");
                continue;
            }
            if (next == endWord)
                return res;
            for (auto &w : graph[next])
                q.push(w);
            visited[next] = true;
        }

        return 0;
    }

    int wordDiff(string &a, string &b)
    {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res += a[i] == b[i] ? 0 : 1;

        return res;
    }
};
