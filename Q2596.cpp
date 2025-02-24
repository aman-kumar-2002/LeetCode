/*There is a knight on an n x n chessboard. In a valid configuration,
the knight starts at the top-left cell of the board and visits every cell on the board exactly once.

You are given an n x n integer matrix grid consisting of distinct integers
from the range [0, n * n - 1] where grid[row][col] indicates that
the cell (row, col) is the grid[row][col]th cell that the knight visited. The moves are 0-indexed.

Return true if grid represents a valid configuration of the knight's movements or false otherwise.

Note that a valid knight move consists of moving two squares vertically
and one square horizontally, or two squares horizontally and one square vertically.
The figure below illustrates all the possible eight moves of a knight from some cell.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Helper function to check if the knight's tour sequence is valid
    bool isValidMove(vector<vector<int>> &grid, int row, int col, int gridSize, int expectedValue)
    {
        // Boundary conditions: check if the move is out of bounds or does not match the expected value
        if (row < 0 || col < 0 || row >= gridSize || col >= gridSize || grid[row][col] != expectedValue)
        {
            return false;
        }

        // If we have reached the last expected value in the sequence, return true
        if (expectedValue == gridSize * gridSize - 1)
        {
            return true;
        }

        // 8 possible knight moves in an L-shape
        bool move1 = isValidMove(grid, row - 2, col + 1, gridSize, expectedValue + 1);
        bool move2 = isValidMove(grid, row - 1, col + 2, gridSize, expectedValue + 1);
        bool move3 = isValidMove(grid, row + 1, col + 2, gridSize, expectedValue + 1);
        bool move4 = isValidMove(grid, row + 2, col + 1, gridSize, expectedValue + 1);
        bool move5 = isValidMove(grid, row + 2, col - 1, gridSize, expectedValue + 1);
        bool move6 = isValidMove(grid, row + 1, col - 2, gridSize, expectedValue + 1);
        bool move7 = isValidMove(grid, row - 1, col - 2, gridSize, expectedValue + 1);
        bool move8 = isValidMove(grid, row - 2, col - 1, gridSize, expectedValue + 1);

        // If any of the 8 possible moves lead to a valid knight's tour, return true
        return move1 || move2 || move3 || move4 || move5 || move6 || move7 || move8;
    }

    // Function to check if the given knight's tour grid is valid
    bool checkValidGrid(vector<vector<int>> &grid)
    {
        int gridSize = grid.size();

        // The knight starts at the top-left corner (0,0) with an expected value of 0
        return isValidMove(grid, 0, 0, gridSize, 0);
    }
};