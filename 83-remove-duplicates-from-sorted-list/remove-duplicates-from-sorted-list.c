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

    struct ListNode*prev=NULL;
    struct ListNode*curr=head;
    while(curr!=NULL){
        if(prev!=NULL && prev->val==curr->val){
            struct ListNode*temp=curr;
            prev->next=curr->next;
            curr=curr->next;
            free(temp);
        } else{
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
    
}