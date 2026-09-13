/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
   if (head == NULL || left == right) {
    return head;
}

struct ListNode dummy;
dummy.next = head;

struct ListNode* prev = &dummy;

for (int i = 1; i < left; i++) {
    prev = prev->next;
}

struct ListNode* curr = prev->next;

for (int i = 0; i < right - left; i++) {

    struct ListNode* nextnode = curr->next;

    curr->next = nextnode->next;

    nextnode->next = prev->next;

    prev->next = nextnode;
}

return dummy.next;
    
}