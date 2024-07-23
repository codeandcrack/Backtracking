void solve(int i, int j, int n, int m, vector<vector<int>> matrix, vector<vector<int>> &vis, int count, int &ans, int xd, int yd)
{
    if (i < 0 or j < 0 or i >= n or j >= m or vis[i][j] or matrix[i][j] == 0)
    {
        return;
    }

    if (i == xd and j == yd)
    {
        ans = max(ans, count);
        return;
    }

    vis[i][j] = 1;
    solve(i + 1, j, n, m, matrix, vis, count + 1, ans, xd, yd);
    solve(i - 1, j, n, m, matrix, vis, count + 1, ans, xd, yd);
    solve(i, j + 1, n, m, matrix, vis, count + 1, ans, xd, yd);
    solve(i, j - 1, n, m, matrix, vis, count + 1, ans, xd, yd);
    vis[i][j] = 0;
}
int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
{
    int n = matrix.size(), m = matrix[0].size();

    int ans = -1;

    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));

    solve(xs, ys, n, m, matrix, vis, 0, ans, xd, yd);

    return ans;
}