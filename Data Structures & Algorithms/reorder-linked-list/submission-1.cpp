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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // find middle
        ListNode* midPtr = head;
        ListNode* fastPtr = head;

        while (fastPtr->next && fastPtr->next->next) {
            midPtr = midPtr->next;
            fastPtr = fastPtr->next->next;
        }

        //reverse second half linked list
        ListNode* secondHead = midPtr->next;
        midPtr->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = secondHead;
        while (curr) {
            ListNode* next = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // merge them together
        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};
