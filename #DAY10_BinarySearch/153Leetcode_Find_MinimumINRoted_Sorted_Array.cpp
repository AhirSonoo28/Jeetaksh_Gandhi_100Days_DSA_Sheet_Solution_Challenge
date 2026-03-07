#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        int ans = nums[0];

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Left side sorted
            if (nums[mid] >= nums[0]) {
                start = mid + 1;
            }
            // Right side sorted
            else {
                ans = nums[mid];
                end = mid - 1;
            }
        }

        return ans;
    }
};

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements of rotated sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    int result = obj.findMin(nums);

    cout << "Minimum element: " << result << endl;

    return 0;
}

//Leetcode Link:-https://leetcode.com/submissions/detail/1941025249/