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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    /*
    归并排序 时间复杂度O(nlogn)
    */

    ListNode *sortList(ListNode *head)
    {
        // 递归退出条件 ListNode.size() <= 1
        if (head == nullptr || head->next == nullptr)
            return head;

        // 二分
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre = nullptr;
        while (fast != nullptr && fast->next != nullptr)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // 分开链表
        pre->next = nullptr;
        ListNode *l = sortList(head);
        ListNode *r = sortList(slow);

        return merge(l, r);
    }

    /*
    merge 合并两个链表
    */
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;

        while (head1 && head2)
        {
            if (head1->val <= head2->val)
            {
                cur->next = head1;
                cur = cur->next;
                head1 = head1->next;
            }
            else
            {
                cur->next = head2;
                cur = cur->next;
                head2 = head2->next;
            }
        }

        cur->next = head1 ? head1 : head2;

        return dummyHead->next;
    }
};