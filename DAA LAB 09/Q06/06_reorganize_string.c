// Problem 6: Reorganize String with K-Distance Apart
// This program tries to rebuild the string while making sure identical characters stay at least K positions apart.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Final rearranged output string.

char result[1000];
int count[256];
int totalLen;

// Check whether placing this character at the current index violates the distance rule.

int isValidPlacement(int pos, char ch, int k) {
    for (int i = pos - k; i < pos; i++) {
        if (i >= 0 && result[i] == ch) return 0;
    }
    return 1;
}

int solve(int pos, int k) {
    if (pos == totalLen) return 1;

    int bestChar = -1;
    int bestFreq = -1;

    for (int ch = 0; ch < 256; ch++) {
        if (count[ch] > 0 && isValidPlacement(pos, (char)ch, k) && count[ch] > bestFreq) {
            bestFreq = count[ch];
            bestChar = ch;
        }
    }

    if (bestChar == -1) return 0;

    result[pos] = (char)bestChar;
    count[bestChar]--;
    if (solve(pos + 1, k)) return 1;
    count[bestChar]++;
    return 0;
}

// Main routine: count characters, greedily build the result, and print it if valid.

int main() {
    char s[1000];
    int k;
    scanf("%s %d", s, &k);

    memset(count, 0, sizeof(count));
    for (int i = 0; s[i] != '\0'; i++) {
        count[(unsigned char)s[i]]++;
    }

    totalLen = strlen(s);
    if (solve(0, k)) {
        printf("%s\n", result);
    } else {
        printf("\n");
    }
    return 0;
}
