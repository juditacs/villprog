#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int osszead_szoroz(int a, int b, int* szorzat) {
    (*szorzat) = a*b;
    return a+b;

}

int main(int argc, char* argv[]) {
    if(argc < 3) {
        fprintf(stderr, "Usage: %s <a> <b>\n", argv[0]);
        return -1;
    }
    int a, b;
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    int szorzat = 0;
    int osszeg = osszead_szoroz(a, b, &szorzat);
    printf("osszeg: %d\nszorzat: %d\n", osszeg, szorzat);
    return 0;
}
