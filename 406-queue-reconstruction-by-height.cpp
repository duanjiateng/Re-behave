#include <vector>
#include <algorithm>
using namespace std;

/*
先排序，身高从大到小，身高相同人数从小到大
后插入，按照当前人前面比其的人数进行插入
*/

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        // 排序
        sort(people.begin(), people.end(), [](const vector<int> &v, const vector<int> &u) {
            return v[0] > u[0] || (v[0] == u[0] && v[1] < u[1]);
        });

        vector<vector<int>> res;
        // 插入
        for (const vector<int> &p : people)
        {
            res.insert(res.begin() + p[1], p);
        }

        return res;
    }
};