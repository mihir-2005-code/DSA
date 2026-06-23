class Solution {
public:

    ListNode* reverseLinkedlist(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newHead = reverseLinkedlist(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }

    bool isPalindrome(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverseLinkedlist(slow->next);

        ListNode* first = head;
        ListNode* second = newHead;

        while (second != NULL) {
            if (first->val != second->val) {
                reverseLinkedlist(newHead); // restore
                return false;
            }

            first = first->next;
            second = second->next;
        }

        reverseLinkedlist(newHead); // restore
        return true;
    }
};