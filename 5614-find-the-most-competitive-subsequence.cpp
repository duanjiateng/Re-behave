class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        int n = nums.size(), count = n - k;
        if (n == k)
            return nums;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            while (res.size() > 0 && nums[i] < res.back() && count > 0)
            {
                res.pop_back();
                count--;
            }
            res.push_back(nums[i]);
        }

        while (res.size() > k)
            res.pop_back();

        return res;
    }
};