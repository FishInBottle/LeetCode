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
#if 1
    ListNode *head = nullptr; //Always point to the 1st node of sum list
    ListNode* appendDigitList(int digit) {
        static ListNode *cur; //Always point to the last node of sum list
        ListNode *tmp = new ListNode(digit);

        if (nullptr == head)
        {
            head = tmp;
            cur = head;
        }
        else
        {
            cur->next = tmp;
            cur = cur->next;
        }

        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int digit, carrier = 0;
        ListNode *result;

        if((0 == l1->val) && (nullptr == l1->next)
        && (0 == l2->val) && (nullptr == l2->next))
        {
            return new ListNode(0);
        }
        else
        {
            while(nullptr != l1 || nullptr != l2)
            {
                //Handle carrier
                if(0 != carrier)
                {
                    digit = 1;
                }
                else
                {
                    digit = 0;
                }
                carrier = 0;

                if(nullptr != l1 && nullptr != l2)
                {
                    digit += l1->val + l2->val;
                    l1 = l1->next;
                    l2 = l2->next;
                }
                else if(nullptr != l1)
                {
                    digit += l1->val;
                    l1 = l1->next;
                }
                else //nullptr != l2
                {
                    digit += l2->val;
                    l2 = l2->next;
                }

                if(9 < digit)
                {
                    carrier = 1;
                    digit -= 10;
                }
                result = appendDigitList(digit);
            }

            if(0 != carrier)
            {
                result = appendDigitList(carrier);
            }

            return result;
        }
    }
#else
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long num1 = 0, num2 = 0, sum;
        int i, j, ar[101];
        ListNode *head = nullptr;
        ListNode *cur, *tmp;

        i = 0;
        while(l1 != nullptr)
        {
            num1 += l1->val * pow(10, i);
            l1 = l1->next;
            i++;
        }
        i = 0;
        while(l2 != nullptr)
        {
            num2 += l2->val * pow(10, i);
            l2 = l2->next;
            i++;
        }
        sum = num1 + num2;

        i = 0;
        while((0 != sum) && (i < 101))
        {
            ar[i] = sum % 10;
            sum /= 10;
            i++;
        }
        
        /* Create linked list for sum */
        if(0 == i)
        {
            return new ListNode(0);
        }
        else
        {
            for(j = 0; j < i; j++)
            {
                cur = new ListNode(ar[j]);
                if (nullptr == head)
                {
                    head = cur;
                }
                else
                {
                    tmp = head;
                    while(nullptr != tmp->next)
                    {
                        tmp = tmp->next;
                    }
                    tmp->next = cur;
                }
            }
        }

        return head;
    }
#endif
};