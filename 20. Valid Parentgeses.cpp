/**
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
 */

class Solution {
public:
    bool isValid(string s) {
	    string chk_str;

        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
            case '[':
            case '{':
                /* Push all the open brackets into the string for comparison */
                chk_str.push_back(s[i]);
                break;

            case ')':
                if (!chk_str.empty())
                {
                    if ('(' == chk_str.back())
                    {
                        chk_str.pop_back();
                    }
                    else
                    {
                        /* Compare mismatch */
                        return false;
                    }
                }
                else
                {
                    /* the number of close brackets is more than open brackets */
                    return false;
                }
                break;

            case ']':
                if (!chk_str.empty())
                {
                    if ('[' == chk_str.back())
                    {
                        chk_str.pop_back();
                    }
                    else
                    {
                        /* Compare mismatch */
                        return false;
                    }
                }
                else
                {
                    /* the number of close brackets is more than open brackets */
                    return false;
                }
                break;

            case '}':
                if (!chk_str.empty())
                {
                    if ('{' == chk_str.back())
                    {
                        chk_str.pop_back();
                    }
                    else
                    {
                        /* Compare mismatch */
                        return false;
                    }
                }
                else
                {
                    /* the number of close brackets is more than open brackets */
                    return false;
                }
                break;

            default:
                break;
            }
        }

        /* Invalid if chk_str is not empty */
	    return chk_str.empty();
    }
};