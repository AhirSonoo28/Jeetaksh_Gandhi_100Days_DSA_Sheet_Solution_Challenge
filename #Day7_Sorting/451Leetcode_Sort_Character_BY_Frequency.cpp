#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {

        // Step 1: Count frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Store (character, frequency) into a vector
        vector<pair<char, int>> vec;
        for (auto it : freq) {
            vec.push_back(it);
        }

        // Step 3: Sort vector by frequency (descending)
        sort(vec.begin(), vec.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
        });

        // Step 4: Build the result string
        string result = "";
        for (auto &p : vec) {
            result.append(p.second, p.first);
        }

        return result;
    }
};

int main() {
    Solution obj;

    string s1 = "tree";
    string s2 = "cccaaa";
    string s3 = "Aabb";

    cout << obj.frequencySort(s1) << endl;
    cout << obj.frequencySort(s2) << endl;
    cout << obj.frequencySort(s3) << endl;

    return 0;
}



//Leetcode Link:-https://leetcode.com/submissions/detail/1927620233/