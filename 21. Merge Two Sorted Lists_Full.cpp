// VS_Debug.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_set>

using namespace std;

/**
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptrptr) {}
 *     ListNode(int x) : val(x), next(nullptrptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(void)
    {
        val = 0;
        next = nullptr;
    }

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* nextPtr)
    {
        val = x;
        next = nextPtr;
    }
};

class Solution {
    ListNode* head = nullptr;

    /**
    * @brief  Append the node into the merged list and remove it from the original list
    */
    ListNode* appendNode(ListNode* node)
    {
        static ListNode* last;
        ListNode* tmp;

        if (nullptr != head)
        {
            last->next = node;
            last = last->next;
        }
        else
        {
            head = node;
            last = head;
        }
        node = node->next; //Remove this node from the original list
        last->next = nullptr; //Set the next pointer of last node to nullptr for the merged list
        return node;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        while (nullptr != list1 || nullptr != list2)
        {
            if (nullptr != list1 && nullptr != list2)
            {
                if (list1->val <= list2->val)
                {
                    list1 = appendNode(list1);
                }
                else if (list1->val > list2->val)
                {
                    list2 = appendNode(list2);
                }
            }
            else if (nullptr != list1)
            {
                list1 = appendNode(list1);
            }
            else
            {
                list2 = appendNode(list2);
            }
        }

        return head;
    }
};

ListNode* genTestCase(int usecase)
{
    ListNode* list = new ListNode(1);
    ListNode* tmp = list;

    switch (usecase)
    {
    case 1:
        tmp->next = new ListNode(2);
        tmp = tmp->next;
        tmp->next = new ListNode(4);
        break;

    case 2:
        tmp->next = new ListNode(3);
        tmp = tmp->next;
        tmp->next = new ListNode(4);
        break;
    }

    tmp = list;
    cout << tmp->val << endl;
    tmp = tmp->next;
    cout << tmp->val << endl;
    tmp = tmp->next;
    cout << tmp->val << endl;
    return list;
}

int main()
{
    Solution sol;

    sol.mergeTwoLists(genTestCase(1), genTestCase(2));
    
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
