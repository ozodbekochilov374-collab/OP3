#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char s[200];
    int j = 0;   

    printf("Satr kiriting: ");
    if (fgets(s, sizeof(s), stdin) == NULL) {
        return 1;
    }

    s[strcspn(s, "\n")] = '\0';

    for (int i = 0; s[i] != '\0'; i++) {
        if (!ispunct((unsigned char)s[i])) {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';  

    printf("Natija: %s\n", s);
    return 0;
}