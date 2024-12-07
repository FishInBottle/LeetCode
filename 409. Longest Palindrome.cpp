/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome 
that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

Example 1:
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

Constraints:
1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.

https://leetcode.com/problems/longest-palindrome/description/
*/

class Solution {
public:
    int longestPalindrome(string s) {
        uint16_t i = 0, hasOdd = 0, length = 0;
        uint16_t alphabet[52] = {0};

        // Calculate the count for each alphabet
        while ('\0' != s[i]) {
            if (s[i] < 'a')
                alphabet[s[i] - 'A']++;
            else
                alphabet[s[i] - 'a' + 26]++;
            i++;
        }

        // Add all the even counts since they're symmetrical, and plus 1 if
        // there is an odd
        for (i = 0; i < 52; i++) {
            if (0 == (alphabet[i] % 2))
                length += alphabet[i];
            else {
                //For an odd count n, add the (n -1) and remain 1
                if (alphabet[i] > 1)
                    length += alphabet[i] - 1;
                hasOdd = 1;
            }
        }

        return length + hasOdd;
    }
};