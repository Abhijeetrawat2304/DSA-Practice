/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int ans[10000];
int idx=0;
void preorder(struct TreeNode*root){
    if(root==NULL){
        return;
    }
    ans[idx++]=root->val;
    preorder(root->left);
    preorder(root->right);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    idx=0;
    preorder(root);
    *returnSize=idx;
    return ans;
    
    
}
