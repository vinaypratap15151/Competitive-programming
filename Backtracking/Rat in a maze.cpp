#include <bits/stdc++.h>
using namespace std;

bool checkr(int grid[][9], int row, int num)
{

    for (int i = 0; i <= 8; i++)
    {
        if (grid[row][i] == num)
        {
            return false;
        }
    }
    return true;
}

bool checkc(int grid[][9], int col, int num)
{

    for (int i = 0; i <= 8; i++)
    {
        if (grid[i][col] == num)
        {
            return false;
        }
    }
    return true;
}

bool checkb(int grid[][9], int row, int col, int num)
{
    int r = row - (row % 3);
    int c = col - (col % 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (grid[i + r][j + c] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool check(int grid[][9], int row, int col, int num)
{

    if (checkr(grid, row, num) && checkc(grid, col, num) && checkb(grid, row, col, num))
    {
        return true;
    }

    return false;
}

bool find(int grid[9][9], int &row, int &col)
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool solve(int grid[9][9])
{

    int row, col;
    if (!find(grid, row, col))
    {

        return true;
    }

    for (int i = 1; i <= 9; i++)
    {

        if (check(grid, row, col, i))
        {
            grid[row][col] = i;

            if (solve(grid))
            {
                return true;
            }

            grid[row][col] = 0;
        }
    }
    return false;
}

int main()
{

    int grid[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> grid[i][j];
        }
    }

    if (solve(grid))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    // write your code here

    return 0;
}