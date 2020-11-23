class Solution
{
public:
    int waysToMakeFair(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> s1(n + 1), s2(n + 1);

        // 求奇数前缀和  偶数前缀和
        for (int i = 1; i <= n; i++)
        {
            s1[i] = s1[i - 1];
            s2[i] = s2[i - 1];
            if (i % 2 == 0)
                s1[i] += nums[i - 1];
            else
                s2[i] += nums[i - 1];
        }

        int res = 0;
        // 枚举删除每个位置
        for (int i = 1; i <= n; i++)
        {
            int odd = s2[i - 1] + s1[n] - s1[i + 1];
            int even = s1[i - 1] + s2[n] - s2[i + 1];

            if (odd == even)
                res++;
        }
        return res;
    }
};