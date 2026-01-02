/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root, int* global_max) {
    if ( !root ) return 0;
    int l = maxDepth(root->left, global_max);
    int r = maxDepth(root->right, global_max);
    if ( l + r > *global_max )
    *global_max = l + r;
    if ( r >= l ){
        return ++r;
    }
    else return ++l;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int global_max = 0;
    maxDepth(root, &global_max);
    return global_max;
}
