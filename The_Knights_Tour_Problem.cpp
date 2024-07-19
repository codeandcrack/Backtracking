bool solve(int i, int j, vector<vector<int>> &grid, int target, int count, int n)
{
    if (count == target)
    {
        return true;
    }

    if (i < 0 or j < 0 or i >= n or j >= n or grid[i][j] != count)
    {
        return false;
    }

    bool a = solve(i + 2, j + 1, grid, target, count + 1, n);
    bool b = solve(i + 2, j - 1, grid, target, count + 1, n);
    bool c = solve(i - 2, j + 1, grid, target, count + 1, n);
    bool d = solve(i - 2, j - 1, grid, target, count + 1, n);
    bool e = solve(i + 1, j + 2, grid, target, count + 1, n);
    bool f = solve(i - 1, j + 2, grid, target, count + 1, n);
    bool g = solve(i + 1, j - 2, grid, target, count + 1, n);
    bool h = solve(i - 1, j - 2, grid, target, count + 1, n);

    return a or b or c or d or e or f or g or h;
}
bool checkValidGrid(vector<vector<int>> &grid)
{
    int n = grid.size();
    int target = (n * n);
    return solve(0, 0, grid, target, 0, n);
}