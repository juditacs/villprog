#include <cstdio>
#include <cstdlib>
#include <climits>

int find_max(int l[], int len, int& max_pos) {
    max_pos = 0;
    int i;
    for(i=1; i<len; i++) {
        if(l[max_pos] <= l[i]) max_pos = i;
    }
    return l[max_pos];
}

void find_nmax1(int l[], int len, int N, int* nmax, int* max_pos) {
    int i;
    for(i=0; i<N; i++) {
        nmax[i] = find_max(l, len, max_pos[i]);
        l[max_pos[i]] = INT_MIN;

    }
}

void find_nmax2(int l[], int len, int N, int* nmax, int* max_pos) {
    int* l_cpy = (int*)malloc(sizeof(int)*len);
    int i;
    for(i=0; i<len; i++) l_cpy[i] = l[i];
    find_nmax1(l_cpy, len, N, nmax, max_pos);
    free(l_cpy);
}

int main(int argc, char* argv[]) {
    int* l = (int*)malloc(sizeof(int) * (argc-1));
    int i;
    int list_len = argc-2;
    int N = atoi(argv[1]);
    for(i=0; i<list_len; i++) {
        l[i] = atoi(argv[i+2]);
    }
    int* max_pos = (int*)malloc(sizeof(int)*list_len);
    int* max_elem = (int*)malloc(sizeof(int)*list_len);
    find_nmax2(l, list_len, N, max_elem, max_pos);
    for(i=0; i<N; i++) {
        printf("%d-th largest element: [%d], occurs at position [%d]\n", i+1, max_elem[i], max_pos[i]);
    }

    printf("\nOriginal list:\n");
    for(i=0; i<list_len; i++) {
        printf("%d ", l[i]);
    }
    printf("\n");

    free(l);
    free(max_pos);
    free(max_elem);
}
