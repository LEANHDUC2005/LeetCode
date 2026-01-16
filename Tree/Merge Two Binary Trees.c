/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void modifyTree(struct TreeNode** root2, struct TreeNode* root1){
    if ( !root1 ) return;
    else{
        if(*root2){
            (*root2)->val += root1->val;
        }
        else{
            (*root2) = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            (*root2)->val = root1->val;
            (*root2)->left = NULL;
            (*root2)->right = NULL;
        }
         modifyTree(&(*root2)->left, root1->left);
         modifyTree(&(*root2)->right, root1->right);
    }

}
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    modifyTree(&root2, root1);
    return root2;
}
