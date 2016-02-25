#include <cstdio>
#include <cstdlib>

double find_max(double l[], int len, int& max_pos) {
    max_pos = 0;
    int i;
    for(i=1; i<len; i++) {
        if(l[max_pos] <= l[i]) max_pos = i;
    }
    return l[max_pos];
}

int main(int argc, char* argv[]) {
    double* l = (double*)malloc(sizeof(double) * (argc-1));
    int i;
    int list_len = argc-1;
    for(i=0; i<list_len; i++) {
        l[i] = atof(argv[i+1]);
    }
    int max_pos;
    double max_elem = find_max(l, list_len, max_pos);
    printf("Maximum element: [%2.2lf] last occurs at position [%d]\n", max_elem, max_pos);
    free(l);
}
