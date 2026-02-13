#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans(m * n);

        int d = 1;      // direction: 1 = up-right, -1 = down-left
        int row = 0;
        int col = 0;

        for (int i = 0; i < m * n; ++i) {
            ans[i] = matrix[row][col];

            row -= d;
            col += d;

            // Out of bounds conditions
            if (row >= m) {
                row = m - 1;
                col += 2;
                d = -d;
            }

            if (col >= n) {
                col = n - 1;
                row += 2;
                d = -d;
            }

            if (row < 0) {
                row = 0;
                d = -d;
            }

            if (col < 0) {
                col = 0;
                d = -d;
            }
        }

        return ans;
    }
};

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution sol;
    vector<int> result = sol.findDiagonalOrder(matrix);

    cout << "Diagonal Order: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
