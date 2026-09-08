/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode*temp=dummy;
    struct ListNode*temp1=list1;
    struct ListNode*temp2=list2;

    while(temp1!=NULL && temp2!=NULL){
        if(temp1->val<=temp2->val){
            temp->next=temp1;
            temp=temp1;
            temp1=temp1->next;
        } else{
            temp->next=temp2;
            temp=temp2;
            temp2=temp2->next;
        }
    }
    if(temp1!=NULL){
        temp->next=temp1;
    } else{
        temp->next=temp2;
    }

    struct ListNode*head=dummy->next;
    free(dummy);

    return head;
    
    
}