class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        unordered_map<int, int> map;
        for (int &a : A)
        {
            for (int &b : B)
            {
                ++map[a + b];
            }
        }

        int ans = 0;

        for (int &c : C)
        {
            for (int &d : D)
            {
                if (map[-c - d])
                {
                    ans += map[-c - d];
                }
            }
        }

        return ans;
    }
};