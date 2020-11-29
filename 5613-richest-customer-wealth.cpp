class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int res = 0;
        for (vector<int> &a : accounts)
        {
            int sum = 0;
            for (int &n : a)
            {
                sum += n;
            }
            res = max(res, sum);
        }
        return res;
    }
};