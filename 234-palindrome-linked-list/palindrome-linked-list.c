/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
 if(head == NULL || head->next == NULL){
        return 1;
    }

    int count = 0;
    struct ListNode* temp = head;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    count /= 2;

    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while(count--){
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;

    struct ListNode* front;
    prev = NULL;

    while(curr != NULL){
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    struct ListNode* head1 = head;
    struct ListNode* head2 = prev;

    while(head1 != NULL && head2 != NULL){
        if(head1->val != head2->val){
            return 0;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    return 1;
    
}