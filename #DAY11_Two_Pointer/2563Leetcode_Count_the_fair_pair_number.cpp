#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int right = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();

            count += (right - left);
        }

        return count;
    }
};

int main() {
    int n, lower, upper;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter lower and upper: ";
    cin >> lower >> upper;

    Solution obj;
    cout << "Number of Fair Pairs: " << obj.countFairPairs(nums, lower, upper);

    return 0;
}

//Leetcode link :-https://leetcode.com/submissions/detail/1949392343/
