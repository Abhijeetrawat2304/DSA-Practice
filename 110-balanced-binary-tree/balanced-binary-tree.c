/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int height(struct TreeNode* root, int *valid) {

    if(root == NULL) {
        return 0;
    }

    int l = height(root->left, valid);
    int r = height(root->right, valid);

    if(abs(l-r) > 1) {
        *valid = 0;
    }

    if(l > r) {
        return 1 + l;
    }
    else {
        return 1 + r;
    }
}

bool isBalanced(struct TreeNode* root) {

    int valid = 1;

    height(root, &valid);

    return valid;
}