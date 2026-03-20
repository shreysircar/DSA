//Approach - 1 - Brute Force DFS (you can do BFS as well)
//T.C : O(n^4)
//S.C : O(n^2)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j])
            return 0;

        visited[i][j] = true;
        int count = 1;

        for(vector<int>& dir : directions) {
            count += DFS(grid, i + dir[0], j + dir[1], visited);
        }

        return count;
    }

    int findLargestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {  // Try converting each 0 to 1
                    grid[i][j] = 1;
                    
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    int largest = 0;
                    
                    for(int x = 0; x < m; x++) {
                        for(int y = 0; y < n; y++) {
                            if(grid[x][y] == 1 && !visited[x][y]) {
                                largest = max(largest, DFS(grid, x, y, visited));
                            }
                        }
                    }
                    
                    maxArea = max(maxArea, largest);
                    grid[i][j] = 0; // Backtrack
                }
            }
        }
        
        return (maxArea == 0) ? m * n : maxArea; // If the grid was full of 1s
    }

    int largestIsland(vector<vector<int>>& grid) {
        return findLargestIsland(grid);
    }
};