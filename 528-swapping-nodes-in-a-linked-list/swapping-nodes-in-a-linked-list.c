/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode* temp = head;
 struct ListNode* first = head;
 struct ListNode* second = head;

 int count = 0;
 int pos;

  while(temp != NULL){
    count++;
    temp = temp->next;
  }

  pos = count - k + 1;

   for(int i = 1; i < k; i++){
    first = first->next;
  }

   for(int i = 1; i < pos; i++){
    second = second->next;
  }

 int x = first->val;
 first->val = second->val;
 second->val = x;

 return head;

    
}