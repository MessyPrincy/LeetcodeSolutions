#define N 5003

typedef struct node
{
    int val;
    struct node *next;
} node;

node *table[N];

unsigned int hashVal (int val);

bool containsDuplicate(int* nums, int numsSize) {
    for (int i = 0; i < N; i++) {
        table[i] = NULL;
    }

    for (int j = 0; j < numsSize; j++) {
       unsigned int hashed = hashVal(nums[j]);

        node *ptr = table[hashed];
        while (ptr != NULL) {
            if (ptr->val == nums[j]) {
                return true;
            }
            ptr = ptr->next;
        }

        node *n = malloc(sizeof(node));
        
        n->val = nums[j];
        n->next = table[hashed];
        table[hashed] = n;
    }
    return false;
}

unsigned int hashVal (int val) {
    return (val & 0x7FFFFFFF) % N;
}