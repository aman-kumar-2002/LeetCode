/*Problem Description: Rat in a Maze (Pathfinding using Backtracking)
Problem Statement:
A rat is placed at the top-left corner of an N x N maze (grid) at position (0,0). The rat needs to find a path to reach the bottom-right corner (N-1, N-1). The maze consists of open paths (1) and blocked cells (0). The rat can move Down (D), Up (U), Left (L), or Right (R) but cannot pass through blocked cells (0).

The objective is to find all possible paths from the start (0,0) to the destination (N-1,N-1). If no path exists, return an empty result.

Constraints:
The maze is represented as a square matrix of size N x N, where 1 indicates an open path and 0 indicates a blocked cell.
The rat cannot move diagonally, only in four directions: Down, Up, Left, and Right.
The rat cannot visit a cell more than once in the same path.
If the start cell (0,0) or the destination cell (N-1,N-1) is blocked (0), the rat cannot start or reach the goal.
The result should contain all possible paths in lexicographical order.
Input Format:
An integer N, the size of the maze.
An N x N grid representing the maze, where:
1 denotes an open path.
0 denotes a blocked cell.
Output Format:
If at least one path exists, print all possible paths from (0,0) to (N-1,N-1), each represented as a string of movement directions (D, U, L, R).
If no path exists, print "No path found".*/

#include <bits/stdc++.h>
using namespace std;

// Helper function to explore paths in the maze
void findPathsHelper(vector<vector<int>> &maze, int row, int col, string currentPath,
                     vector<string> &allPaths, vector<vector<bool>> &visited)
{
    int size = maze.size();

    // Boundary conditions and obstacle check
    if (row < 0 || col < 0 || row >= size || col >= size || maze[row][col] == 0 || visited[row][col])
    {
        return;
    }

    // If the destination (bottom-right) is reached, store the path
    if (row == size - 1 && col == size - 1)
    {
        allPaths.push_back(currentPath);
        return;
    }

    // Mark the current cell as visited
    visited[row][col] = true;

    // Explore all four possible directions: Down, Up, Left, Right
    findPathsHelper(maze, row + 1, col, currentPath + "D", allPaths, visited); // Move Down
    findPathsHelper(maze, row - 1, col, currentPath + "U", allPaths, visited); // Move Up
    findPathsHelper(maze, row, col - 1, currentPath + "L", allPaths, visited); // Move Left
    findPathsHelper(maze, row, col + 1, currentPath + "R", allPaths, visited); // Move Right

    // Unmark the current cell before backtracking
    visited[row][col] = false;
}

// Function to find all possible paths from (0,0) to (n-1,n-1)
vector<string> findAllPaths(vector<vector<int>> &maze)
{
    int size = maze.size();
    vector<string> allPaths;
    vector<vector<bool>> visited(size, vector<bool>(size, false)); // Track visited cells

    // If the starting position is open, initiate pathfinding
    if (maze[0][0] == 1)
    {
        findPathsHelper(maze, 0, 0, "", allPaths, visited);
    }

    // Optional: Sort paths lexicographically for consistent output
    sort(allPaths.begin(), allPaths.end());

    return allPaths;
}

// Main function to take input and display results
int main()
{
    int size;
    cout << "Enter the size of the maze (N x N): ";
    cin >> size;

    vector<vector<int>> maze(size, vector<int>(size));

    cout << "Enter the maze matrix (1 for open path, 0 for blocked cell):\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> maze[i][j];
        }
    }

    vector<string> paths = findAllPaths(maze);

    // Display results
    if (paths.empty())
    {
        cout << "No path found from (0,0) to (" << size - 1 << "," << size - 1 << ").\n";
    }
    else
    {
        cout << "Possible paths from (0,0) to (" << size - 1 << "," << size - 1 << "):\n";
        for (const string &path : paths)
        {
            cout << path << "\n";
        }
    }

    return 0;
}
