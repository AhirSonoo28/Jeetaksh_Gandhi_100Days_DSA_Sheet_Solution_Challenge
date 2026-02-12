#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n / 2];
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int result = obj.majorityElement(nums);

    cout << "Majority Element is: " << result << endl;

    return 0;
}

// Leetcde link :- https://leetcode.com/submissions/detail/1914956787/