/*
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

Constraints:
The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100

https://leetcode.com/problems/middle-of-the-linked-list/description/
 */

/**
 * Note: use two pointers to solve this problem.
 * Let the fast pointer always be 2 times faster than the slow pointer, 
 * when the fast pointer reach the end, the slow pointer will at the middle of the linked list
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head, *slow = head;
        uint8_t slow_cnt = 0;

        if(nullptr == head)
            return nullptr;

#if 0
        /* Return the 1st middle if 2 middle nodes */
        while(nullptr != fast->next)
#else
        /* Return the 2nd middle if 2 middle nodes */
        while(nullptr != fast)
#endif
        {
            fast = fast->next;
            slow_cnt++;
            if(2 == slow_cnt)
            {
                slow = slow->next;
                slow_cnt = 0;
            }
        }

        return slow;
    }
};