/**
Given a string s, find the length of the longest 
substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /* Sliding window */
        int lSide = 0, rSide;
        int maxLength = 0;
        string subStr = ""; //Use to save the substring for checking

        /* Traverse all the characters in the string to find the max length substring */
        for (rSide = 0; rSide < s.length();)
        {
            /* Check if there are repeat characters in the substring */
            if (subStr.npos == subStr.find(s[rSide], 0))
            {
                /* No, increase the window size from right */
                subStr.push_back(s[rSide]);
                rSide++;
                
                if ((rSide - lSide) > maxLength)
                {
                    maxLength = rSide - lSide;
                }
            }
            else
            {
                /* Yes, decrease the window size from left */
                lSide++;
                subStr.erase(0, 1);
            }
        }

        return maxLength;
    }
};