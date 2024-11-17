/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, 
the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, 
which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. 
Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example 1:
Input: n = 5, bad = 4
Output: 4

Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.

Example 2:
Input: n = 1, bad = 1
Output: 1
 
Constraints:
1 <= bad <= n <= 2^31 - 1

https://leetcode.com/problems/first-bad-version/
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

/**
 * Note: Set gooVer to 0 because you don't know whether the 1st version is good or bad.
 */

class Solution {
public:
    int firstBadVersion(int n) {
#if 0 //straight
        uint64_t goodVer = 0, badVer = n, chkVer;
#else //save memory
        int goodVer = 0, badVer = n, chkVer;
#endif
        bool res;
        
        /* Binary search to find the 1st bad version */
        chkVer = (goodVer + badVer) / 2;
        while (badVer != chkVer && goodVer != chkVer) {
            res = isBadVersion(chkVer);
            if (true == res) {
                badVer = chkVer;
            } else {
                goodVer = chkVer;
            }
#if 0 //straight
            chkVer = (goodVer + badVer) / 2;
#else //save memory
            chkVer = (badVer - goodVer) / 2 + goodVer;
#endif
        }

        return badVer;
    }
};