#include <stdio.h>

int main() {
    int j = 0;
    char c;

    while(scanf("%c", &c) == 1) {
        printf("%d: %02X\n", ++j, c);
    }
    return 0;
}
