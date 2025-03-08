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

class ProductOfNumbers
{
public:
    vector<int> buf;
    int last_zero = -1;
    ProductOfNumbers()
    {
        buf.push_back(1);
    }

    void add(int num)
    {
        if (num == 0)
        {
            last_zero = buf.size();
            buf.push_back(1);
        }
        else
        {
            buf.push_back(buf.back() * num);
        }
        cout << "buf back; " << buf.back() << endl;
    }

    int getProduct(int k)
    {
        if ((int)(buf.size() - k) <= last_zero)
        {
            return 0;
        }
        return buf.back() / buf[buf.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
