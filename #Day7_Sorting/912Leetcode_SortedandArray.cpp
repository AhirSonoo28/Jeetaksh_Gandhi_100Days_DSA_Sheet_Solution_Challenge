#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Merge function
    void mergs(vector<int>& nums, int l, int m, int r) {
        vector<int> temp;
        int i = l, j = m + 1;

        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= m) {
            temp.push_back(nums[i++]);
        }

        while (j <= r) {
            temp.push_back(nums[j++]);
        }

        for (int k = l; k <= r; k++) {
            nums[k] = temp[k - l];
        }
    }

    // Merge Sort
    void mergSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;

        int m = l + (r - l) / 2;
        mergSort(nums, l, m);
        mergSort(nums, m + 1, r);
        mergs(nums, l, m, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {5, 2, 3, 1};

    vector<int> result = obj.sortArray(nums);

    cout << "Sorted Array: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}

//leetcode link :-https://leetcode.com/submissions/detail/1926628302/