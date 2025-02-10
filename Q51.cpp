/*The n-queens puzzle is the problem of placing n queens
on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.
You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement,
where 'Q' and '.' both indicate a queen and an empty space, respectively.*/

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    // Function to check if placing a queen at board[row][col] is safe
    bool isSafe(vector<string> &board, int currentRow, int currentCol, int boardSize)
    {
        // Check the same column for any previously placed queen
        for (int row = 0; row < currentRow; row++)
        {
            if (board[row][currentCol] == 'Q')
                return false;
        }

        // Check the upper-left diagonal for any queen
        for (int row = currentRow, col = currentCol; row >= 0 && col >= 0; row--, col--)
        {
            if (board[row][col] == 'Q')
                return false;
        }

        // Check the upper-right diagonal for any queen
        for (int row = currentRow, col = currentCol; row >= 0 && col < boardSize; row--, col++)
        {
            if (board[row][col] == 'Q')
                return false;
        }

        return true; // No conflicts, safe to place queen
    }

    // Recursive function to solve the N-Queens problem using backtracking
    void solveNQueensHelper(vector<string> &board, int currentRow, int boardSize, vector<vector<string>> &solutions)
    {
        // Base case: If all queens are placed, store the current board configuration
        if (currentRow == boardSize)
        {
            solutions.push_back(board);
            return;
        }

        // Try placing the queen in each column of the current row
        for (int col = 0; col < boardSize; col++)
        {
            if (isSafe(board, currentRow, col, boardSize))
            {
                board[currentRow][col] = 'Q';                                    // Place the queen
                solveNQueensHelper(board, currentRow + 1, boardSize, solutions); // Recur for the next row
                board[currentRow][col] = '.';                                    // Backtrack by removing the queen
            }
        }
    }

    // Function to return all possible solutions for the N-Queens problem
    vector<vector<string>> solveNQueens(int boardSize)
    {
        vector<vector<string>> solutions;                        // Stores all valid board configurations
        vector<string> board(boardSize, string(boardSize, '.')); // Initialize an empty board

        solveNQueensHelper(board, 0, boardSize, solutions); // Start backtracking from the first row
        return solutions;
    }
};
