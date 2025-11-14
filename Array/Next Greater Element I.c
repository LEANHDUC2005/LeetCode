/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct stack
{
    int data[1000];
    int top;
};

void init(struct stack *S)
{
    S->top = -1;
}

int isEmpty(struct stack* S)
{
    return ( S->top == -1 );
}

int isFull(struct stack* S)
{
    return ( S->top == 1000 - 1 );
}

void push(struct stack* S, int x)
{
    if ( !isFull(S) )
    {
        S->top++;
        S->data[S->top] = x;
    }
}

int pop(struct stack* S)
{
    if ( !isEmpty(S) )
    {
        int x = S->data[S->top];
        S->top--;
        return x;
    }
    return -1;
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    struct stack S;
    init(&S);

    int hash[10000];
    memset(hash, -1, sizeof(hash));
    int *return_arr = (int*)malloc( nums1Size * sizeof(int) );

    push(&S, nums2[0]);
    printf("%d", S.top);

    for(int i=0; i<nums2Size; i++)
    {
        while( !isEmpty(&S) && nums2[i] > S.data[S.top] )
        {
            hash[pop(&S)] = nums2[i];
        }
        push(&S, nums2[i]);

    }

    for(int i=0; i<nums1Size; i++)
    {
        return_arr[i] = hash[nums1[i]];
    }

    *returnSize = nums1Size;
    return return_arr;

} 
