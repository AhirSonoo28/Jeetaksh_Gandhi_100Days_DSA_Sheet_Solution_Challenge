#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, h = n - 1, maxArea = 0;
        int currentArea = 0;

        while (l < h) {
            currentArea = min(height[l], height[h]) * (h - l);
            maxArea = max(maxArea, currentArea);

            if (height[l] < height[h])
                l++;
            else
                h--;
        }

        return maxArea;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter the heights: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution obj;
    int result = obj.maxArea(height);

    cout << "Maximum Area: " << result << endl;

    return 0;
}

//Leetcdoe link :- https://leetcode.com/submissions/detail/1949377771/