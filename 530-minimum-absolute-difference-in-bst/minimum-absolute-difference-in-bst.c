/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int prev;
int hasPrev = 0;
int minDiff = INT_MAX;
void inorder(struct TreeNode *root)
{
    if(root == NULL)
        return;

    inorder(root->left);

    if(hasPrev == 1)
    {
        int diff = root->val - prev;

        if(diff < minDiff)
            minDiff = diff;
    }

    prev = root->val;
    hasPrev = 1;

    inorder(root->right);
}

int getMinimumDifference(struct TreeNode *root)
{
    prev = 0;
    hasPrev = 0;
    minDiff = INT_MAX;

    inorder(root);

    return minDiff;
}