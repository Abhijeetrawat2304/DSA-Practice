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
 void postorder(struct TreeNode*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    ans[idx++]=root->val;
  
 }
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    idx=0;
    postorder(root);
    *returnSize=idx;
    return ans;
    
}