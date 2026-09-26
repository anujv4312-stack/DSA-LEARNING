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
    ListNode* findtail(ListNode* head,int len){
        int cnt = 0;
        ListNode* temp = head;
        while(temp->next != nullptr){
            cnt++;
            if(cnt == len){
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0){
            return head;
        }
        ListNode*  tail = head;
        int len = 1;
        while(tail->next != nullptr){
            len++;
            tail = tail->next;
        }
        if(k%len == 0) return head;
        k = k% len;
        tail->next = head;
        ListNode* newtail = findtail(head,len-k);
        head = newtail->next;
        newtail->next = nullptr;
        return head;
    }
};