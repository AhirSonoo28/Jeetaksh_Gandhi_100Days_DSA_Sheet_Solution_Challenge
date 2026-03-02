#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    // Store start with original index
    vector<pair<int, int>> starts;
    for (int i = 0; i < n; i++) {
        starts.push_back({intervals[i][0], i});
    }

    // Sort by start value
    sort(starts.begin(), starts.end());

    vector<int> result(n, -1);

    // For each interval, binary search
    for (int i = 0; i < n; i++) {
        int end = intervals[i][1];
        int low = 0, high = n - 1;
        int idx = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (starts[mid].first >= end) {
                idx = starts[mid].second;
                high = mid - 1;   // try to minimize start
            } else {
                low = mid + 1;
            }
        }
        result[i] = idx;
    }

    // Output
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}


//Leetcode Link :- https://leetcode.com/submissions/detail/1935983317/