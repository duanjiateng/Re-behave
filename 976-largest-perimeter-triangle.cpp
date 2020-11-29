class Solution
{
public:
    /*
    排序
    然后从最大三个数开始 a <= b <= c
    找出满足 a + b > c, return a + b + c
    */
    int largestPerimeter(vector<int> &A)
    {
        sort(A.begin(), A.end());
        int n = A.size();
        for (int i = n - 3; i >= 0; i--)
        {
            if (A[i] + A[i + 1] > A[i + 2])
                return A[i] + A[i + 1] + A[i + 2];
        }
        return 0;
    }
};