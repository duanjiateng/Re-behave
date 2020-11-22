class Solution
{
public:
    /*
    求合并区间后的区间个数
    1.先排序
    2.合并区间
    */
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
            return 0;
        // sort 按照右边界大小排序
        sort(points.begin(), points.end(), [](const vector<int> &u, const vector<int> &v) {
            return u[1] < v[1];
        });

        int cnt = 1, right = points[0][1];

        for (int i = 1; i < points.size(); i++)
        {
            // 不能合并区间，结果++
            if (right < points[i][0])
            {
                cnt++;
                right = points[i][1];
            }
        }

        return cnt;
    }
};