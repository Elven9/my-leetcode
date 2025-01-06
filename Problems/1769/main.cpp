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
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();

        vector<int> prefix(n, 0);
        int cnt = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += cnt;
            prefix[i] = sum;
            cnt += (boxes[i] == '1');
        }

        vector<int> suffix(n, 0);
        sum = 0;
        cnt = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sum += cnt;
            suffix[i] = sum;
            cnt += (boxes[i] == '1');
        }

        vector<int> res(n, 0);
        for (int i = 0; i < n; i++)
            res[i] = prefix[i] + suffix[i];

        return res;
    }
};
