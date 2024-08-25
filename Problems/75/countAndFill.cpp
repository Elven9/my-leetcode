#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // Naive solution: Sorting, O(nlogn)
        // Thinking about one-pass solution: O(n), O(1)
        // Two moving pointers to record last 0 and 2 insertion place

        int lastzero = 0, lasttwo = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                lastzero++;
            else if (nums[i] == 2)
                lasttwo--;
        }

        // fill zero
        for (int i = 0; i < lastzero; i++)
            nums[i] = 0;
        // fill one
        while (lastzero <= lasttwo)
            nums[lastzero++] = 1;

        for (int i = lasttwo + 1; i < nums.size(); i++)
            nums[i] = 2;
    }
};

int main()
{
    Solution sol;
    vector<int> payload{2, 0, 2, 1, 1, 0};

    sol.sortColors(payload);

    for (int i = 0; i < payload.size(); i++)
    {
        cout << payload[i] << endl;
    }

    return 0;
}
