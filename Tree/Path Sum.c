/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if( !root ) return false;
    if( !root->left && !root->right ){
        if ( targetSum - root->val == 0 ) return true;
    }
    targetSum -= root->val;
    return hasPathSum(root->right, targetSum) || hasPathSum(root->left, targetSum);
}
