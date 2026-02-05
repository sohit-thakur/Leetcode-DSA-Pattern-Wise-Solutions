#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<string> ans;

    bool isSafe(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    void solve(int i, int j, vector<vector<int>>& maze, string temp, int n) {
        if (!isSafe(i, j, n) || maze[i][j] == 0) return;
        if (i == n-1 && j == n-1) {
            ans.push_back(temp);
            return;
        }

        maze[i][j] = 0; 

        temp.push_back('D');
        solve(i+1, j, maze, temp, n);
        temp.pop_back();

        temp.push_back('R');
        solve(i, j+1, maze, temp, n);
        temp.pop_back();

        temp.push_back('U');
        solve(i-1, j, maze, temp, n);
        temp.pop_back();

        temp.push_back('L');
        solve(i, j-1, maze, temp, n);
        temp.pop_back();

        maze[i][j] = 1; 
    }

public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        string temp = "";
        solve(0, 0, maze, temp, n);
        sort(ans.begin(), ans.end()); 
        return ans;
    }
};
