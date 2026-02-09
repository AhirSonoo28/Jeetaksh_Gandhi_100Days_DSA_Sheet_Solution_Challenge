#include <bits/stdc++.h>
using namespace std;

class NumMatrix
{
public:
    vector<vector<int>> prefixsum;

    NumMatrix(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        prefixsum.resize(row + 1, vector<int>(col + 1, 0));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                prefixsum[i + 1][j + 1] =
                    prefixsum[i][j + 1] +
                    prefixsum[i + 1][j] -
                    prefixsum[i][j] +
                    matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return prefixsum[row2 + 1][col2 + 1] - prefixsum[row2 + 1][col1] - prefixsum[row1][col2 + 1] + prefixsum[row1][col1];
    }
};

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    NumMatrix obj(matrix);
    // number of queries
    int q;
    cin >> q;

    while (q--)
    {
        int row1, col1, row2, col2;
        cin >> row1 >> col1 >> row2 >> col2;
        cout << obj.sumRegion(row1, col1, row2, col2) << endl;
    }

    return 0;
}
