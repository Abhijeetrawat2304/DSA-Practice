/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int count=0;
 void inorder(struct TreeNode*root,int arr[]){
    if(root==NULL){
        return;
    }
    inorder(root->left,arr);
    arr[count]=root->val;
    count++;
    inorder(root->right,arr);
 }
int kthSmallest(struct TreeNode* root, int k) {
    int arr[10000];
    count=0;
    inorder(root ,arr);
    return arr[k-1];

    
}