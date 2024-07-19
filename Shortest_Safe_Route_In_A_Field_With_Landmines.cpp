#include <bits/stdc++.h>
using namespace std;

void send(int i, int j, vector<vector<int>> &field, int row, int col)
{
    if (i < 0 or j < 0 or i >= row or j >= col)
    {
        return;
    }

    field[i][j] = -2;
    return;
}
void madePure(vector<vector<int>> &field)
{
    for (int i = 0; i < field.size(); i++)
    {
        for (int j = 0; j < field[i].size(); j++)
        {
            if (field[i][j] == 0)
            {
                send(i + 1, j, field, field.size(), field[i].size());
                send(i - 1, j, field, field.size(), field[i].size());
                send(i, j - 1, field, field.size(), field[i].size());
                send(i, j + 1, field, field.size(), field[i].size());
                field[i][j] = -2;
            }
        }
    }

    for (int i = 0; i < field.size(); i++)
    {
        for (int j = 0; j < field[i].size(); j++)
        {
            if (field[i][j] == -2)
            {
                field[i][j] = 0;
            }
        }
    }
}

int solve(int i, int j, vector<vector<int>> &field, int n, int m)
{
    queue<pair<int, int>> q;
    vector<vector<int>> vec = field;
    q.push({i, j});

    while (!q.empty())
    {
        pair<int, int> fr = q.front();
        q.pop();
        int row = fr.first, col = fr.second;

        if (row + 1 >= 0 and row + 1 < n and col >= 0 and col + 1 < m and vec[row][col] == 1 and vec[row][col] != 0)
        {
            vec[row + 1][col] = vec[row][col] + 1;
            q.push({row + 1, col});
        }

        if (row - 1 >= 0 and row - 1 < n and col >= 0 and col + 1 < m and vec[row][col] == 1 and vec[row][col] != 0)
        {
            vec[row - 1][col] = vec[row][col] + 1;
            q.push({row - 1, col});
        }

        if (row >= 0 and row < n and col + 1 >= 0 and col + 1 < m and vec[row][col] == 1 and vec[row][col] != 0)
        {
            vec[row][col + 1] = vec[row][col] + 1;
            q.push({row, col + 1});
        }
    }

    int maxAns = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        if (vec[n - 1][i] != 0)
            maxAns = min(maxAns, vec[n - 1][i]);
    }

    return maxAns;
}
int shortestPath(vector<vector<int>> &field)
{
    madePure(field);
    for (int i = 0; i < field.size(); i++)
    {
        for (int j = 0; j < field[i].size(); j++)
        {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }

    int ans = INT_MAX;
    for (int i = 0; i < field.size(); i++)
    {
        if (field[i][0] != 0)
        {
            ans = min(ans, solve(i, 0, field, field.size(), field[i].size()));
        }
    }

    if (ans == INT_MAX)
    {
        return -1;
    }

    return ans;
}

int32_t main()
{
    vector<vector<int>> field{{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 1}};

    for (int i = 0; i < field.size(); i++)
    {
        for (int j = 0; j < field[i].size(); j++)
        {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int ans = shortestPath(field);

    cout << "Ans: " << ans << endl;
}