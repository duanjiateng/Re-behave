class Solution
{
public:
    string reorganizeString(string S)
    {
        int n = S.size();
        if (n < 2)
            return S;
        vector<int> cnt(26, 0);
        int maxCnt = 0;
        for (auto ch : S)
        {
            cnt[ch - 'a']++;
            maxCnt = max(maxCnt, cnt[ch - 'a']);
        }
        // 判断是否有解
        if (maxCnt > (n + 1) / 2)
            return "";
        // 比较器
        auto cmp = [&](const char &ch1, const char &ch2) {
            return cnt[ch1 - 'a'] < cnt[ch2 - 'a'];
        };
        // 优先队列
        priority_queue<char, vector<char>, decltype(cmp)> queue{cmp};
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (cnt[ch - 'a'] > 0)
                queue.push(ch);
        }
        string res = "";
        while (queue.size() > 1)
        {
            char ch1 = queue.top();
            queue.pop();
            char ch2 = queue.top();
            queue.pop();
            res += ch1;
            res += ch2;
            int idx1 = ch1 - 'a', idx2 = ch2 - 'a';
            cnt[idx1]--;
            cnt[idx2]--;
            if (cnt[idx1] > 0)
                queue.push(ch1);
            if (cnt[idx2] > 0)
                queue.push(ch2);
        }
        if (queue.size() > 0)
            res += queue.top();
        return res;
    }
};