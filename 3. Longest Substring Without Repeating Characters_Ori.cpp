// VS_Debug.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
    bool isUnique(string subStr)
    {
#if 0
        int len = subStr.length();
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (i == j)
                {
                    continue;
                }
                else
                {
                    if (subStr[i] == subStr[j])
                    {
                        return false;
                    }
                }
            }
        }
#else
        string chk_str;

        for (int i = 0; i < subStr.length(); i++)
        {
            if (!chk_str.find(subStr[i]))
            {
                chk_str.push_back(subStr[i]);
            }
            else
            {
                return false;
            }
        }
#endif
        return true;
    }

public:
    int lengthOfLongestSubstring(string s) {
#if 0
        int len = s.length();
        int max_length;

        switch (len)
        {
        case 0:
            return 0;

        case 1:
            return 1;

        default:
            max_length = 1;
            for (int window_size = 2; window_size <= len; window_size++)
            {
                for (int i = 0; i <= (len - window_size); i++)
                {
                    if (isUnique(s.substr(i, window_size)))
                    {
                        max_length = window_size;
                        break;
                    }
                }
            }
            return max_length;
        }
#else
        int lSide = 0, rSide;
        int maxLength = 0;
        string subStr = "";

        for (rSide = 0; rSide < s.length();)
        {
            if (subStr.npos == subStr.find(s[rSide], 0))
            {
                subStr.push_back(s[rSide]);
                rSide++;
                
                if ((rSide - lSide) > maxLength)
                {
                    maxLength = rSide - lSide;
                }
            }
            else
            {
                lSide++;
                subStr.erase(0, 1);
            }
        }

        return maxLength;
#endif
    }
};

int main()
{
    string s = {"abcabcbb"};
    Solution sol;

    sol.lengthOfLongestSubstring(s);
    
    return 1;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
