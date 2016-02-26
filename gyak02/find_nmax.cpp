#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>


int find_max(const int t[], int len, int& pos) {
    pos = 0;
    for(int i=1; i<len; i++) {
        if(t[pos] <= t[i]) pos = i;
    }
    return t[pos];
}

void find_nmax(int t[], int len, int N, int pos[], int max[]) {
    for(int i=0; i<N; i++) {
        max[i] = find_max(t, len, pos[i]);
        t[pos[i]] = INT_MIN;
    }
}

int main(int argc, char* argv[]) {
    if(argc < 3) {
        fprintf(stderr, "Usage: %s <N> <input_list>\n", argv[0]);
        return -1;
    }
    int N = atoi(argv[1]);
    int len = argc-2;
    int* t = (int*)malloc(sizeof(int)*(len));

    for(int i=0; i<len; i++) t[i] = atoi(argv[i+2]);

    int* pos = (int*)malloc(sizeof(int)*N);
    int* max = (int*)malloc(sizeof(int)*N);
    find_nmax(t, len, N, pos, max);

    for(int i=0; i<N; i++)
        printf("%d-th max: [%d], last occurs at position [%d]\n", i+1, max[i], pos[i]);

    // HF: find_nmax2, ami lemasolja a tombot es nem modositja az eredetit
    free(max);
    free(pos);
    free(t);
}
