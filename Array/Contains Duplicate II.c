#define HASHSIZE 10000000

struct hash_node{
    int node_key;
    int node_value;
    struct hash_node* next;
};

void hash_init(struct hash_node **H)
{
    for(int i=0; i<HASHSIZE; i++)
    {
        H[i] = NULL;
    }
}

struct hash_node* insert_node(int nums_value, int nums_index)
{
    struct hash_node *p = (struct hash_node*)malloc(sizeof(struct hash_node));
    p->node_key = nums_value;
    p->node_value = nums_index;
    p->next = NULL;
    return p;
}

int hash_function(int nums_value)
{
    return ( nums_value % HASHSIZE + HASHSIZE ) % HASHSIZE;
}

void insert(struct hash_node** H, int nums_value, int nums_index)
{
    int hash_key = hash_function(nums_value);
    if ( H[hash_key] != NULL )
    {
        struct hash_node* Hnode = insert_node(nums_value, nums_index);
        Hnode->next = H[hash_key];
        H[hash_key] = Hnode;
    }
    else
    {
        H[hash_key] = (struct hash_node*)malloc(sizeof(struct hash_node));
        H[hash_key]->node_key = nums_value;
        H[hash_key]->node_value = nums_index;
        H[hash_key]->next = NULL;
    }
}

int search(struct hash_node **H, int nums_value)
{
    int search_hash = hash_function(nums_value);
    if ( H[search_hash] == NULL ) return -1;
    {
        struct hash_node *temp = H[search_hash];
        while( temp != NULL )
        {
            if ( temp->node_key == nums_value ) 
            {
                printf("Key : %d - Value: %d\n", temp->node_key, temp->node_value);
                return temp->node_value;
            }
               
        }
        return -1;
    }
}

void delete(struct hash_node **H,int nums_value, int nums_index)
{
    int delete_hash = hash_function(nums_value);
    if ( H[delete_hash] != NULL )
    {
        struct hash_node *temp = H[delete_hash];
        struct hash_node *prev = H[delete_hash];
        while(temp != NULL && temp->node_value == nums_index)
        {
            temp = temp->next;
        }
        if ( temp == NULL ) return;

        while(prev->next != temp && prev != NULL)
        {
            prev = prev->next;
        }
        prev->next = temp->next;
        free(temp);
        return;
    }
    return;
}
int free_hash(struct hash_node **H)
{
    if ( !H ) return 0;
    for(int i=0; i<HASHSIZE; i++)
    {
        struct hash_node *temp = H[i];
        while( temp != NULL )
        {
            struct hash_node *p = temp;
            temp = temp->next;
            free(p);
        }
        H[i] = NULL;
    }
    return 1;
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    clock_t start = clock();
    int left = 0;
    int right;
    struct hash_node *H[HASHSIZE];

    hash_init(H);
    if ( !H[1] ) printf("YES\n");

    int hashing;
    for(right = 0; right < numsSize; right++)
    {
        //printf("Left: %d Num[left]: %d | Right: %d Num[right]: %d\n", left, nums[left], right, nums[right]);
        if ( right - left > k )
        {
            delete(H, nums[left], left);
            left++;
        }
        if ( ( hashing = search(H, nums[right]) ) != -1 && ( right - hashing <= k ) )
        {
            //printf("Hash: %d, Right: %d", hashing , right);
            free_hash(H);
            return true;
        }
        insert(H, nums[right], right);
    }

    free_hash(H);
    return false;
}
