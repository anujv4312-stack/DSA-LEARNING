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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       int n1 = 0;
       int n2 = 0;
       int cnt = 0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while(temp1 != nullptr){
            n1++;
            temp1 = temp1->next;
        }
        while(temp2 != nullptr){
            n2++;
            temp2 = temp2->next;
        }
        temp1 = headA;
        temp2 = headB;
        if(n1>n2){
            cnt = n1-n2;
            
            for(int i=0;i<cnt;i++){
                temp1 = temp1->next;
            }
        }
        else {
            cnt = n2-n1;
            
            for(int i = 0;i<cnt;i++){
                temp2 = temp2->next;
            }
        }
        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1 == temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
            
        }
        return nullptr;
    }
};