/**
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""

Explanation: There is no common prefix among the input strings.

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;

        /* Index of currently checking character (max is 200) */
        for(i = 0; i < 200; i++)
        {
            /* Traverse each string in the vector */
            for(int j = 0; j < strs.size(); j++)
            {
                /* Check if this string reaches the end */
                if (i < strs[j].size())
                {
                    /* Use 1st string to compare with the remained strings, once mismatch then out */
                    if (strs[0][i] != strs[j][i])
                    {
                        goto CHK_END;
                    }
                }
                else
                {
                    /* Reach the end of this string */
                    goto CHK_END;
                }
            }
        }

    CHK_END:
        return strs[0].substr(0, i);
    }
};