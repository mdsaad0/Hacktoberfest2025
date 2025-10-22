class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        // Boundary and water check
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0')
            return;

        // Mark the current land as visited
        grid[i][j] = '0';

        // Visit all 4 directions (up, down, left, right)
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Found a new island
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j); // Mark all its land as visited
                }
            }
        }
        return count;
    }
};
