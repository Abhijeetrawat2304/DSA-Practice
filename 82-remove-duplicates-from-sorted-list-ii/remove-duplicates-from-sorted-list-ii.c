/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
  if (head == NULL || head->next == NULL) {
    return head;
}

struct ListNode* prev = NULL;
struct ListNode* curr = head;

while (curr != NULL) {

    if (curr->next != NULL && curr->val == curr->next->val) {

        struct ListNode* temp = curr;

        while (temp->next != NULL && temp->val == temp->next->val) {
            temp = temp->next;
        }

        temp = temp->next;

        while (curr != temp) {
            struct ListNode* del = curr;
            curr = curr->next;
            free(del);
        }

        if (prev == NULL) {
            head = temp;
        } else {
            prev->next = temp;
        }

    } else {
        prev = curr;
        curr = curr->next;
    }
}

return head;
}