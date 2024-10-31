/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:
1 <= s.length, t.length <= 5 * 10^4
s and t consist of lowercase English letters.
 */

/*
Count all the counts of each letter, and check the count of each letter is match or not
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int letters[26] = {0};
        
        /* Count all the counts of each letter in s */
        for(int i=0;i<s.size();i++)
        {
            letters[s[i] - 'a']++;
        }

        /* Decrease all the counts of each letter in t */
        for(int i=0;i<t.size();i++)
        {
            letters[t[i] - 'a']--;
        }

        /* Check if all the values in this array are 0 */
        for(int i=0;i<26;i++)
        {
            if(0 != letters[i])
                return false;
        }
        return true;
    }
};