/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void LeftRightNode(struct TreeNode* root, int** result, int* returnSize){
    if ( !root ) return;
    LeftRightNode(root->left, result, returnSize);
    LeftRightNode(root->right, result, returnSize);
    (*result)[*returnSize - 1] = root->val;
    (*returnSize)++;
    int *new_result = realloc(*result, (*returnSize) * sizeof(int));
    if ( new_result ) *result = new_result;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *result = (int*)malloc(sizeof(int));
    *returnSize = 1;
    if ( !result ) return NULL;
    LeftRightNode(root, &result, returnSize);
    (*returnSize)--;
    return result;
}
