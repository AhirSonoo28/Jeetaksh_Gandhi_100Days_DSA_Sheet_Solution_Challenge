#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            } else {
                digits[i] = 0;
            }
        }

        // If all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> digits(n);
    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }

    Solution obj;
    vector<int> result = obj.plusOne(digits);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
//Leet code link :- https://leetcode.com/submissions/detail/1914969224/
