#define N 26

bool isAnagram(char* s, char* t) {
    int *sTable[N];
    int *tTable[N];

    for (int i = 0; i < N; i++) {
        sTable[i] = 0;
        tTable[i] = 0;
    }

    unsigned int sLength = strlen(s);
    unsigned int tLength = strlen(t);

    if (sLength != tLength) {
        return false;
    }

    for (int j = 0; j < sLength; j++) {
        char cS = s[j];
        char cT = t[j];

        int numberCS = cS - 'a';
        int numberCT = cT - 'a';

        sTable[numberCS]++;
        tTable[numberCT]++;
    }

    for (int k = 0; k < N; k++) {
        if (!(sTable[k] == tTable[k])) {
            return false;
        }
    }
    return true;
}