#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    char* p;
    int len;
} MyString;

void dispose(MyString* s) {
    free(s->p);
}

void printString(MyString* s) {
    printf("%s", s->p);
}


void createFromChar(MyString* s, char c) {
    s->len = 1;
    s->p = (char*)malloc(2*sizeof(char));
    assert(s->p);
    s->p[0] = c;
    s->p[1] = '\0'; // nem = 0
}

void createFromStr(MyString* s, char* p) {
    s->len = strlen(p);
    s->p = (char*)malloc((s->len+1)*sizeof(char));
    assert(s->p);
    strcpy(s->p, p);
}

MyString concatString(MyString* s1, MyString s2) {
    MyString news;
    news.len = s1->len + s2.len;
    news.p = (char*)malloc((news.len+1)*sizeof(char));
    assert(news.p);
    strcpy(news.p, s1->p);
    strcpy(news.p+s1->len, s2.p);
    return news;
}

int main(int argc, char* argv[]) {
    if(argc < 3) {
        fprintf(stderr, "Usage: %s <s1> <s2>\n", argv[0]);
        return -1;
    }
    MyString s1, s2, s3;
    createFromStr(&s1, argv[1]);
    createFromStr(&s2, argv[2]);

    s3 = concatString(&s1, s2);

    printString(&s3);

    // szorgalmi: charAt fuggveny
    // tulindexeles eseten '\0'-t ad vissza, egyebken az i-edik karaktert
    //printf("%d: %c\n", 3, charAt(&s3, 3));

    // HF2: ahol lehet, konstans parameterekre atirni a fuggvenyeket
    // (a main ugyanaz marad)
    printf("\n");
    dispose(&s1);
    dispose(&s2);
    dispose(&s3);

    return 0;
}
