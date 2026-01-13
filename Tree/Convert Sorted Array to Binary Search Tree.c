void build(struct TreeNode** root, int* nums, int left, int right){
    if ( left <= right ){
        int mid = left + (right - left)/2;
        (*root) = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        (*root)->val = nums[mid];
        (*root)->left = NULL;
        (*root)->right = NULL;
        build(&(*root)->left, nums, left, mid - 1);
        build(&(*root)->right, nums, mid + 1, right);
    }
    else return;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    build(&root, nums, 0, numsSize - 1);
    return root;
}
