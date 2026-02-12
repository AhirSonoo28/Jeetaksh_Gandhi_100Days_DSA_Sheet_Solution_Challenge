#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;

        if (n == 1) {
            return nums;
        }

        if (n == 2) {
            if (nums[0] == nums[1]) {
                v.push_back(nums[0]);
                return v;
            } else {
                return nums;
            }
        }

        sort(nums.begin(), nums.end());

        int count = 1;

        for (int i = 1; i <= n - 1; i++) {

            if (nums[i - 1] == nums[i]) {
                count++;
            }
            else {
                if (count > n / 3) {
                    v.push_back(nums[i - 1]);
                }
                count = 1;
            }

            if (i == n - 1) {
                if (count > n / 3) {
                    v.push_back(nums[i]);
                }
            }
        }

        return v;
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
    vector<int> result = obj.majorityElement(nums);

    cout << "Majority elements (> n/3 times): ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}

//Leetcode Link :-https://leetcode.com/submissions/detail/1916950744/