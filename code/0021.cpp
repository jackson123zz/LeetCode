// LeetCode-21.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
1、单链表操作，遍历每一个顺序链表，追加到新的链表中
*/

#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(-1);
		ListNode* current = head;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				current->next = l1;
				l1 = l1->next;
			} else {
				current->next = l2;
				l2 = l2->next;
			}
			current = current->next;
		}
		current->next = l1 ? l1 : l2;
		return head->next;
	}
};