/* LeetCode 24. Swap Nodes in Pairs
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * Example:
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * Note:
 * 
 * Your algorithm should use only constant extra space.
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 */
 
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
    ListNode* swapPairs(ListNode* head) {
        ListNode sentinel(0);
        sentinel.next = head;
        ListNode* curr = &sentinel;
        while (curr->next && curr->next->next) {
            ListNode *first = curr->next, *second = curr->next->next;
            first->next = second->next;
            curr->next = second;
            second->next = first;
            curr = first;
        }
        return sentinel.next;
        
    }
};
