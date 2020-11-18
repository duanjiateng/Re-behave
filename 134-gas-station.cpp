class Solution
{
public:
    /*
    暴力破解
    从每一个点出发，判断是否可以到这个点
    */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        for (int i = 0; i < n; i++)
        {
            // 起点
            int j = i;
            // 剩余值
            int remain = gas[i];
            // 判断能否到达当前点
            while (remain >= cost[j])
            {
                // 剩余值 要加上下一个点
                remain = remain - cost[j] + gas[(j + 1) % n];
                j = (j + 1) % n;

                // 返回起点
                if (j == i)
                    return i;
            }
        }
        return -1;
    }

    /*
    一次遍历
    找到最低点的下一个点  
    */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int sum = 0, min = 0, start = 0;
        for (int i = 0; i < n; i++)
        {
            sum += gas[i] - cost[i];
            if (sum < min)
            {
                start = i + 1;
                min = sum;
            }
        }

        return (sum < 0) ? -1 : start;
    }
};