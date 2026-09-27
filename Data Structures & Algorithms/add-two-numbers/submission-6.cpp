class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* prev = nullptr;
        int carry = 0;

        // Process overlapping parts
        while (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        // If l2 is longer, attach it to the end of l1
        if (l2 != nullptr) {
            prev->next = l2;
            l1 = l2; // Move l1 pointer to continue processing the rest of the list
        }

        // Process remaining nodes (if any) and carry
        while (l1 != nullptr) {
            int sum = l1->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            prev = l1;
            l1 = l1->next;
        }

        // If there's a final carry left over, attach a new node
        if (carry > 0) {
            prev->next = new ListNode(carry);
        }

        return head;
    }
};