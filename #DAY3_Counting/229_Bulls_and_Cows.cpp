#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int n = secret.length();
        
        vector<int> freq(10, 0);  // frequency for digits 0-9

        // First pass: count bulls and store non-bull digits
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                freq[secret[i] - '0']++;
            }
        }

        // Second pass: count cows
        for (int i = 0; i < n; i++) {
            if (secret[i] != guess[i]) {
                int digit = guess[i] - '0';
                
                if (freq[digit] > 0) {
                    cows++;
                    freq[digit]--;
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main() {
    string secret, guess;

    cout << "Enter secret: ";
    cin >> secret;

    cout << "Enter guess: ";
    cin >> guess;

    Solution obj;
    string result = obj.getHint(secret, guess);

    cout << "Hint: " << result << endl;

    return 0;
}


//Leetcode link :-https://leetcode.com/submissions/detail/1916967278/