
//Definition for singly-linked list.
struct ListNode {
     int val;
     struct ListNode *next;
 };

struct Stack
{
    int data[5000];
    int top;
}S;
void init(struct Stack *S)
{
    S->top = -1;
}
void push(struct Stack *S, int x)
{
    if ( S->top != 5000 )
    {
        S->top++;
        S->data[S->top] = x;
    }
    return;
}

int pop(struct Stack *S)
{
    if ( S->top != -1)
    {
        int x = S->data[S->top];
        S->top--;
        return x;
    }
    return -1;
}
struct ListNode* reverseList(struct ListNode* head) {
    init(&S);
    struct ListNode* temp = head;
    struct ListNode* temp2 = head;
    while(temp != NULL)
    {
        push(&S, temp->val);
        temp = temp->next;
    }

    while(temp2 != NULL)
    {
        temp2->val = pop(&S);
        temp2 = temp2->next;
    }
    return head;   
}