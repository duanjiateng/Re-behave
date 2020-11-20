class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int zero = 0, no_zero = 0;
        while (zero < n && no_zero < n)
        {
            // 找到0
            while (zero < n && nums[zero] != 0)
                zero++;
            // 找到 non-0
            while (no_zero < n && nums[no_zero] == 0)
                no_zero++;

            // 交换
            if (zero < n && no_zero < n && zero < no_zero)
                swap(nums[zero], nums[no_zero]);

            // non-0指针向后挪
            no_zero++;
        }
    }
};