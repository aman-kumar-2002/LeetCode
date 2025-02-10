/*Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.*/

#include <vector>
using namespace std;

class Solution
{
public:
    // Function to check if placing 'num' at board[row][col] is valid
    bool isSafe(vector<vector<char>> &board, int row, int col, char num)
    {
        // Check if 'num' already exists in the current row or column
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == num || board[i][col] == num)
                return false;
        }

        // Check if 'num' already exists in the 3x3 sub-grid
        int subGridStartRow = row - row % 3;
        int subGridStartCol = col - col % 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[subGridStartRow + i][subGridStartCol + j] == num)
                    return false;
            }
        }
        return true; // The number can be placed safely
    }

    // Recursive function to solve Sudoku using backtracking
    bool solveSudokuHelper(vector<vector<char>> &board, int row, int col)
    {
        // If we reach beyond the last row, the Sudoku is solved
        if (row == 9)
            return true;

        // Move to the next column; if at last column, move to next row
        int nextRow = row, nextCol = col + 1;
        if (nextCol == 9)
        {
            nextRow = row + 1;
            nextCol = 0;
        }

        // If the cell is already filled, move to the next cell
        if (board[row][col] != '.')
            return solveSudokuHelper(board, nextRow, nextCol);

        // Try placing numbers from '1' to '9' in the empty cell
        for (char num = '1'; num <= '9'; num++)
        {
            if (isSafe(board, row, col, num))
            {
                board[row][col] = num; // Place the number

                // Recursively attempt to solve the next cell
                if (solveSudokuHelper(board, nextRow, nextCol))
                    return true;

                // Backtrack: Reset the cell if placing 'num' doesn't lead to a solution
                board[row][col] = '.';
            }
        }

        return false; // No valid number found, trigger backtracking
    }

    // Main function to solve the Sudoku puzzle
    void solveSudoku(vector<vector<char>> &board)
    {
        solveSudokuHelper(board, 0, 0);
    }
};
