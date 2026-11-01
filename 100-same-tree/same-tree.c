/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
    
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {

    // Case 1: Both nodes are NULL
    if(p == NULL && q == NULL) {
        return true;
    }

    // Case 2: Only one node is NULL
    if(p == NULL || q == NULL) {
        return false;
    }

    // Case 3: Compare current node values
    if(p->val != q->val) {
        return false;
    }

    // Case 4: Compare left and right subtrees
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);

    return left && right;
}

