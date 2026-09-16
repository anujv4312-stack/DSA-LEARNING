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
    ListNode* findkth(ListNode* head,int k){
        int cnt = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            cnt++;
            if(cnt == k){
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    ListNode* reverse(ListNode* head){
    ListNode* prev=nullptr;
         ListNode* temp=head;
         while(temp!=nullptr){
           ListNode* front=temp->next;
            temp->next=prev;
             prev=temp;
            temp=front;
           
            
         }
    return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevnode = nullptr;
        ListNode* nextnode = nullptr;
        while(temp!= nullptr){
            ListNode* kthnode = findkth(temp,k);
            if(kthnode == nullptr){
                if(prevnode != nullptr){
                    prevnode->next = temp;
                }
                break;
            }
            nextnode = kthnode->next;
            kthnode->next = nullptr;
            reverse(temp);

        if(temp == head){
            head = kthnode;
        }
        else{
            prevnode->next = kthnode;
        }
        prevnode = temp;
        temp = nextnode;
        }
        return head;
    }
};