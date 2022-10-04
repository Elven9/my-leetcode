#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        // Bruteforce Naive solution: Scan String, Check Anagram -> O(s*p)
        // Space O(letter)
        // Scan check with counter, witch reduce time complexity from O(s*p) to O(s)
        int table[26] = {0}, cnt = p.size();
        for (int i = 0; i < p.size(); i++)
        {
            table[p[i] - 'a']++;
        }

        vector<int> res;
        // Edge Case
        if (p.size() > s.size())
            return res;

        int ps = p.size(), ss = s.size(), ed = 0;
        // Init
        while (ed < ps)
        {
            if (table[s[ed] - 'a'] > 0)
            {
                cnt--;
            }
            table[s[ed++] - 'a'] -= 1;
        }
        if (cnt == 0)
            res.push_back(0);

        while (ed < ss)
        {
            table[s[ed - ps] - 'a']++;
            if (table[s[ed - ps] - 'a'] > 0)
                cnt++;
            table[s[ed] - 'a']--;
            if (table[s[ed] - 'a'] >= 0)
                cnt--;

            if (cnt == 0)
                res.push_back(ed - ps + 1);
            ed++;
        }
        return res;
    }
};
