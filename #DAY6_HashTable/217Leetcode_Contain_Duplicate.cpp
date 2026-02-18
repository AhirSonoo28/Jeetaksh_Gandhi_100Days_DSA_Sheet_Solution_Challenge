#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 1};  // sample input

    if (sol.containsDuplicate(nums)) {
        cout << "Duplicate found" << endl;
    } else {
        cout << "No duplicate found" << endl;
    }

    return 0;
}


//Leetcode Link:-https://leetcode.com/submissions/detail/1921366448/
