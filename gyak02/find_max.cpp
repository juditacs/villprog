#include <cstdio>
#include <cstdlib>
#include <cstring>


int find_max(const int t[], int len, int& pos) {
    pos = 0;
    for(int i=1; i<len; i++) {
        if(t[pos] <= t[i]) pos = i;
    }
    return t[pos];
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <input_list>\n", argv[0]);
        return -1;
    }
    int len = argc-1;
    int* t = (int*)malloc(sizeof(int)*(len));

    for(int i=0; i<len; i++) t[i] = atoi(argv[i+1]);

    int pos;
    int max = find_max(t, len, pos);

    printf("Max: [%d], last occurs at position [%d]\n", max, pos);

    free(t);
}
