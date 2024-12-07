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
        chkTimes++; // Add one more check if carry happened

        for (int k = 0; k < chkTimes; k++) {
            op = 0;
            if (i >= 0)
                op += a[i] - '0';
            if (j >= 0)
                op += b[j] - '0';
            op += carry;
            carry = 0;
            // std::cout << "a[" << i << "]=" << a[i] - '0' << endl;
            // std::cout << "b[" << j << "]=" << b[j] - '0' << endl;
            // std::cout << "op=" << op << endl;

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

            default: //3
                sum.insert(0, "1");
                carry = 1;
                break;
            }
            // std::cout << sum << endl;
            if (i >= 0)
                i--;
            if (j >= 0)
                j--;
        }
        return sum;
    }
};
