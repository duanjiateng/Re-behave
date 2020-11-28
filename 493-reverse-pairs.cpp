class Solution
{
public:
    /*
    分解-> 求解 -> 合并
    分解子问题：
    假设数组A分成A1和A2
    A的翻转对数量 = A1的翻转对数量 + A2的翻转对数量 + 跨越A1、A2的翻转对数量
    f(A) = f(A1) + f(A2) + f(A1, A2)
    那对于A1
    f(A1) = f(A11) + f(A12) + f(A11, A12)
    可以一直分割，直到数组剩余一个数，结果为0
    
    求解时：
    实际上就是对“跨越部分求解”
    问题转换为：寻找i在数组A1，j在数组A2，有多少翻转对
    数组无序，则需要O(n^2)
    数组有序，则需要O(n).
        双指针
        当A1[i]>2*A2[j],则i后的所有元素都符合题意，更新答案j++
        否则，i++
    
    合并数组：
        当A1和A2合并后，可以向上解决更大的数组
    */

    /*
    * 找翻转对
    * */
    int findReversePairs(vector<int> &nums, int &left, int &right)
    {
        int mid = left + (right - left) / 2;
        int res = 0, i = left, j = mid + 1;
        while (i <= mid && j <= right)
        {
            if ((long)nums[i] > 2 * (long)nums[j])
            {
                res += (mid + 1) - i;
                j++;
            }
            else
            {
                i++;
            }
        }
        return res;
    }

    /*
    * 归并排序，合并结果
    * */
    int mergeSort(vector<int> &nums, int nums_sorted[], int left, int right)
    {
        if (left >= right)
            return 0;
        int mid = left + (right - left) / 2;
        int res = mergeSort(nums, nums_sorted, left, mid) +
                  mergeSort(nums, nums_sorted, mid + 1, right) +
                  findReversePairs(nums, left, right);

        // 合并两个数组
        int i = left, j = mid + 1, idx = left;
        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
            {
                nums_sorted[idx++] = nums[i++];
            }
            else
            {
                nums_sorted[idx++] = nums[j++];
            }
        }
        // i 有剩余
        while (i <= mid)
            nums_sorted[idx++] = nums[i++];
        while (j <= right)
            nums_sorted[idx++] = nums[j++];

        // 更新原数组
        for (int idx = left; idx <= right; idx++)
            nums[idx] = nums_sorted[idx];
        return res;
    }
    int reversePairs(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        // 辅助数组
        int nums_sorted[nums.size()];
        memset(nums_sorted, 0, sizeof(nums_sorted));
        return mergeSort(nums, nums_sorted, 0, nums.size() - 1);
    }
};