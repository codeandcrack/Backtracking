void solve(int idx, string str, int k, string &ans)
{
    if (k == 0)
    {
        return;
    }

    char maxEle = str[idx];

    for (int i = idx + 1; i < str.length(); i++)
    {
        if (str[i] > maxEle)
        {
            maxEle = str[i];
        }
    }

    if (maxEle != str[idx])
    {
        k--;
    }

    for (int i = idx; i < str.length(); i++)
    {
        if (str[i] == maxEle)
        {
            swap(str[i], str[idx]);
            ans = max(ans, str);
            solve(idx + 1, str, k, ans);
            swap(str[i], str[idx]);
        }
    }
}
string findMaximumNum(string str, int k)
{
    string ans = str;

    solve(0, str, k, ans);

    return ans;
}