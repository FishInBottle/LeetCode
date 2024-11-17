/*
Given two strings ransomNote and magazine, 
return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.

Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true

Constraints:
1 <= ransomNote.length, magazine.length <= 10^5
ransomNote and magazine consist of lowercase English letters.

https://leetcode.com/problems/ransom-note/description/
 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
#if 0
        std::map<char, int> counts;
#else
        int counts[26] = {0};
#endif

        /* Count every alphabet in magazine */
        for (char ch : magazine) {
#if 0
            counts[ch] += 1;
#else
            counts[ch - 'a'] += 1;
#endif
            ch++;
        }

        /* Decrease the count of corresponding alphabet */
        for (char ch : ransomNote) {
#if 0
            counts[ch] -= 1;
#else
            counts[ch - 'a'] -= 1;
#endif
            ch++;
        }

        /* Check results, if any count is below 0, it means ransomeNote requires more letters than the magazine gives */
        for (char ch = 'a'; ch <= 'z'; ch++) {
#if 0
            if (0 > counts[ch])
#else
            if (0 > counts[ch - 'a'])
#endif
                return false;
        }
        return true;
    }
};