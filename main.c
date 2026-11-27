#include <stdio.h>
#include <string.h>
#include <ctype.h>

void decryptLayer1(char *text, int shift) {
    shift = ((shift % 26) + 26) % 26;
    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper((unsigned char)text[i])) text[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A';
        else if (islower((unsigned char)text[i])) text[i] = ((text[i] - 'a' - shift + 26) % 26) + 'a';
    }
}
void decryptLayer2(char *text, const char *key) {
    size_t keyLen = strlen(key);
    if (keyLen == 0) return;
    for (int i = 0, j = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            int shift = tolower((unsigned char)key[j % keyLen]) - 'a';
            if (isupper((unsigned char)text[i])) text[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A';
            else text[i] = ((text[i] - 'a' - shift + 26) % 26) + 'a';
            // TODO: missing 1 line here (hint: it's an increment)
        }
    }
}
int main(void) {
    char ciphertext[] = "Avrrybde vq Mbbs Zpqoyz";
    int shiftKey1 = 99;
    char vigenereKey2[] = "RealKey";

    decryptLayer1(ciphertext, shiftKey1);
    decryptLayer2(ciphertext, vigenereKey2);

    printf("[Layer 2] Plaintext   : %s\n", ciphertext);
    return 0;
}
