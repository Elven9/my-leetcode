#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        // O(n), O(1) greedy solution
        int endIdx[26];
        for (int i = 0; i < 26; i++)
            endIdx[i] = -1;

        for (int i = 0; i < s.size(); i++)
            endIdx[s[i] - 'a'] = i;

        // Scan another time to record partition
        vector<int> res;
        int st = -1, ed = 0, pted = -1;
        for (; ed < s.size(); ed++)
        {
            if (endIdx[s[ed] - 'a'] > pted)
            {
                pted = endIdx[s[ed] - 'a'];
            }
            if (ed == pted)
            {
                res.push_back(ed - st);
                st = ed;
            }
        }
        return res;
    }

    vector<int> partitionLabels_2Slow(string s)
    {
        // Naive solution: O(nlogn), O(1)
        // Scan and Merge Interval
        vector<vector<int>> intervals;
        for (int i = 0; i < 26; i++)
            intervals.push_back(vector<int>{-1, -1});

        // Scan String for Interval
        for (int i = 0; i < s.size(); i++)
        {
            int c = s[i] - 'a';
            if (intervals[c][0] == -1)
                intervals[c][0] = i;
            intervals[c][1] = i;
        }

        // Debug
        for (int i = 0; i < 26; i++)
        {
            cout << char(i + 'a') << ": " << setw(4) << intervals[i][0] << setw(4) << intervals[i][1] << endl;
        }

        sort(intervals.begin(), intervals.end());

        // Merging Intervals
        vector<int> res;
        int is = 0, ie = 0;

        for (int i = 0; i < 26; i++)
        {
            if (intervals[i][0] == -1)
                continue;
            if (intervals[i][0] > ie)
            {
                res.push_back(ie - is + 1);
                is = intervals[i][0];
                ie = intervals[i][1];
            }
            else if (intervals[i][1] > ie)
            {
                ie = intervals[i][1];
            }
        }
        res.push_back(ie - is + 1);

        return res;
    }
};
