class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        if (n == 0) return;
        
        vector<bool> mem(m + n, false);
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    mem[i] = true;
                    mem[m + j] = true;
                }
            }
        }
        
        //行清零
        for (int i = 0; i < m; i++)
        {
            if (mem[i])
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }      
        
        //列清零
        for (int j = 0; j < n; j++)
        {
            if (mem[m + j])
            {
                for (int i = 0; i < m; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};