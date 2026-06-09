#define N 26

bool isAnagram(char* s, char* t) {
    int table[N] = {0};

    unsigned int sLength = strlen(s);
    unsigned int tLength = strlen(t);

    if (sLength != tLength) {
        return false;
    }

    for (int i = 0; i < sLength; i++) {
        char cS = s[i];
        char cT = t[i];

        int numberCS = cS - 'a';
        int numberCT = cT - 'a';

        table[numberCS]++;
        table[numberCT]--;

    }

    for (int j = 0; j < N; j++) {
        if (table[j] != 0) {
            return false;
        }
    }
    return true;
}