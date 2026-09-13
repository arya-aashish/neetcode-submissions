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
     if (head==nullptr)
        return head;

     int size= 0;
     ListNode *temp=head;
     while (temp!=nullptr){
        size++;
        temp=temp->next;
     }
     if (size==n)
        return head->next;
     int counter= size-n;
     ListNode *header=head;
     while (counter!=1)
     {
        head=head->next;
        counter--;
     }
     temp=head;
     head=head->next;
     ListNode *temp1=head;
     head=head->next;
     ListNode *temp2=head;

     delete(temp1);
     temp->next=temp2;

     return header;



    }
};
