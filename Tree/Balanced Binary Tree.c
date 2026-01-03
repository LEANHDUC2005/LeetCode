/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int a, int b){
    return (a > b) ? a : b;
}

int PreOrderHeight(struct TreeNode* root, int* flag){
    if ( !root ) return 0;
    int l = PreOrderHeight(root->left, flag);
    int r = PreOrderHeight(root->right, flag);
    if ( abs(l - r) > 1 ){
        *flag = 0;
    }
    return max(l, r) + 1;
}
bool isBalanced(struct TreeNode* root) {
    int flag = 1;
    PreOrderHeight(root, &flag);
    return flag;
}
