#include <stdio.h>
#include <string.h>

int main(void)
{
    char names[50][50];   
    char temp[50];       
    int n;

    printf("Nechta ism kiritasiz? ");
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    getchar();   

    for (int i = 0; i < n; i++) {
        printf("%d-ism: ", i + 1);
        fgets(names[i], 50, stdin);
        names[i][strcspn(names[i], "\n")] = '\0';  
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
    
    printf("\nAlfavit tartibida:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }

    return 0;
}