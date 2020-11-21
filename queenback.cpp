#include <iostream>

using namespace std;

void printboard(int **board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                cout << "| Q |";
            }
            else
            {
                cout << "| * |";
            }
        }
        cout << endl;
    }
}

bool isSafe(int **board, int n, int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveutil(int **board, int n, int col)
{

    if (col >= n)
        return true;

    for (int i = 0; i < n; i++)
    {

        if (isSafe(board, n, i, col))
        {
            board[i][col] = 1;
            if (solveutil(board, n, col + 1))
                return true;

            board[i][col] = 0; // BACKTRACK
        }
    }

    return false;
}

void solvenq(int **board, int n)
{
    if (solveutil(board, n, 0) == false)
    {
        cout << "Not solvable" << endl;
    }
    printboard(board, n);
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int **board = new int *[n];
    for (int i = 0; i < n; i++)
        board[i] = new int[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    solvenq(board, n);
}