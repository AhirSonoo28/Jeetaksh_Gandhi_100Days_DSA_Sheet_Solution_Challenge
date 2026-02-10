#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double FindPow(double x, long long N) {
        if (N == 0) return 1.0;

        double half = FindPow(x, N / 2);

        if (N % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }

    double myPow(double x, int n) {
        long long N = n;

        // Handle negative power
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return FindPow(x, N);
    }
};

int main() {
    double x;
    int n;
    cin >> x >> n;

    Solution obj;
    cout << obj.myPow(x, n);

    return 0;
}
//leet code link :-https://leetcode.com/submissions/detail/1914972638/