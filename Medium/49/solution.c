#define N 26

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    if (strsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = malloc(0);
        return malloc(0);
    }
    
    char*** result = malloc(strsSize * sizeof(char**));
    int* colSizes = malloc(strsSize * sizeof(int));
    *returnSize = 0;

    int blueprints[strsSize][N];
    memset(blueprints, 0, sizeof(blueprints));

    for (int i = 0; i < strsSize; i++) {
        int table[N] = {0};
        for (int j = 0, wordLength = strlen(strs[i]); j < wordLength; j++) {
            unsigned int c = strs[i][j] - 'a';
            table[c]++;
        }

        bool foundMatch = false;
        int matchIndex = -1;
        for (int j = 0; j < *returnSize; j++) {
            bool isPerfectMatch = true;

            for (int k = 0; k < N; k++) {
                if (blueprints[j][k] != table[k]) {
                    isPerfectMatch = false;
                    break;
                }
            }

            if (isPerfectMatch) {
                foundMatch = true;
                matchIndex = j;
                break;
            }
        }

        if (!foundMatch) {
            for (int k = 0; k < N; k++) {
                blueprints[*returnSize][k] = table[k];
            }

            result[*returnSize] = malloc(1 * sizeof(char*));
            
            result[*returnSize][0] = strs[i];
            colSizes[*returnSize] = 1;

            (*returnSize)++;
        } else {
            int currentSize = colSizes[matchIndex];

            result[matchIndex] = realloc(result[matchIndex], (currentSize + 1) * sizeof(char*));

            result[matchIndex][currentSize] = strs[i];

            colSizes[matchIndex]++;
        }
    }
    *returnColumnSizes = colSizes; 
    return result;
}