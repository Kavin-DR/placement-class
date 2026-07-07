GeeksForGeeks-Rat in a maze

class Solution {
public:

    void solve(int row, int col,
               vector<vector<int>> &maze,
               vector<vector<int>> &vis,
               string path,
               vector<string> &ans)
    {
        int n = maze.size();

        if(row == n - 1 && col == n - 1)
        {
            ans.push_back(path);
            return;
        }

        vis[row][col] = 1;

        if(row + 1 < n &&
           maze[row + 1][col] == 1 &&
           !vis[row + 1][col])
        {
            solve(row + 1, col, maze, vis, path + 'D', ans);
        }

        if(col - 1 >= 0 &&
           maze[row][col - 1] == 1 &&
           !vis[row][col - 1])
        {
            solve(row, col - 1, maze, vis, path + 'L', ans);
        }

        
        if(col + 1 < n &&
           maze[row][col + 1] == 1 &&
           !vis[row][col + 1])
        {
            solve(row, col + 1, maze, vis, path + 'R', ans);
        }

        if(row - 1 >= 0 &&
           maze[row - 1][col] == 1 &&
           !vis[row - 1][col])
        {
            solve(row - 1, col, maze, vis, path + 'U', ans);
        }

        vis[row][col] = 0;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {

        vector<string> ans;
        int n = maze.size();

        if(maze[0][0] == 0 || maze[n-1][n-1] == 0)
            return ans;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        solve(0, 0, maze, vis, "", ans);

        return ans;
    }
};
