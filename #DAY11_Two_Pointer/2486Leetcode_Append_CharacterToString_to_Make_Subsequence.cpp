#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;

        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                j++;
            }
            i++;
        }

        return t.length() - j;
    }
};

int main() {
    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    Solution obj;
    int result = obj.appendCharacters(s, t);

    cout << "Minimum characters to append: " << result << endl;

    return 0;
}

//Leetcode Link :- https://leetcode.com/submissions/detail/1949395755/
