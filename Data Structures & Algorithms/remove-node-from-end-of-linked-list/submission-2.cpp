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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* explorer = head;

        if (!head || !head->next) return nullptr;

        for (int i = 0; i < n; ++i) {
            explorer = explorer->next;
        }

        if (!explorer) {
            return head->next;
        }

        while (explorer) {
            prev = curr;            
            curr = curr->next;
            explorer = explorer->next;
        }

      prev->next = curr->next;
      delete curr;

      return head;  
    }
};
