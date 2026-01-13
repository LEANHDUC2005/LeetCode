/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSametree(struct TreeNode* root, struct TreeNode* subRoot){
    if ( !root && !subRoot ) return true;
    if ( !root || !subRoot ) return false;
    if ( root->val != subRoot->val ) return false;
    return isSametree(root->left, subRoot->left) && isSametree(root->right, subRoot->right);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if ( !root ) return false;
    return isSametree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
