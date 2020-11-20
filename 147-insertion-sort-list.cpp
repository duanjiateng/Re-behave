/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *last = head;
        ListNode *cur = head->next;

        while (cur != nullptr)
        {
            // 不需要插入
            if (last->val <= cur->val)
            {
                last = last->next;
            }
            // 从头遍历插入到合适位置
            else
            {
                ListNode *pre = dummyHead;

                while (pre->next->val <= cur->val)
                {
                    pre = pre->next;
                }
                last->next = cur->next;
                cur->next = pre->next;
                pre->next = cur;
            }
            cur = last->next;
        }

        return dummyHead->next;
    }
};