#include <bits/stdc++.h>
using namespace std;

class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;

public:
    // Constructor
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;
    }

    // Add val to nums2[index]
    void add(int index, int val) {
        nums2[index] += val;
    }

    // Count pairs whose sum == tot
    int count(int tot) {
        int ans = 0;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] + nums2[j] == tot) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums1 = {1, 1, 2, 2, 2, 3};
    vector<int> nums2 = {1, 4, 5, 2, 5, 4};

    FindSumPairs obj(nums1, nums2);

    cout << obj.count(7) << endl;   // 8
    obj.add(3, 2);                  // nums2[3] += 2
    cout << obj.count(8) << endl;   // 2
    cout << obj.count(4) << endl;   // 1
    obj.add(0, 1);
    obj.add(1, 1);
    cout << obj.count(7) << endl;   // 11

    return 0;
}


//Leetcode Link:-https://leetcode.com/submissions/detail/1923558739/