/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  
    struct ListNode* temp1 = l1;
    struct ListNode* temp2 = l2;

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    int carry = 0;

    while (temp1 != NULL || temp2 != NULL || carry != 0) {

        int val1 = 0;
        int val2 = 0;

        if (temp1 != NULL) {
            val1 = temp1->val;
        }

        if (temp2 != NULL) {
            val2 = temp2->val;
        }

        int sum = val1 + val2 + carry;

        int digit = sum % 10;
        carry = sum / 10;

        struct ListNode* newNode =
            (struct ListNode*)malloc(sizeof(struct ListNode));

        newNode->val = digit;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

        if (temp1 != NULL) {
            temp1 = temp1->next;
        }

        if (temp2 != NULL) {
            temp2 = temp2->next;
        }
    }

    return head;

    
}