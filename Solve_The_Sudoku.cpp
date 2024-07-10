#include <bits/stdc++.h>
using namespace std;
bool check(char num, int r, int c, vector<vector<char>> &grid)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[r][i] == num)
        {
            return false;
        }

        if (grid[i][c] == num)
        {
            return false;
        }
    }

    if (r >= 0 and r <= 2 and c >= 0 and c <= 2)
    {
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                if (grid[i][j] == num)
                {
                    return false;
                }
            }
        }
    }

    if (r >= 3 and r <= 5 and c >= 0 and c <= 2)
    {
        for (int i = 3; i <= 5; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                if (grid[i][j] == num)
                {
                    return false;
                }
            }
        }
    }

    if (r >= 6 and r <= 8 and c >= 0 and c <= 2)
    {
        for (int i = 6; i <= 8; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                if (grid[i][j] == num)
                {
                    return false;
                }
            }
        }
    }

    if (r >= 0 and r <= 2 and c >= 3 and c <= 5)
    {
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 3; j <= 5; j++)
            {
                if (grid[i][j] == num)
                {
                    return false;
                }
            }
        }
    }

    if (r >= 3 and r <= 5 and c >= 3 and c <= 5)
    {
        for (int i = 3; i <= 5; i++)
        {
            for (int j = 3; j <= 5; j++)
            {
                if (grid[i][j] == num)
                {
                    return false;
                }
            }
        }
    }

    if (r >= 6 and r <= 8 and c >= 3 and c <= 5)
    {
        for (int i = 6; i <= 8; i++)
        {
            for (int j = 3; j <= 5; j++)
            {
                if (grid[i][j] == num)
                {
                    return false;
                }
            }
        }
    }

    if (r >= 0 and r <= 2 and c >= 6 and c <= 8)
    {
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 6; j <= 8; j++)
            {
                if (grid[i][j] == num)
                {
                    return false;
                }
            }
        }
    }

    if (r >= 3 and r <= 5 and c >= 6 and c <= 8)
    {
        for (int i = 3; i <= 5; i++)
        {
            for (int j = 6; j <= 8; j++)
            {
                if (grid[i][j] == num)
                {
                    return false;
                }
            }
        }
    }

    if (r >= 6 and r <= 8 and c >= 6 and c <= 8)
    {
        for (int i = 6; i <= 8; i++)
        {
            for (int j = 6; j <= 8; j++)
            {
                if (grid[i][j] == num)
                {
                    return false;
                }
            }
        }
    }

    return true;
}
bool solve(vector<vector<char>> &grid)
{
    int N = 9;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == '.')
            {
                for (char k = '1'; k <= '9'; k++)
                {
                    if (check(k, i, j, grid))
                    {
                        grid[i][j] = k;
                        if (solve(grid))
                        {
                            return true;
                        }
                        grid[i][j] = '.';
                    }
                }
            }
            if (grid[i][j] == '.')
            {
                return false;
            }
        }
    }

    return true;
}
void solveSudoku(vector<vector<char>> &grid)
{
    bool x = solve(grid);
    return;
}
int32_t main()
{
    vector<vector<char>> grid = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(grid);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}