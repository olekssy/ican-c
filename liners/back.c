#include <stdio.h>
#include <string.h>

int main(void) {
    char word[20];
    int i, end;
    printf("Enter word: ");
    scanf("%s", word);
    end = strlen(word);
    for (i = end; i > -1; i--) {
        printf("%c", word[i]);
    }
    printf("\n");
    return 0;
}
