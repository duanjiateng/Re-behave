class Solution
{
public:
    /*
    最大情况：
    第一列为1
    每一列 1的数量大于0的数量
    */
    int matrixScore(vector<vector<int>> &A)
    {
        int n = A.size(), m = A[0].size();
        // 处理行
        for (int i = 0; i < n; i++)
        {
            if (A[i][0] != 1)
            {
                for (int j = 0; j < m; j++)
                {
                    A[i][j] = 1 - A[i][j];
                }
            }
        }

        int res = n * (1 << (m - 1));

        // 处理列
        for (int j = 1; j < m; j++)
        {
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (A[i][j] == 1)
                    cnt++;
            }

            int k = max(cnt, n - cnt);

            res += k * (1 << (m - j - 1));
        }

        return res;
    }
};