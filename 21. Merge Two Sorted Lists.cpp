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
    ListNode* head = nullptr;

    /**
    * @brief  Append the node into the merged list and remove it from the original list
    */
    ListNode *appendNode(ListNode* node)
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
