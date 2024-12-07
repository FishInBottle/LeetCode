/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

https://leetcode.com/problems/add-binary/description/
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0, op, chkTimes;
        string sum;

        chkTimes = (a.length() > b.length()) ? a.length() : b.length();
        chkTimes++; // Add one more check if carry happens

        for (int k = 0; k < chkTimes; k++) {
            // Sum(a, b, carry) for that digit
            op = 0;
            if (i >= 0) // Error check before operation
                op += a[i] - '0';
            if (j >= 0) // Error check before operation
                op += b[j] - '0';
            op += carry;
            carry = 0;

            // Insert a digit to the head of current string
            switch (op) {
            case 0:
                if ((i >= 0) || (j >= 0))
                    sum.insert(0, "0");
                break;

            case 1:
                sum.insert(0, "1");
                break;

            case 2:
                sum.insert(0, "0");
                carry = 1;
                break;

            case 3:
                sum.insert(0, "1");
                carry = 1;
                break;

            default:
                break;
            }

            // To higher digit with error check
            if (i >= 0)
                i--;
            // To higher digit with error check
            if (j >= 0)
                j--;
        }
        return sum;
    }
};
