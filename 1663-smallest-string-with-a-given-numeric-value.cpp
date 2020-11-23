class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string res;
        for (int i = 0, s = 0; i < n; i++)
        {
            for (int j = 1; j <= 26; j++)
            {
                int last = k - s - j, m = k - i + 1;
                // 判断剩余的是否有解  m <= last <= m*26
                if (last >= m && last <= m * 26)
                {
                    res += 'a' + j - 1;
                    s += j;
                    break;
                }
            }
        }
        return res;
    }
};