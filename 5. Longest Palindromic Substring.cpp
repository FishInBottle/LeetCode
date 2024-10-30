/**
5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.


Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
 

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
  */

class Solution {
public:
    uint16_t maxOffset = 0, maxLength = 0;

    void findMaxPalindromic(string s, int16_t left, int16_t right)
    {
        while ((0 <= left) && (s.size() > right) && (s[left] == s[right]))
        {
            /* If a longer one is found, then save its offset and length */
            if (maxLength < (right - left + 1))
            {
                maxLength = right - left + 1;
                maxOffset = left;
            }

            /* Try to expend this substring until s[left] != s[right] */
            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        /* Travese for each char, treat it as center and try to expend this substring */
        for (int i = 0; i < s.size(); i++)
        {
            /* For even case, such as "aa" */
            findMaxPalindromic(s, i, i);

            /* For odd case, such as "aba" */
            if (s.size() > (i + 1))
                findMaxPalindromic(s, i, i + 1);
        }

        return s.substr(maxOffset, maxLength);
    }
};
