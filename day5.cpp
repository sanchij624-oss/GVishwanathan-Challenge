//leetcode 141
//linked list cycle 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                ListNode *ptr = head;

                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }

                return ptr;
            }
        }

        return nullptr;
    }
};


//leetcode 234
//paindrome linked list


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr, *curr = slow;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        ListNode *p1 = head, *p2 = prev;
        while (p2) {
            if (p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};