class Solution {
public:
    int m, n;
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(int i, int j, int prevCellVal, vector<vector<int>>& heights,
             vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return;
        }
        if (heights[i][j] < prevCellVal || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        for (auto& dir : direction) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            dfs(i_, j_, heights[i][j], heights, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights[0].size();
        m = heights.size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            dfs(i, 0, INT_MIN, heights, pacific);
        for (int j = 0; j < n; j++)
            dfs(0, j, INT_MIN, heights, pacific);

        for (int j = 0; j < n; j++)
            dfs(m - 1, j, INT_MIN, heights, atlantic);
        for (int i = 0; i < m; i++)
            dfs(i, n - 1, INT_MIN, heights, atlantic);

        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};