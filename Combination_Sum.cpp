#include <bits/stdc++.h>
using namespace std;

void solve(int idx, int n, vector<int> &A, int B, vector<vector<int>> &ans, vector<int> vec, int sum)
{
    if (idx >= n or sum > B)
    {
        return;
    }

    if (sum == B)
    {
        ans.push_back(vec);
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (sum + A[i] <= B)
        {
            sum += A[i];
            vec.push_back(A[i]);
            solve(i, n, A, B, ans, vec, sum);
            vec.pop_back();
            sum -= A[i];
        }
    }
}
void findUnique(vector<int> &A)
{
    vector<int> newArray;
    newArray.push_back(A[0]);

    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] != A[i - 1])
        {
            newArray.push_back(A[i]);
        }
    }

    A = newArray;
}
vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    findUnique(A);
    vector<vector<int>> ans;
    vector<int> vec;

    solve(0, A.size(), A, B, ans, vec, 0);

    return ans;
}

int32_t main()
{
    vector<int> A{7, 2, 6, 5};

    vector<vector<int>> ans = combinationSum(A, 16);

    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}