/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void invert(struct TreeNode* root){
    if ( !root ) return;
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invert(root->left);
    invert(root->right);
}
struct TreeNode* invertTree(struct TreeNode* root) {
    invert(root);
    return root;
}
