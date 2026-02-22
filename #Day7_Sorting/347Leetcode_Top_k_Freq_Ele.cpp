#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // Step 1: Count frequency
        for (int it : nums) {
            mp[it]++;
        }

        // Step 2: Store (number, frequency) in vector
        vector<pair<int, int>> v;
        for (auto it : mp) {
            v.push_back(it);
        }

        // Step 3: Sort by frequency (descending)
        sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        });

        // Step 4: Take top k elements
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(v[i].first);
        }

        return result;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int> ans = obj.topKFrequent(nums, k);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}

//Leetcode Link:-https://leetcode.com/submissions/detail/1927647852/