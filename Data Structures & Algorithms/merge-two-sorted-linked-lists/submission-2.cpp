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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) return nullptr;
        
        ListNode* head = new ListNode();
        ListNode* agent = head;
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* prev = nullptr;

        while (p1 && p2) {
            if (p1->val < p2->val) {
                agent->val = p1->val;
                p1 = p1->next;
            } else {
                agent->val = p2->val;
                p2 = p2->next;
            }
            
            prev = agent;
            agent->next = new ListNode();
            agent = agent->next;
        }

        while (p1) {
            agent->val = p1->val;
            p1 = p1->next;
            prev = agent;
            agent->next = new ListNode();
            agent = agent->next;
        }

        while (p2) {
            agent->val = p2->val;
            p2 = p2->next;
            prev = agent;
            agent->next = new ListNode();
            agent = agent->next;
        }

        delete agent;
        prev->next = nullptr;

        return head;
    }
};
