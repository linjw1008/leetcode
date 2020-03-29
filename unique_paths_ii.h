class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
/*
        if (m == 1 || n == 1)
        {
            return 1;
        }
 */       
        vector<vector<long>> dp;
        dp.resize(m);
        for (int i = 0; i < m; i++)
        {
            dp[i].resize(n, 0);
        }
        
        //边界值处理
        int value = 1;
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = value;
            if (obstacleGrid[i][0] == 1)
            {
                value = 0;
            }
        }
        value = 1;
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = value;
            if (obstacleGrid[0][j] == 1)
            {
                value = 0;
            }
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] * (obstacleGrid[i - 1][j] == 1 ? 0 : 1) + dp[i][j - 1] * (obstacleGrid[i][j - 1] == 1 ? 0 : 1);
            }
        }
        
        return dp[m - 1][n - 1] * (obstacleGrid[m - 1][n - 1] == 1 ? 0 : 1);

    }
};