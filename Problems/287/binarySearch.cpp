#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // Naive solution 1: O(n), O(n) with hashtable
        // Naive solution 2: O(nlogn), O(1), sort and scan, array'd been modified.
        // Naive solution 3: O(n^2), O(1), scan [1,n] and check count

        // Let's Try Binary Search Solution
        // O(nlogn), O(1)

        int st = 1, ed = nums.size();

        while (st < ed)
        {
            int cnt = 0, mcnt = 0;
            int mid = (st + ed) / 2;

            for (int n : nums)
            {
                if (n == mid)
                    mcnt++;
                else if (n < mid)
                    cnt++;
            }

            cout << "[" << st << ", " << ed << ")"
                 << ": cnt: " << cnt << " mcnt: " << mcnt << endl;

            if (mcnt > 1)
                return mid;

            if (cnt <= mid - 1)
            {
                st = mid + 1;
            }
            else
            {
                ed = mid;
            }
        }

        return 0;
    }
};
