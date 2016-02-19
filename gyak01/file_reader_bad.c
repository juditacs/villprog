#include <stdio.h>

int main() {
    int i, j = 0;
    char c;

    while(!feof(stdin)) {
        i = fgetc(stdin);
        printf("%d: %02X\n", ++j, i);
        if (i == EOF) {
            printf("EOF reached\n");
        }
    }
    while(scanf("%c", &c) == 1) {
        printf("%d: %02X\n", ++j, c);
    }
    return 0;
}
