#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        vector<vector<int>> v(2);   // initialize with size 2

        for (auto &match : matches) {
            int win  = match[0];
            int loss = match[1];

            // ensure winner exists with 0 loss
            if (mp.find(win) == mp.end()) {
                mp[win] = 0;
            }

            // increment loss count
            mp[loss]++;
        }

        // categorize players
        for (auto &player : mp) {
            if (player.second == 0) {
                v[0].push_back(player.first);
            } 
            else if (player.second == 1) {
                v[1].push_back(player.first);
            }
        }

        return v;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matches = {
        {1,3},{2,3},{3,6},{5,6},{5,7},
        {4,5},{4,8},{4,9},{10,4},{10,9}
    };

    vector<vector<int>> result = sol.findWinners(matches);

    cout << "Players with 0 losses: ";
    for (int x : result[0]) cout << x << " ";
    cout << endl;

    cout << "Players with 1 loss: ";
    for (int x : result[1]) cout << x << " ";
    cout << endl;

    return 0;
}


//Leetcode Link:- https://leetcode.com/submissions/detail/1923526062/
