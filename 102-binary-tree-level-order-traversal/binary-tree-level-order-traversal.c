/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize=0;
    if(root==NULL){
        *returnColumnSizes=NULL;
        return NULL;
    }
    int**ans=(int**)malloc(10000*sizeof(int*));
    *returnColumnSizes=(int*)malloc(10000*sizeof(int));
    struct TreeNode*queue[10000];
    int front=0;
    int rear=0;
    queue[rear]=root;
    rear++;
    
    while(front<rear){
        int size=rear-front;
        int* level = (int*)malloc(size * sizeof(int));
        for(int i=0;i<size;i++){
            struct TreeNode*temp=queue[front];
            front++;

            level[i]=temp->val;
            if(temp->left!=NULL){
                queue[rear]=temp->left;
                rear++;
            }
            if(temp->right!=NULL){
                queue[rear]=temp->right;
                rear++;
            }
        }
        ans[*returnSize] = level;

        (*returnColumnSizes)[*returnSize] = size;

        (*returnSize)++;
    }
    return ans;
    
}