/**
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true

Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 
Constraints:
1 <= s.length <= 2 * 10^5
s consists only of printable ASCII characters.

https://leetcode.com/problems/valid-palindrome/description/
 */

class Solution {
public:
    bool isPalindrome(string s) {
        int i, converter = 'a' - 'A';
        string str;

        /* Remove all non-alphanumeric characters in the string */
        for (i = 0; i < s.size(); i++) {
            if (('A' <= s[i]) && ('Z' >= s[i])) {
                str.push_back(s[i] + converter);
            } else if ((('a' <= s[i]) && ('z' >= s[i])) ||
                       (('0' <= s[i]) && ('9' >= s[i]))) {
                str.push_back(s[i]);
            }
        }

        /* Compare between first and last in the string */
        for (i = 0; i < str.size(); i++) {
            int j = str.size() - 1 - i;
            if (i == j) {
                break;
            }

            if (str[i] != str[j]) {
                return false;
            }
        }
        return true;
    }
};