class Solution
{
public:
    /*
    模拟题
    */
    string sortString(string s)
    {
        vector<int> nums(26);
        // 统计每个字符的数量
        for (auto &ch : s)
        {
            nums[ch - 'a']++;
        }

        string res;

        while (res.size() < s.size())
        {
            // 找小的
            for (int i = 0; i < 26; i++)
            {
                if (nums[i])
                {
                    res += ('a' + i);
                    nums[i]--;
                }
            }

            // 找大的
            for (int i = 25; i >= 0; i++)
            {
                if (nums[i])
                {
                    res += ('a' + i);
                    nums[i]--;
                }
            }
        }

        return res;
    }
};