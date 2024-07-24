bool isSafe(int i, int j, int n, int m, vector<vector<int>> &matrix, int num)
{
    if (i < 0 or j < 0 or i >= n or j >= m)
    {
        return false;
    }

    if (matrix[i][j] <= num)
    {
        return false;
    }

    return true;
}
int solve(int i, int j, int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (i < 0 or j < 0 or i >= n or j >= m)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int a = 0, b = 0, c = 0, d = 0;
    if (isSafe(i + 1, j, n, m, matrix, matrix[i][j]))
    {
        a = 1 + solve(i + 1, j, n, m, matrix, dp);
    }

    if (isSafe(i - 1, j, n, m, matrix, matrix[i][j]))
    {
        b = 1 + solve(i - 1, j, n, m, matrix, dp);
    }

    if (isSafe(i, j - 1, n, m, matrix, matrix[i][j]))
    {
        c = 1 + solve(i, j - 1, n, m, matrix, dp);
    }

    if (isSafe(i, j + 1, n, m, matrix, matrix[i][j]))
    {
        d = 1 + solve(i, j + 1, n, m, matrix, dp);
    }

    return dp[i][j] = max({a, b, c, d});
}
int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int ans = 0;
    int n = matrix.size(), m = matrix[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            ans = max(ans, solve(i, j, matrix.size(), matrix[i].size(), matrix, dp));
        }
    }

    return ans + 1;
}