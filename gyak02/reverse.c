#include <stdio.h>
#include <stdlib.h>

int Strlen(const char* str) {
    int i;
    for(i=0; str[i] != '\0'; i++);
    return i;
}

void reverse(const char* source, char* target) {
    int i;
    int len = Strlen(source);
    for(i=0; source[i] != '\0'; i++) {
        target[len-i-1] = source[i];
    }
    target[len] = '\0';
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        return -1;
    }
    int len = Strlen(argv[1]);
    char* target = (char*)malloc(sizeof(char)*(len+1));
    reverse(argv[1], target);
    printf("%s\n", target);
    free(target);
    return 0;
}
