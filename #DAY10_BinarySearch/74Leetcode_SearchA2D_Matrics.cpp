#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        if (m == 0) return false;

        int n = matrix[0].size();

        int start = 0;
        int end = m * n - 1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            int element = matrix[mid / n][mid % n];

            if (target == element) {
                return true;
            }
            else if (target < element) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return false;
    }
};

int main() {

    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter matrix elements: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    bool result = obj.searchMatrix(matrix, target);

    if (result)
        cout << "Target found in matrix\n";
    else
        cout << "Target not found\n";

    return 0;
}

//Leetcode Link :-https://leetcode.com/submissions/detail/1941035582/