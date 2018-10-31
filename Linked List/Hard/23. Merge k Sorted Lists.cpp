/* LeetCode 23. Merge k Sorted Lists
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 * 
 * Example:
 * 
 * Input:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 */
 
// Merge lists one by one 

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        ListNode* l = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            l = mergeTwoLists(l, lists[i]);
        }
        return l;
    }

private:   
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* head = l1;    

        if (l1->val > l2->val) { 
            head = l2; 
            l2 = l2->next; 
        } else { 
            l1 = l1->next; 
        }

        ListNode* p = head;     

        while (l1 && l2) {
            if (l1->val < l2->val) { 
                p->next = l1; 
                l1 = l1->next; 
            } else { 
                p->next = l2; 
                l2 = l2->next; 
            }
            p = p->next;
        }

        if (l1)  
            p->next=l1;
        else    
            p->next=l2;

        return head;
    }
};

// Priority queue:

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int> q;
        for (int i = 0; i < lists.size(); i++) {
            while (lists[i] != NULL) {
                q.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        ListNode head(0);
        ListNode *tail = &head;
        while (!q.empty()) {
            tail = new ListNode(q.top());
            tail->next = head.next;
            head.next = tail;
            q.pop();
        }
        return head.next;
    }
};
