#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        vector<char> stk;

        for (auto &digit : num)
        {
            // 栈不为空，栈顶数字大于当前数字，k > 0
            while (stk.size() > 0 && stk.back() > digit && k)
            {
                stk.pop_back();
                k -= 1;
            }
            stk.push_back(digit);
        }

        for (; k > 0; k--)
            stk.pop_back();

        string ans = "";
        // 0 开头
        bool zeroStart = true;

        for (auto &digit : stk)
        {
            if (zeroStart && digit == '0')
                continue;
            zeroStart = false;
            ans += digit;
        }
        return ans == "" ? "0" : ans;
    }
};