/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
     int count;
    struct ListNode*temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    count=count-n;
    if(count==0){
        temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    struct ListNode*prevnode=NULL;
    struct ListNode*currnode=head;
    while(count--){
        prevnode=currnode;
        currnode=currnode->next;
    }
    prevnode->next=currnode->next;
    free(currnode);
    return head;

    
}