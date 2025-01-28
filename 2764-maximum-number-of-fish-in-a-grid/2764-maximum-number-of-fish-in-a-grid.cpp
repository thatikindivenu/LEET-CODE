#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;

        // Helper function for DFS
        function<int(int, int)> dfs = [&](int r, int c) {
            // If out of bounds or land cell, return 0
            if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
                return 0;
            }
            
            int fish = grid[r][c];
            grid[r][c] = 0; // Mark the cell as visited
            
            // Explore all adjacent cells
            fish += dfs(r + 1, c);
            fish += dfs(r - 1, c);
            fish += dfs(r, c + 1);
            fish += dfs(r, c - 1);
            
            return fish;
        };

        // Traverse the grid to find connected components of water cells
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] > 0) { // Start DFS if it's a water cell
                    maxFish = max(maxFish, dfs(r, c));
                }
            }
        }
        
        return maxFish;
    }
};
