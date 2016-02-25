#include <stdio.h>
#include <stdlib.h>


int Strlen(const char* str) {
    int i;
    for(i=0; str[i] != '\0'; i++);
    return i;
}

void reverse(const char* src, char* tgt) {
    int i;
    int l = Strlen(src);
    for(i=0; src[i] != '\0'; i++)
        tgt[l-i-1] = src[i];
    tgt[l] = '\0';
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        return -1;
    }
    int l = Strlen(argv[1]);
    char* revstr = (char*)malloc((l+1)*sizeof(char));
    reverse(argv[1], revstr);
    printf("%s\n", revstr);
    free(revstr);
    return 0;
}
