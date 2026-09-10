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
        if (head==nullptr || head->next==nullptr)
            return;

        ListNode *fast=head, *slow=head;

        
        ListNode *midpos=nullptr;
        while (fast!=nullptr && fast->next!=nullptr){
            midpos=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *prev= nullptr, *current=slow->next;

        while (current!=nullptr){
            ListNode *nextnode= current->next;
            current->next=prev;
            prev=current;
            current= nextnode;
        }
        slow->next=nullptr;

        ListNode *first=head, *second=prev;
        while (second!=nullptr){
            ListNode *temp1=first->next, *temp2=second->next;
            first->next=second;
            second->next=temp1;
            second=temp2;
            first=temp1;
        }
    }
};
