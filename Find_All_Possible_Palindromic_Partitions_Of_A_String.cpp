#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    int i = 0, j = str.length() - 1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}
void solve(int idx, int n, string S, vector<vector<string>> &ans, vector<string> vec)
{
    if (idx >= n)
    {
        ans.push_back(vec);
        return;
    }

    string str = "";
    for (int i = idx; i < n; i++)
    {
        str += S[i];
        if (isPalindrome(str))
        {
            vec.push_back(str);
            solve(i + 1, n, S, ans, vec);
            vec.pop_back();
        }
    }
    return;
}
vector<vector<string>> allPalindromicPerms(string S)
{
    vector<vector<string>> ans;
    vector<string> vec;
    solve(0, S.length(), S, ans, vec);

    return ans;
}

int32_t main()
{
    string s = "geeks";

    vector<vector<string>> ans = allPalindromicPerms(s);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}