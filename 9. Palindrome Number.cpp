/*
These are also palindrome numbers: 11, 0
*/ 



class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }
        else
        {
            /* Max number is 2^31 -1 = 2,147,483,647, total 10 digits */
            int ar[10] = {0};
            int totalLen, verifyLen, i = 0;
            while(0 != x / 10)
            {
                ar[i] = x % 10;
                x /= 10;
                i++;
            }
            ar[i] = x % 10;
            totalLen = ++i;
            
            /* Check total length of this number is odd or even to calculate length to be verified */
            if (0 == (totalLen % 2))
            {
                verifyLen = totalLen / 2;
            }
            else
            {
                verifyLen = (totalLen - 1) / 2;
            }

            /* Handling one digit */
            if(0 == verifyLen)
            {
                return true;
            }

            for(i = 0; i < verifyLen; i++)
            {
                if(ar[i] != ar[totalLen - i - 1])
                {
                    return false;
                }
            }
            return true;
        }
    }
};