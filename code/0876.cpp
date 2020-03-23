/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
算法：
1、遍历单链表，返回单链表的长度len
2、再次遍历单链表，把长度为len/2的节点指针返回
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode* output = head;
        ListNode* tmp = head;
        while (tmp != NULL) {
            len++;
            tmp = tmp->next;
        }
        for (int i = 0; i < len / 2; i++) {
            output = output->next;
        }
        return output;
    }
};