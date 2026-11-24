#include <stdio.h>
#include <string.h>

int main(void)
{
    char words[100][50];   
    char temp[50];
    int n = 0;             

    FILE *f = fopen("words.txt", "r");
    if (f == NULL) {
        perror("words.txt ochilmadi");
        return 1;
    }

    while (n < 100 && fgets(words[n], 50, f) != NULL) {
        words[n][strcspn(words[n], "\n")] = '\0';   
        n++;
    }
    fclose(f);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    FILE *out = fopen("sorted.txt", "w");
    if (out == NULL) {
        perror("sorted.txt ochilmadi");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fprintf(out, "%s\n", words[i]);
    }
    fclose(out);

    printf("%d ta so'z saralandi va sorted.txt ga yozildi.\n", n);
    return 0;
}