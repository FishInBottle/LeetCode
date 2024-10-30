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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *result = nullptr;

        if (nullptr == list1)
        {
            return list2;
        }
        else if (nullptr == list2)
        {
            return list1;
        }
        else
        {
            if (list1->val <= list2->val)
            {
                result = list1;
                result->next = mergeTwoLists(list1->next, list2);
            }
            else
            {
                result = list2;
                result->next = mergeTwoLists(list1, list2->next);
            }
            
        }

        return result;
    }
};
