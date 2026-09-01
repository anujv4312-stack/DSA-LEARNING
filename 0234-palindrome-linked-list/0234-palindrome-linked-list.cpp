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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* current = head;
        while(current != nullptr){
            ListNode* nextnode = current->next;
            current->next = prev;
            prev = current;
            current = nextnode;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newhead = slow->next;
        ListNode* second = reverse(slow->next);
        ListNode* first = head;

        while(first != newhead && second != nullptr){
            if(first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};