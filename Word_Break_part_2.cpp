#include <bits/stdc++.h>
using namespace std;

bool check(string str, vector<string> &dict)
{
    // cout << "checking for str: " << str << endl;
    int n = dict.size();

    for (int i = 0; i < n; i++)
    {
        if (str == dict[i])
        {
            return true;
        }
    }

    return false;
}
void solve(int idx, int n, vector<string> &dict, string s, vector<string> &ans, vector<string> vec)
{
    if (idx == s.length())
    {
        string newStr = "";
        for (int i = 0; i < vec.size(); i++)
        {
            newStr += (vec[i] + " ");
        }
        newStr.pop_back();
        cout << "answer to be add: " << newStr << endl;
        ans.push_back(newStr);
        return;
    }

    string mystr = "";
    for (int i = idx; i < s.length(); i++)
    {
        mystr += s[i];
        // cout << "mystr: " << mystr << endl;
        if (check(mystr, dict))
        {
            cout << "giving true: " << mystr << endl;
            vec.push_back(mystr);
            solve(i + 1, n, dict, s, ans, vec);
            vec.pop_back();
        }
    }
}
vector<string> wordBreak(int n, vector<string> &dict, string s)
{
    vector<string> ans;
    vector<string> vec;
    solve(0, n, dict, s, ans, vec);

    return ans;
}

int32_t main()
{
    string s = "catsanddog";
    int n = 5;
    vector<string> dict{"cats", "cat", "and", "sand", "dog"};

    vector<string> ans = wordBreak(n, dict, s);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
}