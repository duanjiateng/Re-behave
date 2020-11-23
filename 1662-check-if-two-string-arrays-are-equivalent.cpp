class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string s1;
        for (auto &word : word1)
        {
            s1 += word;
        }

        string s2;
        for (auto &word : word2)
        {
            s2 += word;
        }

        return s1 == s2;
    }
};