#include <array>
#include <iostream>
using namespace std;
#define N 4

void PrintSol(const std::array<std::array<int, N>, N> &board)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
bool isSafe(const std::array<std::array<int, N>, N> &board, int row,
              int col)
{
    /// check in the row
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }
    /// check the first diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    /// check the second diagonal
    for (int i = row, j = col; i <= N - 1 && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}
void NQueenSol(std::array<std::array<int, N>, N> board, int col)
{
    if (col >= N)
    {
        PrintSol(board);
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            NQueenSol(board, col + 1);
            board[i][col] = 0;
        }
    }
}

int main()
{
    std::array<std::array<int, N>, N> board{0};

    NQueenSol(board, 0);
}